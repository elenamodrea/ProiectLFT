%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include "types.h"
#define YYDEBUG 0
/* prototypes */
nodeType *opr(int oper, int nops, ...);
nodeType *id(int i);
nodeType *con(int value);
nodeType *conFloat(float value);
nodeType *conChar(char* value);
nodeType *conArray(int* value);
type_ ex(nodeType *p);
void freeNode(nodeType *p);
void yyerror(char *s);
int lengthArray(int* array);
void sortArray(int a[100]);
int search(int a[100], int value);
void insertFirst(int a[100], int value);
void insertLast(int a[100], int value);
int delete(int a[100], int value);
char* deleteAll(char* string, char* substring);

 int isym[26];
 float fsym[26];
 char csym[26][100];   
 int vectori[26][100];
 int types[26]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}; //0-int, 1-float, 2-char* 3-array

%}

%union {
  int iValue;      /* integer value */
  float floatValue;
  char* charValue;
  char sIndex;     /* symbol table index */
  int* aValue;
  nodeType *nPtr;  /* node pointer */
};

%token <iValue> INTEGER 
%token <iValue> VARIABLE
%token <floatValue> FLOAT
%token <charValue>  CHAR
%token <aValue> ARRAYV
%token WHILE IF PRINT INTT FLOATT CHART DO FOR BREAK SWITCH CASE DEFAULT ARRAY SORT SEARCH DELETE INSERTFIRST INSERTLAST LENGTH MAX MIN APPEND DELETEALL LOWER UPPER COPY COMPARE CONTAINS
%nonassoc IFX
%nonassoc ELSE

%left GE LE EQ NE '>' '<'
%left '+' '-'
%left '*' '/'
%nonassoc UMINUS

%type <nPtr> statement expr stmt_list assignment_stmt case_statements case_statement case_expr default_stmt char_expr array_exp

%start      program

%%

program   : function '.'          { exit(0); }
          ;

function  : function statement    { ex($2);freeNode($2); }
          | /* NULL */
          ;

/*array_  : '{' array '}'


array: array INTEGER
      | 
      ;
 */
statement : ';'                   { $$ = opr(';', 2, NULL, NULL); }
          | expr ';'              { $$ = $1; }
          | PRINT expr ';'        { $$ = opr(PRINT, 1, $2); }
          | VARIABLE '=' expr ';' { $$ = opr('=', 2, id($1), $3); }
          | INTT VARIABLE ';'     { $$ = opr(INTT, 1,id($2));}
          | FLOATT VARIABLE ';'   { $$ = opr(FLOATT, 1,id($2));}
          | ARRAY VARIABLE ';'    { $$ = opr(ARRAY, 1, id($2));}
          | CHART VARIABLE ';'    { $$ = opr(CHART, 1, id($2));}
          | SORT '(' VARIABLE ')' ';' {$$ = opr(SORT, 1, id($3));} 
          | MAX '(' VARIABLE ')' ';' {$$ = opr(MAX, 1, id($3));}
          | MIN '(' VARIABLE ')' ';' {$$ = opr(MIN, 1, id($3));}
          | LENGTH '(' VARIABLE ')' ';' {$$ = opr(LENGTH, 1, id($3));}
          | SEARCH '(' VARIABLE ',' array_exp ')' ';' {$$ = opr(SEARCH, 2, id($3),$5);}
          | INSERTFIRST '(' VARIABLE ',' array_exp ')' ';' {$$ = opr(INSERTFIRST, 2, id($3),$5);}
          | INSERTLAST '(' VARIABLE ',' array_exp ')' ';' {$$ = opr(INSERTLAST, 2, id($3),$5);}
          | DELETE '(' VARIABLE ',' array_exp ')' ';' {$$ = opr(DELETE, 2, id($3),$5);}
          | COPY '(' VARIABLE ',' char_expr ')' ';' {$$ = opr(COPY, 2, id($3),$5);}
          | COMPARE '(' char_expr ',' char_expr ')' ';' {$$ = opr(COMPARE, 2, $3,$5);}
          | CONTAINS '(' VARIABLE ',' char_expr ')' ';' {$$ = opr(CONTAINS, 2, id($3),$5);}
          | LOWER '(' VARIABLE ')' ';' {$$ = opr(LOWER, 1, id($3));}
          | UPPER '(' VARIABLE ')' ';' {$$ = opr(UPPER, 1, id($3));}
          | DELETEALL '(' VARIABLE ',' char_expr ')' ';' {$$ = opr(DELETEALL, 2, id($3),$5);}
          | APPEND '(' VARIABLE ',' char_expr ')' ';' {$$ = opr(APPEND, 2, id($3),$5);}
          | WHILE '(' expr ')' statement
                 { $$ = opr(WHILE, 2, $3, $5); }
          | DO statement WHILE '(' expr ')' ';'
                 {$$ = opr(DO, 2, $2, $5);}
          | FOR  '(' assignment_stmt ';' expr ';' assignment_stmt ')' statement
                 {$$ = opr(FOR, 4, $3, $5, $7, $9);}
          | SWITCH  '(' VARIABLE ')' '{' case_statements default_stmt '}'
                 { $$ = opr(SWITCH, 3, id($3), $6, $7);
                  }               
          | IF '(' expr ')' statement %prec IFX
                 { $$ = opr(IF, 2, $3, $5); }
          | IF '(' expr ')' statement ELSE statement
                 { $$ = opr(IF, 3, $3, $5, $7); }
          | '{' stmt_list '}' { $$ = $2; }
          ;

stmt_list : statement
          | stmt_list statement   { $$ = opr(';', 2, $1, $2); }
          ;
case_statements : case_statement
                | case_statements case_statement  { $$ = opr(';', 2, $1, $2); }
                ;

case_statement : CASE case_expr ':' stmt_list BREAK ';'  {$$= opr(CASE,2,$2,$4);}

default_stmt : DEFAULT ':' stmt_list BREAK ';' {$$=opr(DEFAULT,1,$3);}
               ;          
assignment_stmt : VARIABLE '=' expr { $$ = opr('=', 2, id($1), $3); }
                |
                ;
case_expr : FLOAT                 { $$ = conFloat($1);}
          | INTEGER               { $$ = con($1); }
          | CHAR                  { $$ = conChar($1);}
char_expr : CHAR                  { $$ = conChar($1);}
          | VARIABLE              { $$ = id($1); }   
array_exp : INTEGER               { $$ = con($1); }
          | VARIABLE              { $$ = id($1); } 

expr      : FLOAT                 { $$ = conFloat($1);}
          | INTEGER               { $$ = con($1); }
          | CHAR                  { $$ = conChar($1);}
          | ARRAYV                { $$ = conArray($1);}
          | VARIABLE              { $$ = id($1); }
          | '-' expr %prec UMINUS { $$ = opr(UMINUS, 1, $2); }
          | expr '+' expr         { $$ = opr('+', 2, $1, $3); }
          | expr '-' expr         { $$ = opr('-', 2, $1, $3); }
          | expr '*' expr         { $$ = opr('*', 2, $1, $3); }
          | expr '/' expr         { $$ = opr('/', 2, $1, $3); }
          | expr '<' expr         { $$ = opr('<', 2, $1, $3); }
          | expr '>' expr         { $$ = opr('>', 2, $1, $3); }
          | expr GE expr          { $$ = opr(GE, 2, $1, $3); }
          | expr LE expr          { $$ = opr(LE, 2, $1, $3); }
          | expr NE expr          { $$ = opr(NE, 2, $1, $3); }
          | expr EQ expr          { $$ = opr(EQ, 2, $1, $3); }
          | '(' expr ')'          { $$ = $2; }
          ;

%%

nodeType *con(int value) 
{ 
  nodeType *p; 
  
  /* allocate node */ 
  if ((p = malloc(sizeof(conNodeType))) == NULL) 
    yyerror("out of memory"); 
  /* copy information */ 
  p->type = typeCon; 
  p->con.value = value; 
  return p; 
} 
nodeType *conFloat(float value) 
{ 
  nodeType *p; 
  
  /* allocate node */ 
  if ((p = malloc(sizeof(conNodeType))) == NULL) 
    yyerror("out of memory"); 
  /* copy information */ 
  p->type = typeConFloat; 
  p->con.floatValue = value; 
  return p; 
} 
nodeType *conChar(char* value) 
{ 
  nodeType *p; 
  
  /* allocate node */ 
  if ((p = malloc(sizeof(conNodeType))) == NULL) 
    yyerror("out of memory"); 
  /* copy information */ 
  p->type = typeConChar; 
  p->con.charValue=calloc(100,sizeof(char));
  p->con.charValue=value;
  return p; 
} 
nodeType *conArray(int* value) 
{ 
  nodeType *p; 
  
  /* allocate node */ 
  if ((p = malloc(sizeof(conNodeType))) == NULL) 
    yyerror("out of memory"); 
  /* copy information */ 
  p->type = typeConArray; 
  p->con.aValue=calloc(100,sizeof(int));
  p->con.aValue = value; 
  return p; 
} 
nodeType *id(int i) 
{ 
  nodeType *p; 
  /* allocate node */ 
  if ((p = malloc(sizeof(idNodeType))) == NULL) 
    yyerror("out of memory"); 
  /* copy information */ 
  p->type = typeId; 
  p->id.i = i; 
  return p; 
} 

nodeType *opr(int oper, int nops, ...) 
{ 
  va_list ap; 
  nodeType *p; 
  size_t size; 
  int i; 

  /* allocate node */ 
  size = sizeof(oprNodeType) + (nops - 1) * sizeof(nodeType*); 
  if ((p = malloc(size)) == NULL) 
    yyerror("out of memory"); 
  /* copy information */
  p->type = typeOpr; 
  p->opr.oper = oper; 
  p->opr.nops = nops; 
  va_start(ap, nops); 
  for (i = 0; i < nops; i++) 
    p->opr.op[i] = va_arg(ap, nodeType*); 
  va_end(ap); 
  
  return p; 
}

void freeNode(nodeType *p) 
{ 
  int i; 

  if (!p) 
    return; 
  if (p->type == typeOpr) { 
    for (i = 0; i < p->opr.nops; i++) 
      freeNode(p->opr.op[i]); 
  } 
  free (p); 
} 

type_ ex(nodeType *p) 
{ 
  type_ type;
  type.iVal=999999;
  type.fVal=999999.0;
  type.cVal="";
  type_ op1;
  type_ op2;
  type_ op3;
  
  if (!p) 
    return type; 

  switch(p->type) 
    { 
    case typeCon: { 
      type.iVal=p->con.value; 
      return type;}
    case typeConChar:{ 
       type.cVal=p->con.charValue;
       return type;}
    case typeConFloat:{
       type.fVal=p->con.floatValue;
       return type;}
    case typeConArray:{
       type.aVal=p->con.aValue;
       return type;
    } 
    case typeId: if(types[p->id.i]==0){
                    type.iVal=isym[p->id.i];
                   }
                   else if(types[p->id.i]==1){
                    type.fVal=fsym[p->id.i];
                   } 
                   else if(types[p->id.i]==2){
                    type.cVal=csym[p->id.i];
                   }
                   else if(types[p->id.i]==3){
                    type.aVal=vectori[p->id.i];
                    
                   }
                   else {
                    yyerror("variabila nu este declarata");
                   }
                   return type;
     
    case typeOpr: switch(p->opr.oper) 
                    { 
		    case WHILE: while(ex(p->opr.op[0]).iVal) 
		                   ex(p->opr.op[1]); 
		                return type; 
        case DO: do {
                  ex(p->opr.op[0]); 
                   }while(ex(p->opr.op[1]).iVal);
                   return type;
        case FOR: for(ex(p->opr.op[0]); ex(p->opr.op[1]).iVal;ex(p->opr.op[2]))
                     ex(p->opr.op[3]);
                  return type;                        
		    case IF: if (ex(p->opr.op[0]).iVal) 
		                ex(p->opr.op[1]); 
		             else if (p->opr.nops > 2) 
			             ex(p->opr.op[2]); 
		             return type;
        case SWITCH:  int ok=0;
                      for(int i=0 ; i<p->opr.op[1]->opr.nops;i++){
                        if(ex(p->opr.op[0]).iVal!=999999){
                         if(ex(p->opr.op[0]).iVal==ex(p->opr.op[1]->opr.op[i]->opr.op[0]).iVal){
                           ex(p->opr.op[1]->opr.op[i]->opr.op[1]);
                           ok=1;
                         }}
                         else if(ex(p->opr.op[0]).fVal!=999999.0) {
                                if(ex(p->opr.op[0]).fVal==ex(p->opr.op[1]->opr.op[i]->opr.op[0]).fVal){
                                   ex(p->opr.op[1]->opr.op[i]->opr.op[1]);
                                   ok=1;
                         }
                         }
                         else {
                          if(strcmp(ex(p->opr.op[0]).cVal,ex(p->opr.op[1]->opr.op[i]->opr.op[0]).cVal)==0){
                                   ex(p->opr.op[1]->opr.op[i]->opr.op[1]);
                                   ok=1;
                         }
                      }  
                    } 
                    if(ok==0){
                      ex(p->opr.op[2]->opr.op[0]);
                    }    
                      return type;
        case INTT: if(types[p->opr.op[0]->id.i]==-1){
                   types[p->opr.op[0]->id.i]=0; }
                    else {
                      yyerror("variabila este deja initializata");
                     }
                  
                   return type;
        case FLOATT: if(types[p->opr.op[0]->id.i]==-1){ 
                    types[p->opr.op[0]->id.i]=1;
                     }
                     else {
                      yyerror("variabila este deja initializata");
                     }
                    
                    return type;    
        case CHART: if(types[p->opr.op[0]->id.i]==-1){
                    types[p->opr.op[0]->id.i]=2;}
                     else {
                      yyerror("variabila este deja initializata");
                     }
                    return type;    
        case ARRAY: if(types[p->opr.op[0]->id.i]==-1){
                    types[p->opr.op[0]->id.i]=3;
                    }
                     else {
                      yyerror("variabila este deja initializata");
                     }
                    return type;   
        case SORT:    if(types[p->opr.op[0]->id.i]==3){
                       sortArray(ex(p->opr.op[0]).aVal);
                      }
                      else {
                        yyerror("nu se poate face sort decat pe array");
                      } 
                      return type; 
        case MIN:    if(types[p->opr.op[0]->id.i]==3){
                       int *a= ex(p->opr.op[0]).aVal;
                       int n=lengthArray(a);
                       int mn=999999;
                       for(int i=0;i<n;i++){
                        if(a[i]<mn){
                          mn=a[i];
                        }
                       }
                       printf("minimul este: %d\n", mn);
                      }
                      else {
                        yyerror("nu se poate face minim decat pe array");
                      } 
                      return type;   
        case MAX:    if(types[p->opr.op[0]->id.i]==3){
                       int *a= ex(p->opr.op[0]).aVal;
                       int m=lengthArray(a);
                       int mx=-999999;
                       for(int i=0;i<m;i++){
                        if(a[i]>mx){
                          mx=a[i];
                        }
                       }
                       printf("maximul este: %d\n", mx);
                      }
                      else {
                        yyerror("nu se poate face maxim decat pe array");
                      } 
                      return type;                           
        case SEARCH:  if(types[p->opr.op[0]->id.i]==3){
                         int x=search(ex(p->opr.op[0]).aVal,ex(p->opr.op[1]).iVal);
                         if(x==-1){
                          printf("elementul nu a fost gasit\n");
                          }
                          else{
                            printf("indexul unde se afla elementul cautat este: %d \n", x);
                          }
                      }
                      else {
                        yyerror("nu se poate face search decat pe array");
                      } 
                      return type;    
        case INSERTFIRST : if(types[p->opr.op[0]->id.i]==3){
                       insertFirst(ex(p->opr.op[0]).aVal,ex(p->opr.op[1]).iVal);
                      }
                      else {
                        yyerror("nu se poate face insert decat pe array");
                      } 
                      return type;  
        case INSERTLAST : if(types[p->opr.op[0]->id.i]==3){
                       insertLast(ex(p->opr.op[0]).aVal,ex(p->opr.op[1]).iVal);
                      }
                      else {
                        yyerror("nu se poate face insert decat pe array");
                      } 
                      return type;   
        case DELETE:  if(types[p->opr.op[0]->id.i]==3){
                         int x=delete(ex(p->opr.op[0]).aVal,ex(p->opr.op[1]).iVal);
                         if(x==-1){
                          printf("elementul nu a fost gasit\n");
                          }
                      }
                      else {
                        yyerror("nu se poate face delete decat pe array");
                      } 
                      return type; 
        case LENGTH:  if(types[p->opr.op[0]->id.i]==3){
                       int l= lengthArray(ex(p->opr.op[0]).aVal);
                       printf("lungimea array-ului este: %d\n", l);
                      }
                      else {
                        yyerror("nu se poate face length decat pe array");
                      } 
                      return type;                                                        
		    case PRINT:  op3=ex(p->opr.op[0]); 
                     if(op3.iVal!=999999){
                       printf("%d\n", ex(p->opr.op[0]).iVal); 
                       return type;
                     }
                     else if(op3.fVal!=999999.0){
                      printf("%f\n", ex(p->opr.op[0]).fVal);
                      return type; 
                     }
                     else if(op3.aVal!=NULL){
                      op1=ex(p->opr.op[0]);
                      int k= lengthArray(op1.aVal);
                      for(int i=0;i<k-1;i++){
                        printf("%d, ",op1.aVal[i]);
                        
                      }
                      if(k!=0){
                      printf("%d\n", op1.aVal[k-1]);
                      }
                      else{
                        printf("{}\n");
                      }
                     }
                     else{
                      printf("%s\n", ex(p->opr.op[0]).cVal); 
                      return type;
                     }
		                return type; 
        case COPY:  if(types[p->opr.op[0]->id.i]==2){
                       strcpy(csym[p->opr.op[0]->id.i],ex(p->opr.op[1]).cVal);
                      }
                      else {
                        yyerror("nu se poate face copy decat pe stringuri");
                      } 
                      return type;
        case COMPARE:  if(types[p->opr.op[0]->id.i]==2){
                       int comp=strcmp(ex(p->opr.op[0]).cVal,ex(p->opr.op[1]).cVal);
                       if(comp==0){
                        printf("sirurile sunt egale\n");
                       }
                       else if(comp<0){
                        printf("primul sir este mai mic decat al doilea\n");
                       }
                       else {
                        printf("primul sir este mai mare decat al doilea\n");
                       }
                      }
                      else {
                        yyerror("nu se poate face compare decat pe stringuri");
                      } 
                      return type;
        case CONTAINS:  if(types[p->opr.op[0]->id.i]==2){
                       char* str=strstr(ex(p->opr.op[0]).cVal,ex(p->opr.op[1]).cVal);
                       if(str!=NULL){
                        printf("al doilea sir a fost gasit in primul\n");
                       }
                       else {
                        printf("al doilea sir nu a fost gasit in primul\n");
                       }
                      }
                      else {
                        yyerror("nu se poate face compare decat pe stringuri");
                      } 
                      return type;
        case LOWER:  if(types[p->opr.op[0]->id.i]==2){
                      
                      op1=ex(p->opr.op[0]);
                      char* s=calloc(100,sizeof(char));
                      strcpy(s,op1.cVal);
                      int c=strlen(op1.cVal);
                       for(int i = 0; i<c; i++){
                          s[i] = tolower(s[i]);
                        }
                        strcpy(csym[p->opr.op[0]->id.i],s); 
                      }else {
                        yyerror("nu se poate face lower decat pe stringuri");
                      } 
                      return type;
        case UPPER:  if(types[p->opr.op[0]->id.i]==2){
                      op1=ex(p->opr.op[0]);
                      char* s=calloc(100,sizeof(char));
                      strcpy(s,op1.cVal);
                      
                      int c=strlen(op1.cVal);
                       for(int i = 0; i<c; i++){
                          s[i] = toupper(s[i]);
                        }
                        strcpy(csym[p->opr.op[0]->id.i],s); 
                      }else {
                        yyerror("nu se poate face upper decat pe stringuri");
                      } 
                      return type;
        case APPEND:  if(types[p->opr.op[0]->id.i]==2){
                      strcat(csym[p->opr.op[0]->id.i],ex(p->opr.op[1]).cVal); 
                      }else {
                        yyerror("nu se poate face append decat pe stringuri");
                      } 
                      return type;
        case DELETEALL:  if(types[p->opr.op[0]->id.i]==2){
                      char* delete=deleteAll(ex(p->opr.op[0]).cVal,ex(p->opr.op[1]).cVal);
                      if(delete!=NULL){
                         strcpy(csym[p->opr.op[0]->id.i],delete);
                      }
                      }else {
                        yyerror("nu se poate face deleteAll decat pe stringuri");
                      } 
                      return type;                                                                                     
		    case ';': ex(p->opr.op[0]); 
		              return ex(p->opr.op[1]); 
		    case '=': 
         if(types[p->opr.op[0]->id.i]==0){
          isym[p->opr.op[0]->id.i] = ex(p->opr.op[1]).iVal;
         }
         else if(types[p->opr.op[0]->id.i]==1){
             fsym[p->opr.op[0]->id.i] = ex(p->opr.op[1]).fVal;
         }
         else if(types[p->opr.op[0]->id.i]==2){
           strcpy(csym[p->opr.op[0]->id.i],ex(p->opr.op[1]).cVal);
         }
         else if(types[p->opr.op[0]->id.i]==3){
          op1=ex(p->opr.op[1]);
          int length = lengthArray(op1.aVal);
          for(int i=0;i<length;i++){
           vectori[p->opr.op[0]->id.i][i]=op1.aVal[i];
          }
         }
         else{
          yyerror("variabila nu este declarata");
         }
         
          return type;
        
		    case '+':    op1=ex(p->opr.op[0]);
                     op2=ex(p->opr.op[1]);
                    if((op1.iVal==999999)&&(op2.iVal==999999)){
                      type.fVal=ex(p->opr.op[0]).fVal + ex(p->opr.op[1]).fVal;
                    }
                    else if((op1.fVal==999999.0)&&(op2.fVal==999999.0)){
                      type.iVal=ex(p->opr.op[0]).iVal + ex(p->opr.op[1]).iVal;
                    } 
                    else yyerror("operanzii nu sunt de acelasi tip");
                    
                   return type;
                  
		    case '-':    op1=ex(p->opr.op[0]);
                     op2=ex(p->opr.op[1]);
                     if((op1.iVal==999999)&&(op2.iVal==999999)){
                      type.fVal=ex(p->opr.op[0]).fVal - ex(p->opr.op[1]).fVal;
                    }
                    else if((op1.fVal==999999.0)&&(op2.fVal==999999.0)){
                       
                      type.iVal=ex(p->opr.op[0]).iVal - ex(p->opr.op[1]).iVal;
                    } 
                    else yyerror("operanzii nu sunt de acelasi tip");
                    
                   return type;
                  
		    case '*':    op1=ex(p->opr.op[0]);
                     op2=ex(p->opr.op[1]);
                    if((op1.iVal==999999)&&(op2.iVal==999999)){
                      type.fVal=ex(p->opr.op[0]).fVal * ex(p->opr.op[1]).fVal;
                    }
                    else if((op1.fVal==999999.0)&&(op2.fVal==999999.0)){
                      type.iVal=ex(p->opr.op[0]).iVal * ex(p->opr.op[1]).iVal;
                    } 
                    else yyerror("operanzii nu sunt de acelasi tip");
                    
                   return type;
                  
		    case '/':   op1=ex(p->opr.op[0]);
                    op2=ex(p->opr.op[1]);
                    if((op1.iVal==999999)&&(op2.iVal==999999)){
                      type.fVal=ex(p->opr.op[0]).fVal / ex(p->opr.op[1]).fVal;
                    }
                    else if((op1.fVal==999999.0)&&(op2.fVal==999999.0)){
                      type.iVal=ex(p->opr.op[0]).iVal / ex(p->opr.op[1]).iVal;
                    } 
                    else yyerror("operanzii nu sunt de acelasi tip");
                    
                   return type;
                  
		    case '<':    op1=ex(p->opr.op[0]);
                     op2=ex(p->opr.op[1]);
                    if((op1.iVal==999999)&&(op2.iVal==999999)){
                      type.iVal=ex(p->opr.op[0]).fVal < ex(p->opr.op[1]).fVal;
                    }
                    else if((op1.fVal==999999.0)&&(op2.fVal==999999.0)){
                      type.iVal=ex(p->opr.op[0]).iVal < ex(p->opr.op[1]).iVal;
                    }
                    else yyerror("operanzii nu sunt de acelasi tip");
                    
                   return type;
                  
		    case '>':    op1=ex(p->opr.op[0]);
                     op2=ex(p->opr.op[1]);
                    if((op1.iVal==999999)&&(op2.iVal==999999)){
                      type.iVal=ex(p->opr.op[0]).fVal > ex(p->opr.op[1]).fVal;
                    }
                    else if((op1.fVal==999999.0)&&(op2.fVal==999999.0)){
                      type.iVal=ex(p->opr.op[0]).iVal > ex(p->opr.op[1]).iVal;
                    } 
                    else yyerror("operanzii nu sunt de acelasi tip");
                    
                   return type;
                  
		    case GE:     op1=ex(p->opr.op[0]);
                     op2=ex(p->opr.op[1]);
                    if((op1.iVal==999999)&&(op2.iVal==999999)){
                      type.iVal=ex(p->opr.op[0]).fVal >= ex(p->opr.op[1]).fVal;
                    }
                    else if((op1.fVal==999999.0)&&(op2.fVal==999999.0)){
                      type.iVal=ex(p->opr.op[0]).iVal >= ex(p->opr.op[1]).iVal;
                    } 
                    else yyerror("operanzii nu sunt de acelasi tip");
                    
                   return type;
                  
		    case LE:     op1=ex(p->opr.op[0]);
                     op2=ex(p->opr.op[1]);
                    if((op1.iVal==999999)&&(op2.iVal==999999)){
                      type.iVal=ex(p->opr.op[0]).fVal <= ex(p->opr.op[1]).fVal;
                    }
                    else if((op1.fVal==999999.0)&&(op2.fVal==999999.0)){
                      type.iVal=ex(p->opr.op[0]).iVal <= ex(p->opr.op[1]).iVal;
                    } 
                    else yyerror("operanzii nu sunt de acelasi tip");
                    
                   return type;
                  
		    case NE:    op1=ex(p->opr.op[0]);
                    op2=ex(p->opr.op[1]);
                    if((op1.iVal==999999)&&(op2.iVal==999999)){
                      type.iVal=ex(p->opr.op[0]).fVal != ex(p->opr.op[1]).fVal;
                    }
                    else if((op1.fVal==999999.0)&&(op2.fVal==999999.0)){
                      type.iVal=ex(p->opr.op[0]).iVal != ex(p->opr.op[1]).iVal;
                    } 
                    else yyerror("operanzii nu sunt de acelasi tip");
                    
                   return type;
                   
		    case EQ:    op1=ex(p->opr.op[0]);
                    op2=ex(p->opr.op[1]);
                    if((op1.iVal==999999)&&(op2.iVal==999999)){
                      type.iVal=ex(p->opr.op[0]).fVal == ex(p->opr.op[1]).fVal;
                    }
                    else if((op1.fVal==999999.0)&&(op2.fVal==999999.0)){
                      type.iVal=ex(p->opr.op[0]).iVal == ex(p->opr.op[1]).iVal;
                    } 
                    else yyerror("operanzii nu sunt de acelasi tip");
                    
                   return type;
                  
		    } 
    } 

}
int lengthArray(int* array){
  int i=0;
  while(array[i]!=0){
    i++;
  }
  return i;
}
void sortArray(int a[100]){
  int n=lengthArray(a);
  int aux;
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
       if(a[i]>a[j]){
        aux=a[i];
        a[i]=a[j];
        a[j]=aux;
        }
    }
  }
}
int search(int a[100], int value){
  int k=-1;
  int n=lengthArray(a);
  for(int i=0;i<n;i++){
    if(a[i]==value){
      return i;
    }
  }
  return k;
}
void insertFirst(int arr[100], int element) {
   int size=lengthArray(arr);

    for (int i =size; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

    arr[0] = element;
}
void insertLast(int arr[100], int element) {
   int size=lengthArray(arr);

    arr[size] = element;
}
int delete(int arr[100], int element){
  int index=search(arr,element);
  if (index==-1){
    return -1;
  }
  int size=lengthArray(arr);

    // Shift elements to the left
    for (int i = index; i < (size - 1); i++) {
        arr[i] = arr[i + 1];
    }
    arr[size-1]=0;
    return index;
}
char* deleteAll(char* string, char*substring){
   int len = strlen(substring);
    while ((string = strstr(string, substring)) != NULL) {
        memmove(string, string + len, strlen(string + len) + 1);
    }
  return string;
}
void yyerror(char *s) 
{ 
  fprintf(stdout, "%s\n", s); 
} 

int main(void) 
{
#if YYDEBUG
  yydebug = 1;
#endif
  yyparse();
  return 0; 
}
