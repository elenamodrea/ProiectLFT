/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INTEGER = 258,                 /* INTEGER  */
    VARIABLE = 259,                /* VARIABLE  */
    FLOAT = 260,                   /* FLOAT  */
    CHAR = 261,                    /* CHAR  */
    ARRAYV = 262,                  /* ARRAYV  */
    WHILE = 263,                   /* WHILE  */
    IF = 264,                      /* IF  */
    PRINT = 265,                   /* PRINT  */
    INTT = 266,                    /* INTT  */
    FLOATT = 267,                  /* FLOATT  */
    CHART = 268,                   /* CHART  */
    DO = 269,                      /* DO  */
    FOR = 270,                     /* FOR  */
    BREAK = 271,                   /* BREAK  */
    SWITCH = 272,                  /* SWITCH  */
    CASE = 273,                    /* CASE  */
    DEFAULT = 274,                 /* DEFAULT  */
    ARRAY = 275,                   /* ARRAY  */
    SORT = 276,                    /* SORT  */
    SEARCH = 277,                  /* SEARCH  */
    DELETE = 278,                  /* DELETE  */
    INSERTFIRST = 279,             /* INSERTFIRST  */
    INSERTLAST = 280,              /* INSERTLAST  */
    LENGTH = 281,                  /* LENGTH  */
    MAX = 282,                     /* MAX  */
    MIN = 283,                     /* MIN  */
    APPEND = 284,                  /* APPEND  */
    DELETEALL = 285,               /* DELETEALL  */
    LOWER = 286,                   /* LOWER  */
    UPPER = 287,                   /* UPPER  */
    COPY = 288,                    /* COPY  */
    COMPARE = 289,                 /* COMPARE  */
    CONTAINS = 290,                /* CONTAINS  */
    IFX = 291,                     /* IFX  */
    ELSE = 292,                    /* ELSE  */
    GE = 293,                      /* GE  */
    LE = 294,                      /* LE  */
    EQ = 295,                      /* EQ  */
    NE = 296,                      /* NE  */
    UMINUS = 297                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define INTEGER 258
#define VARIABLE 259
#define FLOAT 260
#define CHAR 261
#define ARRAYV 262
#define WHILE 263
#define IF 264
#define PRINT 265
#define INTT 266
#define FLOATT 267
#define CHART 268
#define DO 269
#define FOR 270
#define BREAK 271
#define SWITCH 272
#define CASE 273
#define DEFAULT 274
#define ARRAY 275
#define SORT 276
#define SEARCH 277
#define DELETE 278
#define INSERTFIRST 279
#define INSERTLAST 280
#define LENGTH 281
#define MAX 282
#define MIN 283
#define APPEND 284
#define DELETEALL 285
#define LOWER 286
#define UPPER 287
#define COPY 288
#define COMPARE 289
#define CONTAINS 290
#define IFX 291
#define ELSE 292
#define GE 293
#define LE 294
#define EQ 295
#define NE 296
#define UMINUS 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 35 "interpreter.y"

  int iValue;      /* integer value */
  float floatValue;
  char* charValue;
  char sIndex;     /* symbol table index */
  int* aValue;
  nodeType *nPtr;  /* node pointer */

#line 160 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
