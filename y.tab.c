/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "interpreter.y"

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


#line 105 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 251 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INTEGER = 3,                    /* INTEGER  */
  YYSYMBOL_VARIABLE = 4,                   /* VARIABLE  */
  YYSYMBOL_FLOAT = 5,                      /* FLOAT  */
  YYSYMBOL_CHAR = 6,                       /* CHAR  */
  YYSYMBOL_ARRAYV = 7,                     /* ARRAYV  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_IF = 9,                         /* IF  */
  YYSYMBOL_PRINT = 10,                     /* PRINT  */
  YYSYMBOL_INTT = 11,                      /* INTT  */
  YYSYMBOL_FLOATT = 12,                    /* FLOATT  */
  YYSYMBOL_CHART = 13,                     /* CHART  */
  YYSYMBOL_DO = 14,                        /* DO  */
  YYSYMBOL_FOR = 15,                       /* FOR  */
  YYSYMBOL_BREAK = 16,                     /* BREAK  */
  YYSYMBOL_SWITCH = 17,                    /* SWITCH  */
  YYSYMBOL_CASE = 18,                      /* CASE  */
  YYSYMBOL_DEFAULT = 19,                   /* DEFAULT  */
  YYSYMBOL_ARRAY = 20,                     /* ARRAY  */
  YYSYMBOL_SORT = 21,                      /* SORT  */
  YYSYMBOL_SEARCH = 22,                    /* SEARCH  */
  YYSYMBOL_DELETE = 23,                    /* DELETE  */
  YYSYMBOL_INSERTFIRST = 24,               /* INSERTFIRST  */
  YYSYMBOL_INSERTLAST = 25,                /* INSERTLAST  */
  YYSYMBOL_LENGTH = 26,                    /* LENGTH  */
  YYSYMBOL_MAX = 27,                       /* MAX  */
  YYSYMBOL_MIN = 28,                       /* MIN  */
  YYSYMBOL_APPEND = 29,                    /* APPEND  */
  YYSYMBOL_DELETEALL = 30,                 /* DELETEALL  */
  YYSYMBOL_LOWER = 31,                     /* LOWER  */
  YYSYMBOL_UPPER = 32,                     /* UPPER  */
  YYSYMBOL_COPY = 33,                      /* COPY  */
  YYSYMBOL_COMPARE = 34,                   /* COMPARE  */
  YYSYMBOL_CONTAINS = 35,                  /* CONTAINS  */
  YYSYMBOL_IFX = 36,                       /* IFX  */
  YYSYMBOL_ELSE = 37,                      /* ELSE  */
  YYSYMBOL_GE = 38,                        /* GE  */
  YYSYMBOL_LE = 39,                        /* LE  */
  YYSYMBOL_EQ = 40,                        /* EQ  */
  YYSYMBOL_NE = 41,                        /* NE  */
  YYSYMBOL_42_ = 42,                       /* '>'  */
  YYSYMBOL_43_ = 43,                       /* '<'  */
  YYSYMBOL_44_ = 44,                       /* '+'  */
  YYSYMBOL_45_ = 45,                       /* '-'  */
  YYSYMBOL_46_ = 46,                       /* '*'  */
  YYSYMBOL_47_ = 47,                       /* '/'  */
  YYSYMBOL_UMINUS = 48,                    /* UMINUS  */
  YYSYMBOL_49_ = 49,                       /* '.'  */
  YYSYMBOL_50_ = 50,                       /* ';'  */
  YYSYMBOL_51_ = 51,                       /* '='  */
  YYSYMBOL_52_ = 52,                       /* '('  */
  YYSYMBOL_53_ = 53,                       /* ')'  */
  YYSYMBOL_54_ = 54,                       /* ','  */
  YYSYMBOL_55_ = 55,                       /* '{'  */
  YYSYMBOL_56_ = 56,                       /* '}'  */
  YYSYMBOL_57_ = 57,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 58,                  /* $accept  */
  YYSYMBOL_program = 59,                   /* program  */
  YYSYMBOL_function = 60,                  /* function  */
  YYSYMBOL_statement = 61,                 /* statement  */
  YYSYMBOL_stmt_list = 62,                 /* stmt_list  */
  YYSYMBOL_case_statements = 63,           /* case_statements  */
  YYSYMBOL_case_statement = 64,            /* case_statement  */
  YYSYMBOL_default_stmt = 65,              /* default_stmt  */
  YYSYMBOL_assignment_stmt = 66,           /* assignment_stmt  */
  YYSYMBOL_case_expr = 67,                 /* case_expr  */
  YYSYMBOL_char_expr = 68,                 /* char_expr  */
  YYSYMBOL_array_exp = 69,                 /* array_exp  */
  YYSYMBOL_expr = 70                       /* expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   448

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  13
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  215

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      52,    53,    46,    44,    54,    45,    49,    47,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    57,    50,
      43,    51,    42,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,     2,    56,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    48
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    64,    64,    67,    68,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   103,
     105,   107,   110,   112,   114,   117,   118,   120,   121,   124,
     126,   128,   129,   131,   132,   133,   134,   135,   136,   137,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INTEGER", "VARIABLE",
  "FLOAT", "CHAR", "ARRAYV", "WHILE", "IF", "PRINT", "INTT", "FLOATT",
  "CHART", "DO", "FOR", "BREAK", "SWITCH", "CASE", "DEFAULT", "ARRAY",
  "SORT", "SEARCH", "DELETE", "INSERTFIRST", "INSERTLAST", "LENGTH", "MAX",
  "MIN", "APPEND", "DELETEALL", "LOWER", "UPPER", "COPY", "COMPARE",
  "CONTAINS", "IFX", "ELSE", "GE", "LE", "EQ", "NE", "'>'", "'<'", "'+'",
  "'-'", "'*'", "'/'", "UMINUS", "'.'", "';'", "'='", "'('", "')'", "','",
  "'{'", "'}'", "':'", "$accept", "program", "function", "statement",
  "stmt_list", "case_statements", "case_statement", "default_stmt",
  "assignment_stmt", "case_expr", "char_expr", "array_exp", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-163)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -163,     8,   149,  -163,  -163,   -23,  -163,  -163,  -163,    12,
      14,     0,    46,    47,    63,   312,    18,    29,    78,    31,
      45,    48,    65,    66,    67,    68,    69,    70,    71,    80,
      82,    83,    96,    97,     0,  -163,  -163,     0,   312,  -163,
     100,     0,     0,     0,  -163,   362,    49,   101,   115,   122,
     163,   181,   136,   183,   184,   185,   186,   187,   188,   189,
     191,   192,   193,   196,   199,   201,    59,   202,  -163,   -24,
    -163,    81,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -163,   375,    15,   330,  -163,  -163,  -163,  -163,
     172,   174,   194,   190,  -163,   195,   198,   200,   203,   205,
     197,   207,   224,   241,   242,   225,   244,   245,  -163,  -163,
     246,   247,  -163,  -163,  -163,     2,     2,     2,     2,     2,
       2,   -45,   -45,  -163,  -163,  -163,   312,   312,     0,     0,
       0,   243,   252,    21,    21,    21,    21,   253,   255,   256,
      59,    59,   257,   258,    59,    59,    59,  -163,   208,   346,
     401,   388,   228,  -163,  -163,  -163,   260,   275,   277,   278,
    -163,  -163,  -163,   295,   296,  -163,  -163,   297,   298,   299,
     312,   262,   163,     6,    16,  -163,   303,   304,   305,   306,
     308,   309,   310,   311,   313,  -163,  -163,   325,  -163,  -163,
    -163,   322,   323,  -163,   254,  -163,  -163,  -163,  -163,  -163,
    -163,  -163,  -163,  -163,   312,   312,   312,  -163,  -163,   206,
     259,   315,   316,  -163,  -163
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     1,    51,    54,    50,    52,    53,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     2,     5,     0,     0,     3,
       0,     0,     0,     0,    54,     0,     0,     0,     0,     0,
      42,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    55,     0,
      35,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     6,     0,     0,     0,     7,     9,    10,    12,
       0,     0,     0,     0,    11,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    47,    46,
       0,     0,    66,    34,    36,    62,    63,    65,    64,    61,
      60,    56,    57,    58,    59,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    28,    32,     0,
      41,     0,     0,    13,    48,    49,     0,     0,     0,     0,
      16,    14,    15,     0,     0,    24,    25,     0,     0,     0,
       0,     0,    42,     0,     0,    37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    29,     0,    44,    43,
      45,     0,     0,    38,     0,    17,    20,    18,    19,    27,
      26,    21,    22,    23,     0,     0,     0,    31,    30,     0,
       0,     0,     0,    39,    40
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -163,  -163,  -163,    -2,  -162,  -163,    73,  -163,    77,  -163,
    -114,   -97,    -1
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    70,    71,   174,   175,   194,    92,   191,
     110,   156,    40
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      39,    80,    81,     4,    44,     6,     7,     8,     3,   188,
      45,   189,   190,    49,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,   154,   155,   163,   164,    41,   112,
     167,   168,   169,    68,   173,   192,    69,   157,   158,   159,
      83,    84,    85,   209,   210,    34,    78,    79,    80,    81,
      46,    47,    37,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,   108,    42,   109,    43,    48,   126,   114,
      50,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,    51,    52,    53,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    54,    17,    87,
      55,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    56,    57,    58,
      59,    60,    61,    62,   147,   148,    34,   149,   150,   151,
      90,    36,    63,    37,    64,    65,    38,   113,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    66,    67,
      82,    88,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    89,    17,    91,   185,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    93,    94,    95,    96,    97,
      98,    99,   100,   101,    34,   102,   103,   104,    35,    36,
     105,    37,   208,   106,    38,   107,   111,   114,   114,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,   211,    17,   128,   129,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,     0,   131,   130,   170,   173,   193,   132,   187,
     137,    34,   133,     0,   134,     0,    36,   135,    37,   136,
     138,    38,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,   212,    17,   139,   142,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,   140,   141,   143,   152,   144,
     145,   146,   153,   160,    34,   161,   162,   165,   166,    36,
     207,    37,   186,   176,    38,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,   177,    17,
     178,   179,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,   180,   181,
     182,   183,   184,   195,   196,   197,   198,    34,   199,   200,
     201,   202,    36,   203,    37,   213,   214,    38,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,   204,   205,
     206,     0,     0,   127,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,     0,     0,     0,     0,     0,   171,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
       0,     0,    86,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,     0,     0,   125,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,     0,     0,   172,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81
};

static const yytype_int16 yycheck[] =
{
       2,    46,    47,     3,     4,     5,     6,     7,     0,     3,
      11,     5,     6,    15,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     3,     4,   140,   141,    51,    53,
     144,   145,   146,    34,    18,    19,    37,   134,   135,   136,
      41,    42,    43,   205,   206,    45,    44,    45,    46,    47,
       4,     4,    52,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,     4,    52,     6,    52,     4,    53,    71,
      52,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    52,     4,    52,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    52,    17,    50,
      52,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    52,    52,    52,
      52,    52,    52,    52,   126,   127,    45,   128,   129,   130,
       8,    50,    52,    52,    52,    52,    55,    56,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    52,    52,
      50,    50,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    50,    17,     4,   170,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,     4,    50,     4,     4,     4,
       4,     4,     4,     4,    45,     4,     4,     4,    49,    50,
       4,    52,   204,     4,    55,     4,     4,   209,   210,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    52,    51,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    53,    50,    37,    18,   174,    53,   172,
      53,    45,    54,    -1,    54,    -1,    50,    54,    52,    54,
      53,    55,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    53,    53,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    54,    54,    53,    55,    54,
      54,    54,    50,    50,    45,    50,    50,    50,    50,    50,
      56,    52,    50,    53,    55,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    53,    17,
      53,    53,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    53,    53,
      53,    53,    53,    50,    50,    50,    50,    45,    50,    50,
      50,    50,    50,    50,    52,    50,    50,    55,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    53,    57,
      57,    -1,    -1,    53,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,    53,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    -1,    50,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    -1,    50,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    -1,    50,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    59,    60,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    17,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    45,    49,    50,    52,    55,    61,
      70,    51,    52,    52,     4,    70,     4,     4,     4,    61,
      52,    52,     4,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    70,    70,
      61,    62,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    50,    70,    70,    70,    50,    50,    50,    50,
       8,     4,    66,     4,    50,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     6,
      68,     4,    53,    56,    61,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    50,    53,    53,    52,    51,
      50,    53,    53,    54,    54,    54,    54,    53,    53,    53,
      54,    54,    53,    53,    54,    54,    54,    61,    61,    70,
      70,    70,    55,    50,     3,     4,    69,    69,    69,    69,
      50,    50,    50,    68,    68,    50,    50,    68,    68,    68,
      37,    53,    50,    18,    63,    64,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    61,    50,    66,     3,     5,
       6,    67,    19,    64,    65,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    53,    57,    57,    56,    61,    62,
      62,    16,    16,    50,    50
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    59,    60,    60,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    62,    62,    63,    63,    64,
      65,    66,    66,    67,    67,    67,    68,    68,    69,    69,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     1,     2,     3,     4,     3,
       3,     3,     3,     5,     5,     5,     5,     7,     7,     7,
       7,     7,     7,     7,     5,     5,     7,     7,     5,     7,
       9,     8,     5,     7,     3,     1,     2,     1,     2,     6,
       5,     3,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: function '.'  */
#line 64 "interpreter.y"
                                  { exit(0); }
#line 1469 "y.tab.c"
    break;

  case 3: /* function: function statement  */
#line 67 "interpreter.y"
                                  { ex((yyvsp[0].nPtr));freeNode((yyvsp[0].nPtr)); }
#line 1475 "y.tab.c"
    break;

  case 5: /* statement: ';'  */
#line 78 "interpreter.y"
                                  { (yyval.nPtr) = opr(';', 2, NULL, NULL); }
#line 1481 "y.tab.c"
    break;

  case 6: /* statement: expr ';'  */
#line 79 "interpreter.y"
                                  { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1487 "y.tab.c"
    break;

  case 7: /* statement: PRINT expr ';'  */
#line 80 "interpreter.y"
                                  { (yyval.nPtr) = opr(PRINT, 1, (yyvsp[-1].nPtr)); }
#line 1493 "y.tab.c"
    break;

  case 8: /* statement: VARIABLE '=' expr ';'  */
#line 81 "interpreter.y"
                                  { (yyval.nPtr) = opr('=', 2, id((yyvsp[-3].iValue)), (yyvsp[-1].nPtr)); }
#line 1499 "y.tab.c"
    break;

  case 9: /* statement: INTT VARIABLE ';'  */
#line 82 "interpreter.y"
                                  { (yyval.nPtr) = opr(INTT, 1,id((yyvsp[-1].iValue)));}
#line 1505 "y.tab.c"
    break;

  case 10: /* statement: FLOATT VARIABLE ';'  */
#line 83 "interpreter.y"
                                  { (yyval.nPtr) = opr(FLOATT, 1,id((yyvsp[-1].iValue)));}
#line 1511 "y.tab.c"
    break;

  case 11: /* statement: ARRAY VARIABLE ';'  */
#line 84 "interpreter.y"
                                  { (yyval.nPtr) = opr(ARRAY, 1, id((yyvsp[-1].iValue)));}
#line 1517 "y.tab.c"
    break;

  case 12: /* statement: CHART VARIABLE ';'  */
#line 85 "interpreter.y"
                                  { (yyval.nPtr) = opr(CHART, 1, id((yyvsp[-1].iValue)));}
#line 1523 "y.tab.c"
    break;

  case 13: /* statement: SORT '(' VARIABLE ')' ';'  */
#line 86 "interpreter.y"
                                      {(yyval.nPtr) = opr(SORT, 1, id((yyvsp[-2].iValue)));}
#line 1529 "y.tab.c"
    break;

  case 14: /* statement: MAX '(' VARIABLE ')' ';'  */
#line 87 "interpreter.y"
                                     {(yyval.nPtr) = opr(MAX, 1, id((yyvsp[-2].iValue)));}
#line 1535 "y.tab.c"
    break;

  case 15: /* statement: MIN '(' VARIABLE ')' ';'  */
#line 88 "interpreter.y"
                                     {(yyval.nPtr) = opr(MIN, 1, id((yyvsp[-2].iValue)));}
#line 1541 "y.tab.c"
    break;

  case 16: /* statement: LENGTH '(' VARIABLE ')' ';'  */
#line 89 "interpreter.y"
                                        {(yyval.nPtr) = opr(LENGTH, 1, id((yyvsp[-2].iValue)));}
#line 1547 "y.tab.c"
    break;

  case 17: /* statement: SEARCH '(' VARIABLE ',' array_exp ')' ';'  */
#line 90 "interpreter.y"
                                                      {(yyval.nPtr) = opr(SEARCH, 2, id((yyvsp[-4].iValue)),(yyvsp[-2].nPtr));}
#line 1553 "y.tab.c"
    break;

  case 18: /* statement: INSERTFIRST '(' VARIABLE ',' array_exp ')' ';'  */
#line 91 "interpreter.y"
                                                           {(yyval.nPtr) = opr(INSERTFIRST, 2, id((yyvsp[-4].iValue)),(yyvsp[-2].nPtr));}
#line 1559 "y.tab.c"
    break;

  case 19: /* statement: INSERTLAST '(' VARIABLE ',' array_exp ')' ';'  */
#line 92 "interpreter.y"
                                                          {(yyval.nPtr) = opr(INSERTLAST, 2, id((yyvsp[-4].iValue)),(yyvsp[-2].nPtr));}
#line 1565 "y.tab.c"
    break;

  case 20: /* statement: DELETE '(' VARIABLE ',' array_exp ')' ';'  */
#line 93 "interpreter.y"
                                                      {(yyval.nPtr) = opr(DELETE, 2, id((yyvsp[-4].iValue)),(yyvsp[-2].nPtr));}
#line 1571 "y.tab.c"
    break;

  case 21: /* statement: COPY '(' VARIABLE ',' char_expr ')' ';'  */
#line 94 "interpreter.y"
                                                    {(yyval.nPtr) = opr(COPY, 2, id((yyvsp[-4].iValue)),(yyvsp[-2].nPtr));}
#line 1577 "y.tab.c"
    break;

  case 22: /* statement: COMPARE '(' char_expr ',' char_expr ')' ';'  */
#line 95 "interpreter.y"
                                                        {(yyval.nPtr) = opr(COMPARE, 2, (yyvsp[-4].nPtr),(yyvsp[-2].nPtr));}
#line 1583 "y.tab.c"
    break;

  case 23: /* statement: CONTAINS '(' VARIABLE ',' char_expr ')' ';'  */
#line 96 "interpreter.y"
                                                        {(yyval.nPtr) = opr(CONTAINS, 2, id((yyvsp[-4].iValue)),(yyvsp[-2].nPtr));}
#line 1589 "y.tab.c"
    break;

  case 24: /* statement: LOWER '(' VARIABLE ')' ';'  */
#line 97 "interpreter.y"
                                       {(yyval.nPtr) = opr(LOWER, 1, id((yyvsp[-2].iValue)));}
#line 1595 "y.tab.c"
    break;

  case 25: /* statement: UPPER '(' VARIABLE ')' ';'  */
#line 98 "interpreter.y"
                                       {(yyval.nPtr) = opr(UPPER, 1, id((yyvsp[-2].iValue)));}
#line 1601 "y.tab.c"
    break;

  case 26: /* statement: DELETEALL '(' VARIABLE ',' char_expr ')' ';'  */
#line 99 "interpreter.y"
                                                         {(yyval.nPtr) = opr(DELETEALL, 2, id((yyvsp[-4].iValue)),(yyvsp[-2].nPtr));}
#line 1607 "y.tab.c"
    break;

  case 27: /* statement: APPEND '(' VARIABLE ',' char_expr ')' ';'  */
#line 100 "interpreter.y"
                                                      {(yyval.nPtr) = opr(APPEND, 2, id((yyvsp[-4].iValue)),(yyvsp[-2].nPtr));}
#line 1613 "y.tab.c"
    break;

  case 28: /* statement: WHILE '(' expr ')' statement  */
#line 102 "interpreter.y"
                 { (yyval.nPtr) = opr(WHILE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1619 "y.tab.c"
    break;

  case 29: /* statement: DO statement WHILE '(' expr ')' ';'  */
#line 104 "interpreter.y"
                 {(yyval.nPtr) = opr(DO, 2, (yyvsp[-5].nPtr), (yyvsp[-2].nPtr));}
#line 1625 "y.tab.c"
    break;

  case 30: /* statement: FOR '(' assignment_stmt ';' expr ';' assignment_stmt ')' statement  */
#line 106 "interpreter.y"
                 {(yyval.nPtr) = opr(FOR, 4, (yyvsp[-6].nPtr), (yyvsp[-4].nPtr), (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1631 "y.tab.c"
    break;

  case 31: /* statement: SWITCH '(' VARIABLE ')' '{' case_statements default_stmt '}'  */
#line 108 "interpreter.y"
                 { (yyval.nPtr) = opr(SWITCH, 3, id((yyvsp[-5].iValue)), (yyvsp[-2].nPtr), (yyvsp[-1].nPtr));
                  }
#line 1638 "y.tab.c"
    break;

  case 32: /* statement: IF '(' expr ')' statement  */
#line 111 "interpreter.y"
                 { (yyval.nPtr) = opr(IF, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1644 "y.tab.c"
    break;

  case 33: /* statement: IF '(' expr ')' statement ELSE statement  */
#line 113 "interpreter.y"
                 { (yyval.nPtr) = opr(IF, 3, (yyvsp[-4].nPtr), (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1650 "y.tab.c"
    break;

  case 34: /* statement: '{' stmt_list '}'  */
#line 114 "interpreter.y"
                              { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1656 "y.tab.c"
    break;

  case 36: /* stmt_list: stmt_list statement  */
#line 118 "interpreter.y"
                                  { (yyval.nPtr) = opr(';', 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr)); }
#line 1662 "y.tab.c"
    break;

  case 38: /* case_statements: case_statements case_statement  */
#line 121 "interpreter.y"
                                                  { (yyval.nPtr) = opr(';', 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr)); }
#line 1668 "y.tab.c"
    break;

  case 39: /* case_statement: CASE case_expr ':' stmt_list BREAK ';'  */
#line 124 "interpreter.y"
                                                         {(yyval.nPtr)= opr(CASE,2,(yyvsp[-4].nPtr),(yyvsp[-2].nPtr));}
#line 1674 "y.tab.c"
    break;

  case 40: /* default_stmt: DEFAULT ':' stmt_list BREAK ';'  */
#line 126 "interpreter.y"
                                               {(yyval.nPtr)=opr(DEFAULT,1,(yyvsp[-2].nPtr));}
#line 1680 "y.tab.c"
    break;

  case 41: /* assignment_stmt: VARIABLE '=' expr  */
#line 128 "interpreter.y"
                                    { (yyval.nPtr) = opr('=', 2, id((yyvsp[-2].iValue)), (yyvsp[0].nPtr)); }
#line 1686 "y.tab.c"
    break;

  case 43: /* case_expr: FLOAT  */
#line 131 "interpreter.y"
                                  { (yyval.nPtr) = conFloat((yyvsp[0].floatValue));}
#line 1692 "y.tab.c"
    break;

  case 44: /* case_expr: INTEGER  */
#line 132 "interpreter.y"
                                  { (yyval.nPtr) = con((yyvsp[0].iValue)); }
#line 1698 "y.tab.c"
    break;

  case 45: /* case_expr: CHAR  */
#line 133 "interpreter.y"
                                  { (yyval.nPtr) = conChar((yyvsp[0].charValue));}
#line 1704 "y.tab.c"
    break;

  case 46: /* char_expr: CHAR  */
#line 134 "interpreter.y"
                                  { (yyval.nPtr) = conChar((yyvsp[0].charValue));}
#line 1710 "y.tab.c"
    break;

  case 47: /* char_expr: VARIABLE  */
#line 135 "interpreter.y"
                                  { (yyval.nPtr) = id((yyvsp[0].iValue)); }
#line 1716 "y.tab.c"
    break;

  case 48: /* array_exp: INTEGER  */
#line 136 "interpreter.y"
                                  { (yyval.nPtr) = con((yyvsp[0].iValue)); }
#line 1722 "y.tab.c"
    break;

  case 49: /* array_exp: VARIABLE  */
#line 137 "interpreter.y"
                                  { (yyval.nPtr) = id((yyvsp[0].iValue)); }
#line 1728 "y.tab.c"
    break;

  case 50: /* expr: FLOAT  */
#line 139 "interpreter.y"
                                  { (yyval.nPtr) = conFloat((yyvsp[0].floatValue));}
#line 1734 "y.tab.c"
    break;

  case 51: /* expr: INTEGER  */
#line 140 "interpreter.y"
                                  { (yyval.nPtr) = con((yyvsp[0].iValue)); }
#line 1740 "y.tab.c"
    break;

  case 52: /* expr: CHAR  */
#line 141 "interpreter.y"
                                  { (yyval.nPtr) = conChar((yyvsp[0].charValue));}
#line 1746 "y.tab.c"
    break;

  case 53: /* expr: ARRAYV  */
#line 142 "interpreter.y"
                                  { (yyval.nPtr) = conArray((yyvsp[0].aValue));}
#line 1752 "y.tab.c"
    break;

  case 54: /* expr: VARIABLE  */
#line 143 "interpreter.y"
                                  { (yyval.nPtr) = id((yyvsp[0].iValue)); }
#line 1758 "y.tab.c"
    break;

  case 55: /* expr: '-' expr  */
#line 144 "interpreter.y"
                                  { (yyval.nPtr) = opr(UMINUS, 1, (yyvsp[0].nPtr)); }
#line 1764 "y.tab.c"
    break;

  case 56: /* expr: expr '+' expr  */
#line 145 "interpreter.y"
                                  { (yyval.nPtr) = opr('+', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1770 "y.tab.c"
    break;

  case 57: /* expr: expr '-' expr  */
#line 146 "interpreter.y"
                                  { (yyval.nPtr) = opr('-', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1776 "y.tab.c"
    break;

  case 58: /* expr: expr '*' expr  */
#line 147 "interpreter.y"
                                  { (yyval.nPtr) = opr('*', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1782 "y.tab.c"
    break;

  case 59: /* expr: expr '/' expr  */
#line 148 "interpreter.y"
                                  { (yyval.nPtr) = opr('/', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1788 "y.tab.c"
    break;

  case 60: /* expr: expr '<' expr  */
#line 149 "interpreter.y"
                                  { (yyval.nPtr) = opr('<', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1794 "y.tab.c"
    break;

  case 61: /* expr: expr '>' expr  */
#line 150 "interpreter.y"
                                  { (yyval.nPtr) = opr('>', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1800 "y.tab.c"
    break;

  case 62: /* expr: expr GE expr  */
#line 151 "interpreter.y"
                                  { (yyval.nPtr) = opr(GE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1806 "y.tab.c"
    break;

  case 63: /* expr: expr LE expr  */
#line 152 "interpreter.y"
                                  { (yyval.nPtr) = opr(LE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1812 "y.tab.c"
    break;

  case 64: /* expr: expr NE expr  */
#line 153 "interpreter.y"
                                  { (yyval.nPtr) = opr(NE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1818 "y.tab.c"
    break;

  case 65: /* expr: expr EQ expr  */
#line 154 "interpreter.y"
                                  { (yyval.nPtr) = opr(EQ, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1824 "y.tab.c"
    break;

  case 66: /* expr: '(' expr ')'  */
#line 155 "interpreter.y"
                                  { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1830 "y.tab.c"
    break;


#line 1834 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 158 "interpreter.y"


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
