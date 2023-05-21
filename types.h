typedef enum { typeCon, typeConFloat, typeConChar,typeConArray, typeId, typeOpr } nodeEnum;

/* constants */
typedef struct {
  nodeEnum type; /* type of node */
  int value; /* value of constant */
  float floatValue;
  char* charValue;
  int* aValue;
} conNodeType;

/* identifiers */
typedef struct {
  nodeEnum type; /* type of node */
  int i; /* subscript to ident array */
} idNodeType;

/* operators */
typedef struct {
  nodeEnum type; /* type of node */
  int oper; /* operator */
  int nops; /* number of operands */
  union nodeTypeTag *op[1]; /* operands (expandable) */
} oprNodeType;
typedef struct{
  int iVal;
  float fVal;
  char* cVal;
  int*  aVal;
}type_;


typedef union nodeTypeTag {
  nodeEnum type; /* type of node */
  conNodeType con; /* constants */
  idNodeType id; /* identifiers */
  oprNodeType opr; /* operators */
} nodeType;



