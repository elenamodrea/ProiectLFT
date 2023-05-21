%{
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "y.tab.h"
%}

%%
 
  /* variables */
[a-z]           {
                   yylval.iValue = *yytext - 'a';
                   return VARIABLE;
                }

  /* integers */                 

-?[0-9]+\.[0-9]+  {
                  yylval.floatValue = atof(yytext);
                   return FLOAT; 
                }
[\{]([0-9]+[\,]?)+[\}] {
                       char*s= yytext+1;
                       s[strlen(s)-1]='\0';
                       char*p=strtok(s,",");
                       int* rez=calloc(100,sizeof(int));
                       int k=0;
                       while(p){
                        rez[k]=atoi(p);
                        k++;
                        p=strtok(NULL,",");
                       }
                       yylval.aValue = calloc(100, sizeof(int));
                       yylval.aValue = rez;
                       return ARRAYV;
                       }                
-?[0-9]+          {
                   yylval.iValue = atoi(yytext);
                   return INTEGER;
                }                
[\"][a-zA-Z0-9 ,]+[\"] { char*s= yytext+1;
                       s[strlen(s)-1]='\0';
                       yylval.charValue = calloc(100, sizeof(char));
                       yylval.charValue = s;
                       return CHAR; 
                     }                               

  /* operators */
[-()<>=+/*;{}.:,] return *yytext;

">="            return GE;
"<="            return LE;
"=="            return EQ;
"!="            return NE;
"while"         return WHILE;
"if"            return IF;
"else"          return ELSE;
"print"         return PRINT;
"int"           return INTT;
"char*"         return CHART;
"float"         return FLOATT;
"do"            return DO;
"for"           return FOR;
"break"         return BREAK;
"switch"        return SWITCH;
"case"          return CASE;
"default"       return DEFAULT;
"array"         return ARRAY;
"sort"          return SORT;
"search"        return SEARCH;
"insertFirst"   return INSERTFIRST;
"insertLast"    return INSERTLAST;
"delete"        return DELETE;
"length"        return LENGTH;
"max"           return MAX;
"min"           return MIN;
"compare"       return COMPARE;
"copy"          return COPY;
"contains"      return CONTAINS;
"toLower"       return LOWER;
"toUpper"       return UPPER;
"deleteAll"     return DELETEALL;
"append"        return APPEND;

[ \t\n]+        ;      // Skip whitespaces.

.               yyerror("Unknown character.\n");

%%

int yywrap(void)
{
    return 1;
}
