/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parserM.y" /* yacc.c:339  */


#include "P3M.h"

int yyerror (char* yaccProvidedMessage);
int yylex(void);

	extern char* yytext;
	extern FILE* yyin;
	extern FILE* yyout;

int pnum=0;
int namef=0;
int FlagScopeFormal=0;
char *IDV;
int flagMemberLvalue=0;
int lock1=0;
int lock2=0;
struct Stack *scopeoffsetstack; 
struct Stack *loopcounterstack; 
int funcounter=0;
int lockA=1;
int lock=1;
expr *ptrEx=NULL;
expr *ptrElist=NULL;
int flagElist;
expr *TableforlistHead[1000];
int elistptr=-1;
quad *ptrQ=NULL;

#line 97 "parser.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.h".  */
#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IF_ST = 258,
    ELSE_ST = 259,
    FOR_ST = 260,
    WHILE_ST = 261,
    AND_ST = 262,
    NOT_ST = 263,
    OR_ST = 264,
    LOCAL_ST = 265,
    CONTINUE_ST = 266,
    BREAK_ST = 267,
    TRUE_ST = 268,
    FALSE_ST = 269,
    NIL_ST = 270,
    FUNC_ST = 271,
    RETURN_ST = 272,
    PLUS_OP = 273,
    MINUS_OP = 274,
    EQUAL_OP = 275,
    MULTI_OP = 276,
    DIVISION_OP = 277,
    PERCENT_OP = 278,
    INCREMENT_OP = 279,
    DICREMENT_OP = 280,
    COMP_EQUAL_OP = 281,
    COMP_NOT_EQUAL_OP = 282,
    COMP_BIGGER_OP = 283,
    COMP_LESS_OP = 284,
    COMP_BIGGER_EQUAL_OP = 285,
    COMP_LESS_EQUAL_OP = 286,
    LEFT_CBRACKET = 287,
    RIGHT_CBRACKET = 288,
    LEFT_PARENTHESIS = 289,
    RIGHT_PARENTHESIS = 290,
    SEMICOLON = 291,
    COMMA = 292,
    COLON = 293,
    DOUBLE_COLON = 294,
    FULL_STOP = 295,
    RANGE = 296,
    LEFT_ARRAY = 297,
    RIGHT_ARRAY = 298,
    ID = 299,
    NUMBER_REAL = 300,
    NUMBER_INT = 301,
    STRING = 302,
    COMMENT = 303,
    COMMENT1 = 304,
    SPACE = 305,
    OTHER = 306,
    OTHER2 = 307,
    OTHER3 = 308,
    OTHER4 = 309,
    UMINUS = 310
  };
#endif
/* Tokens.  */
#define IF_ST 258
#define ELSE_ST 259
#define FOR_ST 260
#define WHILE_ST 261
#define AND_ST 262
#define NOT_ST 263
#define OR_ST 264
#define LOCAL_ST 265
#define CONTINUE_ST 266
#define BREAK_ST 267
#define TRUE_ST 268
#define FALSE_ST 269
#define NIL_ST 270
#define FUNC_ST 271
#define RETURN_ST 272
#define PLUS_OP 273
#define MINUS_OP 274
#define EQUAL_OP 275
#define MULTI_OP 276
#define DIVISION_OP 277
#define PERCENT_OP 278
#define INCREMENT_OP 279
#define DICREMENT_OP 280
#define COMP_EQUAL_OP 281
#define COMP_NOT_EQUAL_OP 282
#define COMP_BIGGER_OP 283
#define COMP_LESS_OP 284
#define COMP_BIGGER_EQUAL_OP 285
#define COMP_LESS_EQUAL_OP 286
#define LEFT_CBRACKET 287
#define RIGHT_CBRACKET 288
#define LEFT_PARENTHESIS 289
#define RIGHT_PARENTHESIS 290
#define SEMICOLON 291
#define COMMA 292
#define COLON 293
#define DOUBLE_COLON 294
#define FULL_STOP 295
#define RANGE 296
#define LEFT_ARRAY 297
#define RIGHT_ARRAY 298
#define ID 299
#define NUMBER_REAL 300
#define NUMBER_INT 301
#define STRING 302
#define COMMENT 303
#define COMMENT1 304
#define SPACE 305
#define OTHER 306
#define OTHER2 307
#define OTHER3 308
#define OTHER4 309
#define UMINUS 310

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 99 "parserM.y" /* yacc.c:355  */

int intVal;
double doubleVal;
char*  strVal;
struct  SymbolTableEntry *sym;
struct expr *expr;
unsigned un;
struct call *callx;
struct forpr *forpre;
struct stmt_t *stmt_t;
struct indext *indext;

#line 260 "parser.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 275 "parser.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
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
#define YYLAST   609

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  112
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  200

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   310

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   165,   165,   168,   173,   185,   189,   195,   196,   197,
     198,   199,   201,   219,   236,   240,   241,   243,   247,   266,
     285,   305,   325,   344,   362,   383,   403,   422,   454,   484,
     538,   595,   600,   604,   615,   655,   683,   715,   741,   771,
     776,   850,   853,   856,   859,   863,   868,   879,   889,   899,
     904,   911,   919,   944,   945,   948,   951,   968,   975,   976,
     979,   993,  1006,  1006,  1030,  1033,  1033,  1055,  1058,  1073,
    1085,  1098,  1103,  1106,  1113,  1113,  1116,  1118,  1120,  1130,
    1130,  1139,  1146,  1152,  1170,  1198,  1201,  1204,  1207,  1210,
    1213,  1217,  1217,  1218,  1221,  1221,  1222,  1225,  1232,  1247,
    1249,  1255,  1258,  1261,  1266,  1273,  1288,  1307,  1310,  1313,
    1328,  1347,  1362
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF_ST", "ELSE_ST", "FOR_ST", "WHILE_ST",
  "AND_ST", "NOT_ST", "OR_ST", "LOCAL_ST", "CONTINUE_ST", "BREAK_ST",
  "TRUE_ST", "FALSE_ST", "NIL_ST", "FUNC_ST", "RETURN_ST", "PLUS_OP",
  "MINUS_OP", "EQUAL_OP", "MULTI_OP", "DIVISION_OP", "PERCENT_OP",
  "INCREMENT_OP", "DICREMENT_OP", "COMP_EQUAL_OP", "COMP_NOT_EQUAL_OP",
  "COMP_BIGGER_OP", "COMP_LESS_OP", "COMP_BIGGER_EQUAL_OP",
  "COMP_LESS_EQUAL_OP", "LEFT_CBRACKET", "RIGHT_CBRACKET",
  "LEFT_PARENTHESIS", "RIGHT_PARENTHESIS", "SEMICOLON", "COMMA", "COLON",
  "DOUBLE_COLON", "FULL_STOP", "RANGE", "LEFT_ARRAY", "RIGHT_ARRAY", "ID",
  "NUMBER_REAL", "NUMBER_INT", "STRING", "COMMENT", "COMMENT1", "SPACE",
  "OTHER", "OTHER2", "OTHER3", "OTHER4", "UMINUS", "$accept", "program",
  "stmts", "stmt", "expr", "term", "assignexpr", "primary", "lvalue",
  "tableitem", "member", "call", "callsuffix", "normcall", "methodcall",
  "elist", "$@1", "exprs", "$@2", "objectdef", "indexed", "indexedelems",
  "indexedelem", "block", "$@3", "funcblockstart", "funcblockend",
  "funcbody", "funcargs", "$@4", "funcname", "funcprefix", "funcdef",
  "const", "idlist", "$@5", "IDS", "$@6", "elseprefix", "ifprefix",
  "ifstmt1", "ifstmt2", "loopstart", "loopend", "loopstmt", "whilestart",
  "whilecond", "whilestmt", "N", "M", "forprefix", "forstmt", "returnstmt", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310
};
# endif

#define YYPACT_NINF -68

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-68)))

#define YYTABLE_NINF -4

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-4)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,    18,   130,   -68,   -14,   -11,   -68,   250,   -19,    -4,
       0,   -68,   -68,   -68,   170,   250,    80,    80,   -68,   250,
     -68,   -10,   210,   -68,   -68,   -68,   -68,    39,   358,   -68,
     -68,   -68,    87,   -68,   -68,     3,   -68,   -68,   -68,   -68,
     130,   -68,   -68,    12,   -68,    49,   -68,   -68,   -68,   250,
     250,   -68,   -68,   -68,   -68,   -68,   383,   -68,   -68,   -26,
       3,   -26,   -68,   433,    31,   -68,   250,   533,    24,    25,
      32,   -68,   -68,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   -68,   250,   -68,   -68,   250,    38,
      41,   250,   -68,   -68,   -68,   250,    42,   250,    83,   250,
     -68,    44,    57,   250,   458,    56,   -68,    58,    16,   -68,
      60,   333,    59,   -68,   -68,    66,   -68,   250,   250,   -12,
     -12,   -68,   -68,   -68,   564,   564,   169,   169,   169,   169,
     533,    64,   -68,    68,   281,    65,   -68,   307,   -68,   130,
     483,   130,   -68,   -68,   -68,   -68,   -68,    69,   -68,   -68,
      60,   -68,   -68,   250,   250,   250,   -68,    32,   578,   550,
     -68,   250,   -68,   -68,   -68,   -68,   -68,   -68,    61,    76,
     -68,   -68,   250,    75,   508,   533,   -68,    78,   -68,   -68,
      85,   -68,   -68,   408,   -68,   -68,    59,   -68,    81,   -68,
     -68,   -68,   -68,   -68,    79,   -68,   -68,   -68,    81,   -68
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,   107,     1,     0,     0,   104,     0,     0,     0,
       0,    88,    89,    90,     0,     0,     0,     0,    74,   107,
      16,     0,    64,    46,    86,    85,    87,     4,     0,    31,
      17,    39,    41,    50,    49,    42,    43,    14,    15,    45,
     107,     7,     8,     0,     9,     0,   107,    10,    11,     0,
      64,    34,    47,    13,    12,   111,     0,    33,   107,    35,
       0,    37,     5,     0,     0,    48,     0,    62,     0,     0,
      72,   108,   108,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     6,     0,    36,    38,    64,     0,
       0,     0,    56,    58,    59,    64,     0,     0,    99,     0,
     101,    82,     0,    64,     0,     0,   112,     0,   107,    32,
      44,     0,    67,    68,    69,     0,    70,     0,     0,    18,
      19,    20,    21,    22,    27,    28,    23,    25,    24,    26,
      40,     0,    51,     0,     0,     0,    53,     0,    97,   107,
       0,   107,   106,    81,    83,    79,    76,     0,    98,   108,
       0,    75,     4,    64,     0,     0,    63,    72,    29,    30,
      60,    64,    52,    55,    54,   100,   105,   102,    93,     0,
      84,   107,     0,     0,     0,    65,    71,     0,   103,    91,
       0,    77,   101,     0,    57,    73,    67,    61,    96,    80,
      78,   107,   109,    66,     0,    92,   110,    94,    96,    95
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -68,   -68,    63,   -38,    -2,   -68,   -68,   -68,    37,   -68,
     -68,    40,   -68,   -68,   -68,   -44,   -68,   -64,   -68,   -68,
     -68,   -27,    17,   -35,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   -16,   -68,   -68,   -68,   -67,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -34,   -68,   -68,   -68,   -45,   -65,
     -68,   -68,   -68
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    27,    67,    29,    30,    31,    32,    33,
      34,    35,    92,    93,    94,    68,   112,   156,   186,    36,
      69,   116,    70,    37,    62,   169,   190,   170,   146,   168,
     144,   102,    38,    39,   180,   188,   195,   198,   139,    40,
      41,    42,   141,   178,   142,    43,   100,    44,    45,   117,
      46,    47,    48
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      28,   103,    98,    64,    -3,    51,   105,   118,    88,    75,
      76,    77,    56,    57,    89,    90,    91,    63,     3,     4,
      49,     5,     6,    50,     7,    52,     8,     9,    10,    11,
      12,    13,    53,    14,    65,    15,    54,    95,    28,    -2,
      16,    17,   107,    96,   131,    97,    99,   104,    18,   151,
      19,   135,    20,    59,    61,    21,    60,    60,    22,   147,
      23,    24,    25,    26,   111,   101,   110,   113,   114,   115,
     152,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   132,   130,   172,   133,   136,   138,   143,   134,
       8,   145,   149,   150,   153,   137,   155,   140,    66,   160,
     163,   165,   161,   167,   171,   179,    28,    85,    18,   173,
     184,    86,    87,   187,    58,   158,   159,   177,   194,    21,
     189,    88,   193,   197,    23,   108,   182,    89,    90,    91,
     176,   199,   157,     4,   181,     5,     6,    28,     7,    28,
       8,     9,    10,    11,    12,    13,   196,    14,   191,    15,
       0,     0,   174,   175,    16,    17,     0,     0,     0,     0,
       0,     0,    18,     0,    19,     0,    20,     0,     0,    21,
     183,     0,    22,     0,    23,    24,    25,    26,     7,     0,
       8,     0,     0,    11,    12,    13,     0,    73,    74,    15,
      75,    76,    77,     0,    16,    17,     0,    -4,    -4,    -4,
      -4,     0,     0,     0,    19,     0,    55,     0,     0,    21,
       0,     0,    22,     0,    23,    24,    25,    26,     7,     0,
       8,     0,     0,    11,    12,    13,     0,     0,     0,    15,
       0,     0,     0,     0,    16,    17,     0,     0,     0,     0,
       0,     0,    66,     0,    19,     0,     0,     0,     0,    21,
       0,     0,    22,     0,    23,    24,    25,    26,     7,     0,
       8,     0,     0,    11,    12,    13,     0,     0,     0,    15,
       0,     0,     0,     0,    16,    17,     0,     0,     0,     0,
       0,     0,     0,     0,    19,     0,     0,     0,    71,    21,
      72,     0,    22,     0,    23,    24,    25,    26,     0,    73,
      74,     0,    75,    76,    77,     0,     0,    78,    79,    80,
      81,    82,    83,     0,    71,     0,    72,     0,     0,     0,
       0,     0,     0,     0,   162,    73,    74,     0,    75,    76,
      77,     0,     0,    78,    79,    80,    81,    82,    83,     0,
      71,     0,    72,     0,     0,     0,     0,     0,     0,     0,
     164,    73,    74,     0,    75,    76,    77,     0,     0,    78,
      79,    80,    81,    82,    83,    71,     0,    72,     0,     0,
       0,   154,     0,     0,     0,     0,    73,    74,     0,    75,
      76,    77,     0,     0,    78,    79,    80,    81,    82,    83,
      71,     0,    72,     0,    84,     0,     0,     0,     0,     0,
       0,    73,    74,     0,    75,    76,    77,     0,     0,    78,
      79,    80,    81,    82,    83,    71,     0,    72,     0,   106,
       0,     0,     0,     0,     0,     0,    73,    74,     0,    75,
      76,    77,     0,     0,    78,    79,    80,    81,    82,    83,
      71,     0,    72,     0,   192,     0,     0,     0,     0,     0,
       0,    73,    74,     0,    75,    76,    77,     0,     0,    78,
      79,    80,    81,    82,    83,    71,     0,    72,   109,     0,
       0,     0,     0,     0,     0,     0,    73,    74,     0,    75,
      76,    77,     0,     0,    78,    79,    80,    81,    82,    83,
      71,     0,    72,   148,     0,     0,     0,     0,     0,     0,
       0,    73,    74,     0,    75,    76,    77,     0,     0,    78,
      79,    80,    81,    82,    83,    71,     0,    72,   166,     0,
       0,     0,     0,     0,     0,     0,    73,    74,     0,    75,
      76,    77,     0,     0,    78,    79,    80,    81,    82,    83,
      71,   185,    72,     0,     0,     0,     0,     0,     0,     0,
       0,    73,    74,     0,    75,    76,    77,    71,     0,    78,
      79,    80,    81,    82,    83,     0,     0,     0,    73,    74,
       0,    75,    76,    77,     0,     0,    78,    79,    80,    81,
      82,    83,    73,    74,     0,    75,    76,    77,     0,     0,
      -4,    -4,    80,    81,    82,    83,    73,    74,     0,    75,
      76,    77,     0,     0,    78,    79,    80,    81,    82,    83
};

static const yytype_int16 yycheck[] =
{
       2,    46,    40,    19,     0,     7,    50,    72,    34,    21,
      22,    23,    14,    15,    40,    41,    42,    19,     0,     3,
      34,     5,     6,    34,     8,    44,    10,    11,    12,    13,
      14,    15,    36,    17,    44,    19,    36,    34,    40,     0,
      24,    25,    58,    40,    88,    42,    34,    49,    32,    33,
      34,    95,    36,    16,    17,    39,    16,    17,    42,   103,
      44,    45,    46,    47,    66,    16,    35,    43,    43,    37,
     108,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    44,    85,   149,    44,    44,     4,    44,    91,
      10,    34,    36,    35,    34,    97,    37,    99,    32,    35,
      35,   139,    34,   141,    35,    44,   108,    20,    32,   153,
      35,    24,    25,    35,    34,   117,   118,   161,    37,    39,
      35,    34,   186,    44,    44,    62,   171,    40,    41,    42,
     157,   198,   115,     3,   169,     5,     6,   139,     8,   141,
      10,    11,    12,    13,    14,    15,   191,    17,   182,    19,
      -1,    -1,   154,   155,    24,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    34,    -1,    36,    -1,    -1,    39,
     172,    -1,    42,    -1,    44,    45,    46,    47,     8,    -1,
      10,    -1,    -1,    13,    14,    15,    -1,    18,    19,    19,
      21,    22,    23,    -1,    24,    25,    -1,    28,    29,    30,
      31,    -1,    -1,    -1,    34,    -1,    36,    -1,    -1,    39,
      -1,    -1,    42,    -1,    44,    45,    46,    47,     8,    -1,
      10,    -1,    -1,    13,    14,    15,    -1,    -1,    -1,    19,
      -1,    -1,    -1,    -1,    24,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    34,    -1,    -1,    -1,    -1,    39,
      -1,    -1,    42,    -1,    44,    45,    46,    47,     8,    -1,
      10,    -1,    -1,    13,    14,    15,    -1,    -1,    -1,    19,
      -1,    -1,    -1,    -1,    24,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,     7,    39,
       9,    -1,    42,    -1,    44,    45,    46,    47,    -1,    18,
      19,    -1,    21,    22,    23,    -1,    -1,    26,    27,    28,
      29,    30,    31,    -1,     7,    -1,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    18,    19,    -1,    21,    22,
      23,    -1,    -1,    26,    27,    28,    29,    30,    31,    -1,
       7,    -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    18,    19,    -1,    21,    22,    23,    -1,    -1,    26,
      27,    28,    29,    30,    31,     7,    -1,     9,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    18,    19,    -1,    21,
      22,    23,    -1,    -1,    26,    27,    28,    29,    30,    31,
       7,    -1,     9,    -1,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    18,    19,    -1,    21,    22,    23,    -1,    -1,    26,
      27,    28,    29,    30,    31,     7,    -1,     9,    -1,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    -1,    21,
      22,    23,    -1,    -1,    26,    27,    28,    29,    30,    31,
       7,    -1,     9,    -1,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    18,    19,    -1,    21,    22,    23,    -1,    -1,    26,
      27,    28,    29,    30,    31,     7,    -1,     9,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    -1,    21,
      22,    23,    -1,    -1,    26,    27,    28,    29,    30,    31,
       7,    -1,     9,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    18,    19,    -1,    21,    22,    23,    -1,    -1,    26,
      27,    28,    29,    30,    31,     7,    -1,     9,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    -1,    21,
      22,    23,    -1,    -1,    26,    27,    28,    29,    30,    31,
       7,    33,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    18,    19,    -1,    21,    22,    23,     7,    -1,    26,
      27,    28,    29,    30,    31,    -1,    -1,    -1,    18,    19,
      -1,    21,    22,    23,    -1,    -1,    26,    27,    28,    29,
      30,    31,    18,    19,    -1,    21,    22,    23,    -1,    -1,
      26,    27,    28,    29,    30,    31,    18,    19,    -1,    21,
      22,    23,    -1,    -1,    26,    27,    28,    29,    30,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    57,    58,     0,     3,     5,     6,     8,    10,    11,
      12,    13,    14,    15,    17,    19,    24,    25,    32,    34,
      36,    39,    42,    44,    45,    46,    47,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    75,    79,    88,    89,
      95,    96,    97,   101,   103,   104,   106,   107,   108,    34,
      34,    60,    44,    36,    36,    36,    60,    60,    34,    64,
      67,    64,    80,    60,    88,    44,    32,    60,    71,    76,
      78,     7,     9,    18,    19,    21,    22,    23,    26,    27,
      28,    29,    30,    31,    36,    20,    24,    25,    34,    40,
      41,    42,    68,    69,    70,    34,    40,    42,    59,    34,
     102,    16,    87,   104,    60,    71,    36,    88,    58,    35,
      35,    60,    72,    43,    43,    37,    77,   105,   105,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    71,    44,    44,    60,    71,    44,    60,     4,    94,
      60,    98,   100,    44,    86,    34,    84,    71,    35,    36,
      35,    33,    59,    34,    38,    37,    73,    78,    60,    60,
      35,    34,    43,    35,    43,    59,    35,    59,    85,    81,
      83,    35,   105,    71,    60,    60,    77,    71,    99,    44,
      90,    79,   104,    60,    35,    33,    74,    35,    91,    35,
      82,   100,    36,    73,    37,    92,   104,    44,    93,    92
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    57,    58,    58,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    61,    61,    61,    61,    61,    61,    61,    61,
      62,    63,    63,    63,    63,    63,    64,    64,    64,    64,
      64,    65,    65,    66,    66,    67,    67,    67,    68,    68,
      69,    70,    72,    71,    71,    74,    73,    73,    75,    75,
      76,    77,    77,    78,    80,    79,    81,    82,    83,    85,
      84,    86,    86,    87,    88,    89,    89,    89,    89,    89,
      89,    91,    90,    90,    93,    92,    92,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   108
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     0,     2,     1,     1,     1,
       1,     1,     2,     2,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     4,
       4,     1,     3,     2,     2,     2,     2,     2,     2,     1,
       3,     1,     1,     1,     3,     1,     1,     2,     2,     1,
       1,     3,     4,     3,     4,     4,     2,     6,     1,     1,
       3,     5,     0,     3,     0,     0,     4,     0,     3,     3,
       2,     3,     0,     5,     0,     4,     0,     0,     3,     0,
       4,     1,     0,     2,     4,     1,     1,     1,     1,     1,
       1,     0,     3,     0,     0,     4,     0,     1,     4,     2,
       4,     0,     0,     3,     1,     3,     3,     0,     0,     7,
       7,     2,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 165 "parserM.y" /* yacc.c:1646  */
    {
       
        printf("(%d)(program->stmts stmt)\n",++pnum);}
#line 1590 "parser.c" /* yacc.c:1646  */
    break;

  case 3:
#line 168 "parserM.y" /* yacc.c:1646  */
    {
        
        printf("(%d)(program->   )\n",++pnum);}
#line 1598 "parser.c" /* yacc.c:1646  */
    break;

  case 4:
#line 173 "parserM.y" /* yacc.c:1646  */
    {
          if((yyvsp[-1].stmt_t)==NULL&&(yyvsp[0].stmt_t)!=NULL){
              (yyval.stmt_t)=(yyvsp[0].stmt_t);
          }else if((yyvsp[-1].stmt_t)!=NULL&&(yyvsp[0].stmt_t)!=NULL){
              (yyval.stmt_t)=make_stmt( );
              (yyval.stmt_t)->returnList= mergelist((yyvsp[-1].stmt_t)->returnList, (yyvsp[0].stmt_t)->returnList);
              (yyval.stmt_t)->breakList = mergelist((yyvsp[-1].stmt_t)->breakList, (yyvsp[0].stmt_t)->breakList);
              (yyval.stmt_t)->contList = mergelist((yyvsp[-1].stmt_t)->contList,(yyvsp[0].stmt_t)->contList); 
          }else{

          }
          printf("(%d)(stmts->stmts stmt)\n",++pnum);}
#line 1615 "parser.c" /* yacc.c:1646  */
    break;

  case 5:
#line 185 "parserM.y" /* yacc.c:1646  */
    {(yyval.stmt_t)=NULL; printf("(%d)(stmts->    )\n",++pnum);}
#line 1621 "parser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 189 "parserM.y" /* yacc.c:1646  */
    { 
        

            if(lock==0) Merikh_Assign((yyvsp[-1].expr));
            lock=1;
            resettmp(); (yyval.stmt_t)=NULL;  printf("(%d)(stmt->expr;)\n",++pnum);}
#line 1632 "parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 195 "parserM.y" /* yacc.c:1646  */
    { resettmp(); (yyval.stmt_t)=NULL;    printf("(%d)(stmt->ifstmt1\n)",++pnum);}
#line 1638 "parser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 196 "parserM.y" /* yacc.c:1646  */
    { resettmp();  (yyval.stmt_t)=NULL;   printf("(%d)(stmt->ifstmt2\n)",++pnum);}
#line 1644 "parser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 197 "parserM.y" /* yacc.c:1646  */
    { resettmp();  (yyval.stmt_t)=NULL;  printf("(%d)(stmt->whilestmt\n,++pnum)");}
#line 1650 "parser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 198 "parserM.y" /* yacc.c:1646  */
    { resettmp();  (yyval.stmt_t)=NULL;  printf("(%d)(stmt->forstmt)\n",++pnum);}
#line 1656 "parser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 199 "parserM.y" /* yacc.c:1646  */
    { resettmp();  (yyval.stmt_t)=(yyvsp[0].stmt_t); printf("(%d)(stmt->returnstmt)\n",++pnum);}
#line 1662 "parser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 201 "parserM.y" /* yacc.c:1646  */
    {
          
          resettmp();

          if(loopcntr()>0){
             (yyval.stmt_t)=make_stmt( );
             (yyval.stmt_t)->breakList=newlist(nextquadlabel());
             emit(jump,NULL,NULL,NULL);
          }else{
             printf("\033[0;31m");
		       printf("Error(%d)	[Break not in loop] \n",yylineno); 
		       printf("\033[0m");
             (yyval.stmt_t)=NULL;
          }
          
        //  printf("break:%d,%d",loopcntr(),yylineno);
          printf("(%d)(stmt->break;)\n",++pnum);}
#line 1684 "parser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 219 "parserM.y" /* yacc.c:1646  */
    {

          resettmp();

          if(loopcntr()>0){
             (yyval.stmt_t)=make_stmt( );
             (yyval.stmt_t)->contList=newlist(nextquadlabel());
             emit(jump,NULL,NULL,NULL);
          }else{
             printf("\033[0;31m");
		       printf("Error(%d)	[Continue not in loop] \n",yylineno); 
		       printf("\033[0m");
             (yyval.stmt_t)=NULL;
          }
        
          //printf("continue:%d,%d",loopcntr(),yylineno);
          printf("(%d)(stmt->continue;)\n",++pnum);}
#line 1706 "parser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 236 "parserM.y" /* yacc.c:1646  */
    {
          resettmp();
          (yyval.stmt_t)=(yyvsp[0].stmt_t);
          printf("(%d)(stmt->block)\n",++pnum);}
#line 1715 "parser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 240 "parserM.y" /* yacc.c:1646  */
    { resettmp();   printf("(%d)(stmt->funcdef)\n",++pnum);  (yyval.stmt_t)=NULL;}
#line 1721 "parser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 241 "parserM.y" /* yacc.c:1646  */
    { resettmp(); printf("(%d)(stmt->;)\n",++pnum);  (yyval.stmt_t)=NULL;}
#line 1727 "parser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 244 "parserM.y" /* yacc.c:1646  */
    {
          (yyval.expr)=(yyvsp[0].expr);
          printf("(%d)(expr->assignexpr)\n",++pnum );}
#line 1735 "parser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 247 "parserM.y" /* yacc.c:1646  */
    {
            if((yyvsp[-2].expr)!=NULL&&(yyvsp[0].expr)!=NULL){
                if(CheckTypeArithmExpr((yyvsp[-2].expr))==0&&CheckTypeArithmExpr((yyvsp[0].expr))==0){
                    if(BothConstNum((yyvsp[-2].expr),(yyvsp[0].expr))==1)  (yyval.expr) = newexpr(constnum_e);
                    else                        (yyval.expr) = newexpr(arithexpr_e);
                
                    if((yyval.expr)!=NULL){
                        (yyval.expr)=TmpRec((yyval.expr),(yyvsp[-2].expr),(yyvsp[0].expr));
                    } 
                    emit(add, (yyval.expr), (yyvsp[-2].expr), (yyvsp[0].expr));
                }else{
                        (yyval.expr)=NULL;
                        printf("expr+expr,[$1 or $3 is not arithmetic,or both]\n");
                }
            }else{
                 (yyval.expr)=NULL;
                 printf("expr+expr,[$1 or $3 is NULL,or both]\n");
            }
          printf("(%d)(expr->expr+expr)\n",++pnum );}
#line 1759 "parser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 266 "parserM.y" /* yacc.c:1646  */
    {
            if((yyvsp[-2].expr)!=NULL&&(yyvsp[0].expr)!=NULL){
                if(CheckTypeArithmExpr((yyvsp[-2].expr))==0&&CheckTypeArithmExpr((yyvsp[0].expr))==0){
                    if(BothConstNum((yyvsp[-2].expr),(yyvsp[0].expr))==1)  (yyval.expr) = newexpr(constnum_e);
                    else                        (yyval.expr) = newexpr(arithexpr_e);
                
                    if((yyval.expr)!=NULL){
                        (yyval.expr)=TmpRec((yyval.expr),(yyvsp[-2].expr),(yyvsp[0].expr));
                    } 
                    emit(sub, (yyval.expr), (yyvsp[-2].expr), (yyvsp[0].expr));
                }else{
                        (yyval.expr)=NULL;
                        printf("expr-expr,[$1 or $3 is not arithmetic,or both]\n");
                }
            }else{
                 (yyval.expr)=NULL;
                 printf("expr-expr,[$1 or $3 is NULL,or both]\n");
            }
          printf("(%d)(expr->expr-expr)\n",++pnum);}
#line 1783 "parser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 285 "parserM.y" /* yacc.c:1646  */
    {
            if((yyvsp[-2].expr)!=NULL&&(yyvsp[0].expr)!=NULL){
                if(CheckTypeArithmExpr((yyvsp[-2].expr))==0&&CheckTypeArithmExpr((yyvsp[0].expr))==0){
                    if(BothConstNum((yyvsp[-2].expr),(yyvsp[0].expr))==1)  (yyval.expr) = newexpr(constnum_e);
                    else                        (yyval.expr) = newexpr(arithexpr_e);
                
                    if((yyval.expr)!=NULL){
                        (yyval.expr)=TmpRec((yyval.expr),(yyvsp[-2].expr),(yyvsp[0].expr));
                    } 
                    emit(mult, (yyval.expr), (yyvsp[-2].expr), (yyvsp[0].expr));
                }else{
                        (yyval.expr)=NULL;
                        printf("expr * expr,[$1 or $3 is not arithmetic,or both]\n");
                }
            }else{
                 (yyval.expr)=NULL;
                 printf("expr*expr,[$1 or $3 is NULL,or both]\n");
            }
        
          printf("(%d)(expr->expr*expr)\n",++pnum);}
#line 1808 "parser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 305 "parserM.y" /* yacc.c:1646  */
    {
              if((yyvsp[-2].expr)!=NULL&&(yyvsp[0].expr)!=NULL){
                if(CheckTypeArithmExpr((yyvsp[-2].expr))==0&&CheckTypeArithmExpr((yyvsp[0].expr))==0){
                    if(BothConstNum((yyvsp[-2].expr),(yyvsp[0].expr))==1)  (yyval.expr) = newexpr(constnum_e);
                    else                        (yyval.expr) = newexpr(arithexpr_e);
                
                    if((yyval.expr)!=NULL){
                        (yyval.expr)=TmpRec((yyval.expr),(yyvsp[-2].expr),(yyvsp[0].expr));
                    } 
                    emit(divid, (yyval.expr), (yyvsp[-2].expr), (yyvsp[0].expr));
                }else{
                        (yyval.expr)=NULL;
                        printf("expr / expr,[$1 or $3 is not arithmetic,or both]\n");
                }
            }else{
                 (yyval.expr)=NULL;
                 printf("expr/expr,[$1 or $3 is NULL,or both]\n");
            }

          printf("(%d)expr->(expr/expr)\n",++pnum);}
#line 1833 "parser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 325 "parserM.y" /* yacc.c:1646  */
    {
           if((yyvsp[-2].expr)!=NULL&&(yyvsp[0].expr)!=NULL){
                if(CheckTypeArithmExpr((yyvsp[-2].expr))==0&&CheckTypeArithmExpr((yyvsp[0].expr))==0){
                    if(BothConstNum((yyvsp[-2].expr),(yyvsp[0].expr))==1)  (yyval.expr) = newexpr(constnum_e);
                    else                        (yyval.expr) = newexpr(arithexpr_e);
                
                    if((yyval.expr)!=NULL){
                        (yyval.expr)=TmpRec((yyval.expr),(yyvsp[-2].expr),(yyvsp[0].expr));
                    } 
                    emit(modul, (yyval.expr), (yyvsp[-2].expr), (yyvsp[0].expr));
                }else{
                        (yyval.expr)=NULL;
                        printf("expr % expr,[$1 or $3 is not arithmetic,or both]\n");
                }
            }else{
                 (yyval.expr)=NULL;
                 printf("expr % expr,[$1 or $3 is NULL,or both]\n");
            }
          printf("(%d)(expr->expr mod expr)\n",++pnum);}
#line 1857 "parser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 344 "parserM.y" /* yacc.c:1646  */
    {
            if((yyvsp[-2].expr)!=NULL&&(yyvsp[0].expr)!=NULL){
                lock=0;
                lockA=0;
               (yyval.expr)=newexpr(boolexpr_e);
               if((yyval.expr)!=NULL){
                   (yyval.expr)=TmpRec((yyval.expr),(yyvsp[-2].expr),(yyvsp[0].expr));
               }
               emit(if_greater,NULL,(yyvsp[-2].expr),(yyvsp[0].expr));
               (yyval.expr)->trueList=currquad();
               emit(jump,NULL,NULL,NULL);
               (yyval.expr)->falseList=currquad();
               //Merikh_Assign($$);
            }else{
                 (yyval.expr)=NULL;
                 printf("NULL\n");
            }
          printf("(%d)(expr->expr>expr)\n",++pnum);}
#line 1880 "parser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 362 "parserM.y" /* yacc.c:1646  */
    {
            if((yyvsp[-2].expr)!=NULL&&(yyvsp[0].expr)!=NULL){
                lock=0;
                lockA=0;
               (yyval.expr)=newexpr(boolexpr_e);
               if((yyval.expr)!=NULL){
                  (yyval.expr)=TmpRec((yyval.expr),(yyvsp[-2].expr),(yyvsp[0].expr));
               }
               
               emit(if_greatereq,NULL,(yyvsp[-2].expr),(yyvsp[0].expr));
               (yyval.expr)->trueList=currquad();
               emit(jump,NULL,NULL,NULL);
               (yyval.expr)->falseList=currquad();
             //  Merikh_Assign($$);

            }else{
                 (yyval.expr)=NULL;
                 printf("NULL\n");
            }
           
          printf("(%d)(expr->expr>=expr)\n",++pnum);}
#line 1906 "parser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 383 "parserM.y" /* yacc.c:1646  */
    {
            if((yyvsp[-2].expr)!=NULL&&(yyvsp[0].expr)!=NULL){
                lock=0;
                lockA=0;
               (yyval.expr)=newexpr(boolexpr_e);
               if((yyval.expr)!=NULL){
                   (yyval.expr)=TmpRec((yyval.expr),(yyvsp[-2].expr),(yyvsp[0].expr));
               }

               emit(if_less,NULL,(yyvsp[-2].expr),(yyvsp[0].expr));
               (yyval.expr)->trueList=currquad();
               emit(jump,NULL,NULL,NULL);
               (yyval.expr)->falseList=currquad();
               //Merikh_Assign($$);
            }else{
                 (yyval.expr)=NULL;
                 printf("NULL\n");
            }
           
          printf("(%d)(expr->expr<expr)\n",++pnum);}
#line 1931 "parser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 403 "parserM.y" /* yacc.c:1646  */
    {
            if((yyvsp[-2].expr)!=NULL&&(yyvsp[0].expr)!=NULL){
               lock=0;
               lockA=0;
               (yyval.expr)=newexpr(boolexpr_e);
               if((yyval.expr)!=NULL){
                   (yyval.expr)=TmpRec((yyval.expr),(yyvsp[-2].expr),(yyvsp[0].expr));
               }
               
               emit(if_lesseq,NULL,(yyvsp[-2].expr),(yyvsp[0].expr));
               (yyval.expr)->trueList=currquad();
               emit(jump,NULL,NULL,NULL);
               (yyval.expr)->falseList=currquad();
              //Merikh_Assign($$);
            }else{
                 (yyval.expr)=NULL;
                 printf("NULL\n");
            }
           printf("(%d)(expr->expr<=expr)\n",++pnum);}
#line 1955 "parser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 422 "parserM.y" /* yacc.c:1646  */
    {
           if((yyvsp[-2].expr)!=NULL&&(yyvsp[0].expr)!=NULL){
               lock=0;
               lockA=0;
               (yyval.expr)=newexpr(boolexpr_e);
               if((yyval.expr)!=NULL){
                   (yyval.expr)=TmpRec((yyval.expr),(yyvsp[-2].expr),(yyvsp[0].expr));
               }
              
              
               if((yyvsp[-2].expr)->type==5 && (yyvsp[0].expr)->type!=5){
                   Merikh_Assign((yyvsp[-2].expr));
               }else if((yyvsp[0].expr)->type==5 && (yyvsp[-2].expr)->type!=5){
                    Merikh_Assign((yyvsp[0].expr));
               }else if((yyvsp[0].expr)->type==5 && (yyvsp[-2].expr)->type==5){
                    Merikh_Assign((yyvsp[-2].expr));
                    Merikh_Assign((yyvsp[0].expr));
               }else{

               } 

               emit(if_eq,NULL,(yyvsp[-2].expr),(yyvsp[0].expr));
               (yyval.expr)->trueList=currquad();
               emit(jump,NULL,NULL,NULL);
               (yyval.expr)->falseList=currquad();
               

            }else{
                 (yyval.expr)=NULL;
                 printf("NULL\n");
            }
            printf("(%d)(expr->expr==expr)\n",++pnum);}
#line 1992 "parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 454 "parserM.y" /* yacc.c:1646  */
    {
          if((yyvsp[-2].expr)!=NULL&&(yyvsp[0].expr)!=NULL){
               lock=0;
               lockA=0;
               (yyval.expr)=newexpr(boolexpr_e);
               if((yyval.expr)!=NULL){
                   (yyval.expr)=TmpRec((yyval.expr),(yyvsp[-2].expr),(yyvsp[0].expr));
               }

               if((yyvsp[-2].expr)->type==5 && (yyvsp[0].expr)->type!=5){
                   Merikh_Assign((yyvsp[-2].expr));
               }else if((yyvsp[0].expr)->type==5 && (yyvsp[-2].expr)->type!=5){
                    Merikh_Assign((yyvsp[0].expr));
               }else if((yyvsp[0].expr)->type==5 && (yyvsp[-2].expr)->type==5){
                    Merikh_Assign((yyvsp[-2].expr));
                    Merikh_Assign((yyvsp[0].expr));
               }else{

               } 

               emit(if_noteq,NULL,(yyvsp[-2].expr),(yyvsp[0].expr));
               (yyval.expr)->trueList=currquad();
               emit(jump,NULL,NULL,NULL);
               (yyval.expr)->falseList=currquad();
              
            }else{
                 (yyval.expr)=NULL;
                 printf("NULL\n");
            }
         printf("(%d)(expr->expr!=expr)\n",++pnum);}
#line 2027 "parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 484 "parserM.y" /* yacc.c:1646  */
    {
             lockA=0;
             lock=0;
            if((yyvsp[-3].expr)!=NULL&&(yyvsp[0].expr)!=NULL){
               int flg2;
               int flg1;
               (yyval.expr)=newexpr(boolexpr_e);
               if((yyval.expr)!=NULL){
                   (yyval.expr)=TmpRec((yyval.expr),(yyvsp[-3].expr),(yyvsp[0].expr));
               }   
           
              if((yyvsp[-3].expr)->type!=5){
                  emit(if_eq,(yyvsp[-3].expr),newexpr_bool(1),NULL);
                  (yyvsp[-3].expr)->trueList=currquad();            
                  emit(jump,NULL,NULL,NULL);
                  patchlist((yyvsp[-3].expr)->trueList,currquad()+1);
                  (yyvsp[-3].expr)->falseList=currquad();               
                  flg1=1;
              }else{
                  flg1=0;
              }

              if((yyvsp[0].expr)->type!=5){
                  emit(if_eq,(yyvsp[0].expr),newexpr_bool(1),NULL);
                  (yyvsp[0].expr)->trueList=currquad();
                  emit(jump,NULL,NULL,NULL);
                  (yyvsp[0].expr)->falseList=currquad();
                  flg2=1;
              }else{   
                  flg2=0;           
              }

              if(flg1==1&&flg2==1){
                    (yyval.expr)->trueList=(yyvsp[0].expr)->trueList;
              }else if(flg1==1&&flg2==0){
                    patchlist((yyvsp[0].expr)->trueList,currquad()-1);
                    (yyval.expr)->trueList=(yyvsp[-3].expr)->trueList;
              }else if(flg1==0&&flg2==1){
                    patchlist((yyvsp[-3].expr)->trueList,currquad()-1);
                    (yyval.expr)->trueList=(yyvsp[0].expr)->trueList;
              }else{
                   quads[(yyvsp[-3].expr)->trueList].label=(yyvsp[-3].expr)->trueList+2;
                   (yyval.expr)->trueList=(yyvsp[0].expr)->trueList;
              }
               
               

               (yyval.expr)->falseList=mergelist((yyvsp[-3].expr)->falseList,(yyvsp[0].expr)->falseList);
            
            }else{
                 (yyval.expr)=NULL;
                 printf("expr->expr and expr,[$1 or $2 or both are NULL]\n");
            }
           printf("(%d)(expr->expr and expr)\n",++pnum);}
#line 2086 "parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 538 "parserM.y" /* yacc.c:1646  */
    {
            if((yyvsp[-3].expr)!=NULL&&(yyvsp[0].expr)!=NULL){
               lockA=0;
               lock=0;
               int flg2;
               int flg1;
               (yyval.expr)=newexpr(boolexpr_e);
               if((yyval.expr)!=NULL){
                   (yyval.expr)=TmpRec((yyval.expr),(yyvsp[-3].expr),(yyvsp[0].expr));
               }   
           
              if((yyvsp[-3].expr)->type!=5){
                  emit(if_eq,(yyvsp[-3].expr),newexpr_bool(1),NULL);
                  (yyvsp[-3].expr)->trueList=currquad();            
                  emit(jump,NULL,NULL,NULL);
                  (yyvsp[-3].expr)->falseList=currquad();
                  patchlist((yyvsp[-3].expr)->falseList,currquad()+1);
                  flg1=1;
              }else{
                  flg1=0;
              }

              if((yyvsp[0].expr)->type!=5){
                  emit(if_eq,(yyvsp[0].expr),newexpr_bool(1),NULL);
                  (yyvsp[0].expr)->trueList=currquad();
                  emit(jump,NULL,NULL,NULL);
                  (yyvsp[0].expr)->falseList=currquad();
                  flg2=1;
              }else{   
                  flg2=0;           
              }

              if(flg1==1&&flg2==1){
                    (yyval.expr)->falseList=(yyvsp[0].expr)->falseList;
              }else if(flg1==1&&flg2==0){
                    patchlist((yyvsp[0].expr)->falseList,currquad()-1);
                    (yyval.expr)->falseList=(yyvsp[-3].expr)->falseList;
              }else if(flg1==0&&flg2==1){
                    patchlist((yyvsp[-3].expr)->falseList,currquad()-1);
                    (yyval.expr)->falseList=(yyvsp[0].expr)->falseList;
              }else{
                  // quads[$1->falseList].label=$1->falseList+1;
                   int lbl=FindLabelLast ((yyvsp[-3].expr)->falseList);
                   patchlist((yyvsp[-3].expr)->falseList,lbl+1);
                   (yyval.expr)->falseList=(yyvsp[0].expr)->falseList;
              }
               
               

               (yyval.expr)->trueList=mergelist((yyvsp[-3].expr)->trueList,(yyvsp[0].expr)->trueList);
            
             
            }else{
                 (yyval.expr)=NULL;
                 printf("NULL\n");
            }
           printf("(%d)(expr->expr or expr)\n",++pnum);}
#line 2148 "parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 595 "parserM.y" /* yacc.c:1646  */
    {
            (yyval.expr)=(yyvsp[0].expr);
            printf("(%d)(expr->term)\n",++pnum);}
#line 2156 "parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 600 "parserM.y" /* yacc.c:1646  */
    {
        (yyval.expr)=(yyvsp[-1].expr);
        printf("(%d)( term->(expr) )\n",++pnum);}
#line 2164 "parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 604 "parserM.y" /* yacc.c:1646  */
    {
         if((yyvsp[0].expr)!=NULL && CheckTypeArithmExpr((yyvsp[0].expr))==0){
              (yyval.expr) = newexpr(arithexpr_e);
              (yyval.expr)->sym =  istempexpr((yyvsp[0].expr)) ? (yyvsp[0].expr)->sym : newtmp();
              emit(uminus, (yyval.expr),(yyvsp[0].expr), NULL);
         }else{
              (yyval.expr)=NULL;
               printf("term-> -expr,[$2 is not arithmetic,or is  NULL]\n");
         }
          
          printf("(%d)(term-> -expr UMINUS)\n",++pnum);}
#line 2180 "parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 615 "parserM.y" /* yacc.c:1646  */
    {
           if((yyvsp[0].expr)!=NULL){
                lockA=0;
                lock=0;
                (yyval.expr)=newexpr(boolexpr_e);
                if((yyval.expr)!=NULL){
                           if(istempexpr((yyvsp[0].expr))){
                                (yyval.expr)->sym=(yyvsp[0].expr)->sym;
                           }else{
                                (yyval.expr)->sym=newtmp();
                           }
               }   

              
               int var1,var2;
               if((yyvsp[0].expr)->type!=5)
               {
                     emit(if_eq,NULL,(yyvsp[0].expr),newexpr_bool(1));
                     (yyvsp[0].expr)->trueList=currquad();
                     emit(jump,NULL,NULL,NULL);
                     (yyvsp[0].expr)->falseList=currquad();
                     var1=(yyvsp[0].expr)->falseList;
                     var2=(yyvsp[0].expr)->trueList; 
                     (yyval.expr)->trueList=var1;
                     (yyval.expr)->falseList=var2; 
                    
                     // printf("AAAAAXXXX:T%d,F:%d", $$->trueList, $$->falseList);
               }else{
                     var1=(yyvsp[0].expr)->falseList;
                     var2=(yyvsp[0].expr)->trueList; 
                     (yyval.expr)->trueList=var1;
                     (yyval.expr)->falseList=var2; 
               }
                     
                  
           }else{
               printf("term->!expr,[$expr is NULL]\n");
           }
           printf("(%d)(term->!expr)\n",++pnum);}
#line 2224 "parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 655 "parserM.y" /* yacc.c:1646  */
    { 
         if(IsFunction(scope,(yyvsp[0].expr)->sym->name,yylineno)==1){
          printf("\033[0;31m");
			 printf("Error(%d)	[Variable] (function name with  operator) \"++%s\"\n",yylineno,(yyvsp[0].expr)); 
			 printf("\033[0m");
          (yyval.expr)=NULL;
         }else{
             if(CheckTypeArithmExpr((yyvsp[0].expr))==0&&(yyvsp[0].expr)!=NULL){
                
                 if((strcmp("tableitem_e",GetTypeExpr((yyvsp[0].expr)->type))==0)){
                         (yyval.expr) = emit_iftableitem((yyvsp[0].expr));
                         emit(add,(yyval.expr),(yyval.expr), newexpr_num_int(1));
                         emit(tablesetelem,(yyvsp[0].expr),(yyvsp[0].expr)->index,(yyval.expr));
                 }else{
                         emit(add,(yyvsp[0].expr),(yyvsp[0].expr),newexpr_num_int(1));
                         (yyval.expr)=newexpr(arithexpr_e);
                         (yyval.expr)->sym = newtmp();
                         emit(assign, (yyval.expr),(yyvsp[0].expr),NULL);
                 }
              }else{
                 (yyval.expr)=NULL;
                 printf("term-> ++lvalue,[$2 is not arithmetic or is NULL]\n");
              }

         }
      
         printf("(%d)(term-> ++lvalue)\n",++pnum);}
#line 2256 "parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 683 "parserM.y" /* yacc.c:1646  */
    {
         if(IsFunction(scope,(yyvsp[-1].expr)->sym->name,yylineno)==1){
          printf("\033[0;31m");
			 printf("Error(%d)	[Variable] (function name with operator) \"%s++\"\n",yylineno,(yyvsp[-1].expr)); 
			 printf("\033[0m");
          (yyval.expr)=NULL;
         }else{
                 if(CheckTypeArithmExpr((yyvsp[-1].expr))==0&&(yyvsp[-1].expr)!=NULL){
                 (yyval.expr)=newexpr(var_e);
                 (yyval.expr)->sym=newtmp();

                 if((strcmp("tableitem_e",GetTypeExpr((yyvsp[-1].expr)->type))==0)){
                        expr* val = emit_iftableitem((yyvsp[-1].expr));
                        emit(assign, (yyval.expr),val, NULL);
                        emit(add,val,val,newexpr_num_int(1));
                        emit(tablesetelem,(yyvsp[-1].expr), (yyvsp[-1].expr)->index,val);
                 }else{
                         emit(assign,(yyval.expr),(yyvsp[-1].expr),NULL);
                         emit(add,(yyvsp[-1].expr),(yyvsp[-1].expr),newexpr_num_int(1));
                 }
                

              }else{
                 (yyval.expr)=NULL;
                 printf("term-> lvalue++,[$1  is NULL,or not arithmetic]\n");
              }
         }


 
         printf("(%d)(term-> lvalue++)\n",++pnum);}
#line 2292 "parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 715 "parserM.y" /* yacc.c:1646  */
    {
        if(IsFunction(scope,(yyvsp[0].expr)->sym->name,yylineno)==1){
          printf("\033[0;31m");
			 printf("Error(%d)	[Variable] (function name with operator) \"--%s\"\n",yylineno,(yyvsp[0].expr)); 
			 printf("\033[0m");
          (yyval.expr)=NULL;
        }else{
               if(CheckTypeArithmExpr((yyvsp[0].expr))==0&&(yyvsp[0].expr)!=NULL){
                
                 if((strcmp("tableitem_e",GetTypeExpr((yyvsp[0].expr)->type))==0)){
                         (yyval.expr) = emit_iftableitem((yyvsp[0].expr));
                         emit(sub,(yyval.expr),(yyval.expr), newexpr_num_int(1));
                         emit(tablesetelem,(yyvsp[0].expr),(yyvsp[0].expr)->index,(yyval.expr));
                 }else{
                         emit(sub,(yyvsp[0].expr),(yyvsp[0].expr),newexpr_num_int(1));
                         (yyval.expr)=newexpr(arithexpr_e);
                         (yyval.expr)->sym = newtmp();
                         emit(assign, (yyval.expr),(yyvsp[0].expr),NULL);
                 }
              }else{
                 (yyval.expr)=NULL;
                 printf("term-> --lvalue,[$2 is not arithmetic or is NULL]\n");
              }
         }
        printf("(%d)(term-> --lvalue)\n",++pnum);}
#line 2322 "parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 741 "parserM.y" /* yacc.c:1646  */
    {
       if(IsFunction(scope,(yyvsp[-1].expr)->sym->name,yylineno)==1){
          printf("\033[0;31m");
			 printf("Error(%d)	[Variable] (function name with operator) \"%s--\"\n",yylineno,(yyvsp[-1].expr)); 
			 printf("\033[0m");
          (yyval.expr)=NULL;
       }else{
            if(CheckTypeArithmExpr((yyvsp[-1].expr))==0&&(yyvsp[-1].expr)!=NULL){
                 (yyval.expr)=newexpr(var_e);
                 (yyval.expr)->sym=newtmp();

                 if((strcmp("tableitem_e",GetTypeExpr((yyvsp[-1].expr)->type))==0)){
                        expr* val = emit_iftableitem((yyvsp[-1].expr));
                        emit(assign, (yyval.expr),val, NULL);
                        emit(sub,val,val,newexpr_num_int(1));
                        emit(tablesetelem,(yyvsp[-1].expr), (yyvsp[-1].expr)->index,val);
                 }else{
                         emit(assign,(yyval.expr),(yyvsp[-1].expr),NULL);
                         emit(sub,(yyvsp[-1].expr),(yyvsp[-1].expr),newexpr_num_int(1));
                 }
                

            }else{
                 (yyval.expr)=NULL;
                 printf("term-> lvalue--,[$1  is NULL,or not arithmetic]\n");
                 printf("error\n");
            }
         }
         printf("(%d)(term-> lvalue--)\n",++pnum);}
#line 2356 "parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 771 "parserM.y" /* yacc.c:1646  */
    {
        (yyval.expr)=(yyvsp[0].expr);
        printf("(%d)(term->primary)\n",++pnum);}
#line 2364 "parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 776 "parserM.y" /* yacc.c:1646  */
    {
  
    //newtmp();
    if((yyvsp[-2].expr)!=NULL){
      if((yyvsp[-2].expr)->sym->name!=NULL){
      
      if(IsFunction(scope,(yyvsp[-2].expr)->sym->name,yylineno)==1&&lock1!=1&&lock2!=1) {
          printf("\033[0;31m");
			    printf("Error(%d)	[Variable] (Assignation to function:%s)\n",yylineno,(yyvsp[-2].expr)); 
			    printf("\033[0m");  
      }

      if(IsFunctionLocal(scope,(yyvsp[-2].expr)->sym->name,yylineno)==1&&lock1==1&&lock2!=1){
          printf("\033[0;31m");
			    printf("Error(%d)	[Variable] (Assignation(local) to function:%s)\n",yylineno,(yyvsp[-2].expr)); 
			    printf("\033[0m"); 
      }

      if(IsFunctionLocal(0,(yyvsp[-2].expr)->sym->name,yylineno)==1&&lock2==1&&lock1!=1){
          printf("\033[0;31m");
			    printf("Error(%d)	[Variable] (Assignation(local) to function:%s)\n",yylineno,(yyvsp[-2].expr)); 
			    printf("\033[0m"); 
      }

     }
  
      if((yyvsp[0].expr)!=NULL){
            if((yyvsp[0].expr)->trueList!=0&&(yyvsp[0].expr)->falseList!=0&&lockA==0){
                Merikh_Assign((yyvsp[0].expr));
                lock=1;
            }

            lockA=0;

            if((yyvsp[-2].expr)->type==1){
             
                emit(tablesetelem,(yyvsp[-2].expr),(yyvsp[-2].expr)->index,(yyvsp[0].expr));

                 (yyval.expr) = emit_iftableitem ((yyvsp[-2].expr)); 
                 if((yyval.expr)!=NULL){
                     (yyval.expr)->type = assignexpr_e;
                 }else{
                     printf("[$assignexpr is NULL]\n");
                     (yyval.expr)=NULL;
                 }
            }else{
              
                emit(assign,(yyvsp[-2].expr),(yyvsp[0].expr),(expr*)0);
                (yyval.expr)=newexpr(assignexpr_e);
                if((yyval.expr)!=NULL){
                    (yyval.expr)->sym=newtmp();
                    emit(assign, (yyval.expr),(yyvsp[-2].expr),(expr*)0);
                }else{
                    printf("[$assignexpr is NULL]\n");
                    (yyval.expr)=NULL;
                }
            }
      }else{
              (yyval.expr)=NULL;
              printf("assignexpr:lvalue EQUAL_OP expr,[$expr is NULL]\n");
      }

    }else{
              (yyval.expr)=NULL;
              printf("assignexpr:lvalue EQUAL_OP expr,[$lvalue is NULL]\n");
    }
   
  
            lock1=0;
            lock2=0;
            printf("(%d)(assignexpr->lvalue=expr)\n",++pnum);}
#line 2440 "parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 850 "parserM.y" /* yacc.c:1646  */
    {
         (yyval.expr) = emit_iftableitem((yyvsp[0].expr));
         printf("(%d)(primary->lvalue)\n",++pnum);}
#line 2448 "parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 853 "parserM.y" /* yacc.c:1646  */
    {
         (yyval.expr)=(yyvsp[0].expr);
         printf("(%d)(primary->call)\n",++pnum);}
#line 2456 "parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 856 "parserM.y" /* yacc.c:1646  */
    {
         (yyval.expr)=(yyvsp[0].expr);
         printf("(%d)(primary->objectdef)\n",++pnum);}
#line 2464 "parser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 859 "parserM.y" /* yacc.c:1646  */
    {
         (yyval.expr) = newexpr(programfunc_e);
         (yyval.expr)->sym = (yyvsp[-1].sym);
         printf("(%d)(primary->(funcdef) )\n",++pnum);}
#line 2473 "parser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 863 "parserM.y" /* yacc.c:1646  */
    {
         (yyval.expr)=(yyvsp[0].expr);
         printf("(%d)(primary->const)\n",++pnum);}
#line 2481 "parser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 868 "parserM.y" /* yacc.c:1646  */
    {SymbolTableEntry *sym=LookUpVariable(scope,(yyvsp[0].strVal),yylineno);
        
         if(sym!=NULL){
            (yyval.expr)=lvalue_expr(sym);
         }else{
            (yyval.expr)=NULL;
            printf("LookUpVariable returns NULL\n");
         }
          printf("(%d)(lvalue->ID:%s)\n",++pnum,(yyvsp[0].strVal));  
         
      }
#line 2497 "parser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 879 "parserM.y" /* yacc.c:1646  */
    {SymbolTableEntry *sym=LookUpLocal((yyvsp[0].strVal),scope,yylineno);
        if(sym!=NULL){
           (yyval.expr)=lvalue_expr(sym);
        }else{
           (yyval.expr)=NULL;
           printf("LookUpLocal returns NULL\n");
        }
       
        lock1=1;
		  printf("(%d)(lvalue->local ID)\n",++pnum);}
#line 2512 "parser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 889 "parserM.y" /* yacc.c:1646  */
    {SymbolTableEntry *sym=LookUpGlobal((yyvsp[0].strVal),yylineno);
        if(sym!=NULL){
           (yyval.expr)=lvalue_expr(sym);
        }else{
           (yyval.expr)=NULL;
           printf("LookUpGlobal returns NULL\n");
        }

        lock2=1;
        printf("(%d)(lvalue->:: ID)\n",++pnum);}
#line 2527 "parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 899 "parserM.y" /* yacc.c:1646  */
    {
        printf("(%d)(lvalue->member)\n",++pnum);}
#line 2534 "parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 904 "parserM.y" /* yacc.c:1646  */
    {
        
          (yyval.expr)= (yyvsp[0].expr);
         
          printf("(%d)(lvalue->tableitem)\n",++pnum);
          }
#line 2545 "parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 911 "parserM.y" /* yacc.c:1646  */
    {
         
           (yyval.expr) = member_item((yyvsp[-2].expr), (yyvsp[0].strVal));         

           printf("(%d)(tableitem->lvalue.ID)\n",++pnum);
         }
#line 2556 "parser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 919 "parserM.y" /* yacc.c:1646  */
    {
            if((yyvsp[-3].expr)!=NULL){
                (yyvsp[-3].expr) = emit_iftableitem((yyvsp[-3].expr));
                (yyval.expr) = newexpr(tableitem_e); 
                if( (yyval.expr)!=NULL && (yyvsp[-1].expr)!=NULL){
                 (yyval.expr)->sym = (yyvsp[-3].expr)->sym;
                 (yyval.expr)->index = (yyvsp[-1].expr);
                }else{
                  printf("$tableitem is NULL \n");
                }
                
            }else{
              printf("member->lvalue[expr],[$lvalue is NULL]\n");
            }

            printf("(%d)(member->lvalue[expr])\n",++pnum);
          }
#line 2578 "parser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 944 "parserM.y" /* yacc.c:1646  */
    {printf("(%d)(member->call.ID)\n",++pnum);}
#line 2584 "parser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 945 "parserM.y" /* yacc.c:1646  */
    {printf("(%d)(member->call[expr])\n",++pnum);}
#line 2590 "parser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 948 "parserM.y" /* yacc.c:1646  */
    {
       (yyval.expr)=make_call((yyvsp[-3].expr),ReverseElist((yyvsp[-1].expr)));
       printf("(%d)(call->call(elist) )\n",++pnum);}
#line 2598 "parser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 951 "parserM.y" /* yacc.c:1646  */
    {

       (yyvsp[-1].expr) = emit_iftableitem((yyvsp[-1].expr));
       if((yyvsp[0].callx)!=NULL){
            if ((yyvsp[0].callx)->method ){
               expr* t = (yyvsp[-1].expr);
               (yyvsp[-1].expr) = emit_iftableitem(member_item(t, (yyvsp[0].callx)->name));
               if((yyvsp[0].callx)->elist!=NULL)  t->next=(yyvsp[0].callx)->elist;
               (yyvsp[0].callx)->elist= t; 
            }
               (yyval.expr) = make_call((yyvsp[-1].expr),ReverseElist((yyvsp[0].callx)->elist));
       }else{
               printf("Error.callsuffix is NULL in call:call(elist)\n");
               (yyval.expr)=NULL;
       }
       printf("(%d)(call->lvalue callsuffix)\n",++pnum);}
#line 2619 "parser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 968 "parserM.y" /* yacc.c:1646  */
    {
       expr* func = newexpr(programfunc_e);
       if((yyvsp[-4].sym)!=NULL)   func->sym = (yyvsp[-4].sym);
       (yyval.expr) = make_call(func,ReverseElist((yyvsp[-1].expr)));
       printf("(%d)(call->(funcdef)(elist) )\n",++pnum);}
#line 2629 "parser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 975 "parserM.y" /* yacc.c:1646  */
    {(yyval.callx)=(yyvsp[0].callx); printf("(%d)(callsuffix->normcall)\n",++pnum);}
#line 2635 "parser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 976 "parserM.y" /* yacc.c:1646  */
    {(yyval.callx)=(yyvsp[0].callx); printf("(%d)(callsuffix->methodcall)\n",++pnum);}
#line 2641 "parser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 979 "parserM.y" /* yacc.c:1646  */
    {
         callx *ptrX=(callx*)malloc(sizeof(callx));
         if(ptrX!=NULL){
            ptrX->elist = (yyvsp[-1].expr);
            ptrX->method = 0;
            ptrX->name = NULL;
            (yyval.callx)=ptrX;
         }else{
            printf("ptrX is NULL in normcall:(elist)\n");
            (yyval.callx)=NULL;
         }
         printf("(%d)(normcall->(elist) )\n",++pnum);}
#line 2658 "parser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 993 "parserM.y" /* yacc.c:1646  */
    {
            callx *ptrX=(callx*)malloc(sizeof(callx));
            if(ptrX!=NULL){
                  ptrX->elist = (yyvsp[-1].expr);
                  ptrX->method = 1;
                  ptrX->name = strdup((yyvsp[-3].strVal));
                  (yyval.callx)=ptrX;
            }else{
                  printf("ptrX is NULL in normcall:(elist)\n");
                  (yyval.callx)=NULL;
            }
            printf("(%d)(methodcall->..id(elist) )\n",++pnum);}
#line 2675 "parser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1006 "parserM.y" /* yacc.c:1646  */
    {

                if((yyvsp[0].expr)->trueList!=0&&(yyvsp[0].expr)->falseList!=0){
                 Merikh_Assign((yyvsp[0].expr));
                 lockA=1;
                 lock=1;
               }

               flagElist=0;
               elistptr++;
               if((yyvsp[0].expr)!=NULL){                 
                  TableforlistHead[elistptr]=(yyvsp[0].expr);
                  (yyvsp[0].expr)->next=NULL;
               }else{
                  printf("$expr is NULL in elist:expr \n");
                  flagElist=1;
               } 
      }
#line 2698 "parser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1023 "parserM.y" /* yacc.c:1646  */
    {
               if(flagElist==0){ (yyval.expr)=TableforlistHead[elistptr];
               }else { (yyval.expr)=NULL;}
            
                   elistptr--;

               printf("(%d)(elist->expr exprs)\n",++pnum);}
#line 2710 "parser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1030 "parserM.y" /* yacc.c:1646  */
    {       (yyval.expr)=NULL;  printf("(%d)(elist->  )\n",++pnum);}
#line 2716 "parser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1033 "parserM.y" /* yacc.c:1646  */
    {
       if(flagElist==0)
       {       
               if((yyvsp[0].expr)->trueList!=0&&(yyvsp[0].expr)->falseList!=0){
                 Merikh_Assign((yyvsp[0].expr));
                 lockA=1;
                 lock=1;
               }
               ptrElist=TableforlistHead[elistptr];
               while(ptrElist->next!=NULL){
                   ptrElist=ptrElist->next;
               }
         
               if((yyvsp[0].expr)!=NULL){
                   ptrElist->next=(yyvsp[0].expr);
                   (yyvsp[0].expr)->next=NULL;
               }else{
                   flagElist=1;
               }
       }
         
      }
#line 2743 "parser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1054 "parserM.y" /* yacc.c:1646  */
    {printf("(%d)(exprs->COMMA expr epxrs) \n",++pnum); }
#line 2749 "parser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1055 "parserM.y" /* yacc.c:1646  */
    {printf("(%d)(exprs->   )\n",++pnum);}
#line 2755 "parser.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1058 "parserM.y" /* yacc.c:1646  */
    {
           
            printElist((yyvsp[-1].expr));
            expr *t=newexpr(newtable_e);
            t->sym=newtmp();
            emit(tablecreate,t,NULL,NULL);
            int i=0;
            expr *curr=(yyvsp[-1].expr);
            while(curr!=NULL){
               emit(tablesetelem,t,newexpr_num_int(i),curr);
               i++;
               curr=curr->next;
            }
            (yyval.expr)=t;
            printf("(%d)(objectdef->[elist])\n",++pnum);}
#line 2775 "parser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1073 "parserM.y" /* yacc.c:1646  */
    {
            expr *t=newexpr(newtable_e);
            t->sym=newtmp();
            emit(tablecreate,t,NULL,NULL);
            indext *curr=(yyvsp[-1].indext);
            while(curr!=NULL){
               emit(tablesetelem,t,curr->index,curr->value);
               curr=curr->next;
            }
            (yyval.expr)=t;
            printf("(%d)(objectdef->[indexed])\n",++pnum);}
#line 2791 "parser.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1085 "parserM.y" /* yacc.c:1646  */
    {
             printf("OZUNA\n");
            (yyvsp[-1].indext)->next=(yyvsp[0].indext);
             printf("FARR\n");
            (yyval.indext)=(yyvsp[-1].indext);
             printf("J BALVIN\n");
           
            printTableindex((yyval.indext));
            printf("(%d)(indexed->indexedelem indexedelems)\n",++pnum);}
#line 2805 "parser.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1098 "parserM.y" /* yacc.c:1646  */
    {
               (yyvsp[-1].indext)->next=(yyvsp[0].indext);
               (yyval.indext)=(yyvsp[-1].indext);
               
               printf("(%d)(indexedelems-> ,indexedelem indexedelems)\n",++pnum);}
#line 2815 "parser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1103 "parserM.y" /* yacc.c:1646  */
    { (yyval.indext)=NULL; printf("(%d)(indexedelems->  )\n",++pnum);}
#line 2821 "parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1106 "parserM.y" /* yacc.c:1646  */
    {
               indext *ptr=(indext *)malloc(sizeof(indext));
               ptr->index=(yyvsp[-3].expr);
               ptr->value=(yyvsp[-1].expr);
               (yyval.indext)=ptr;
               printf("(%d)(indexedelem ->{ expr : expr })\n",++pnum);}
#line 2832 "parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1113 "parserM.y" /* yacc.c:1646  */
    { ++scope;}
#line 2838 "parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1113 "parserM.y" /* yacc.c:1646  */
    {Hide(scope--); (yyval.stmt_t)=(yyvsp[-1].stmt_t); printf("(%d)(block->{stmts})\n",++pnum);}
#line 2844 "parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1116 "parserM.y" /* yacc.c:1646  */
    { push(loopcounterstack, loopcounter); loopcounter=0; }
#line 2850 "parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1118 "parserM.y" /* yacc.c:1646  */
    { loopcounter = pop(loopcounterstack); }
#line 2856 "parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1120 "parserM.y" /* yacc.c:1646  */
    {
   (yyval.un)=currentscopeoffset();
   exitscopespace();
   if((yyvsp[-1].stmt_t)!=NULL){
       patchlist((yyvsp[-1].stmt_t)->returnList, nextquadlabel());
   }
   printf("(%d)(funcbody->block )\n",++pnum);
}
#line 2869 "parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1130 "parserM.y" /* yacc.c:1646  */
    {++scope; }
#line 2875 "parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1131 "parserM.y" /* yacc.c:1646  */
    {
  scope--;
  enterscopespace();
  resetfunctionLocaloffset();
  printf("(%d)(funcargs->LEFT_PARENTHESIS idlist RIGHT_PARENTHESIS)\n",++pnum);
}
#line 2886 "parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1139 "parserM.y" /* yacc.c:1646  */
    {
   (yyval.strVal)=(yyvsp[0].strVal);
  
   printf("(%d)(funcname->ID )\n",++pnum);
}
#line 2896 "parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1146 "parserM.y" /* yacc.c:1646  */
    {
   (yyval.strVal)=MakeFunctionName(namef++);
   printf("(%d)(funcname-> )\n",++pnum);
}
#line 2905 "parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1152 "parserM.y" /* yacc.c:1646  */
    {
    (yyval.sym)=LookUpFunction(scope,(yyvsp[0].strVal),yylineno);
    
    if( (yyval.sym)!=NULL){
        (yyval.sym)->iadress = nextquadlabel();
        emit(funcstart,function_def((yyval.sym)), NULL, NULL); 
    }else{
      printf("LookUpFunction returns NULL\n");
    }
    push(scopeoffsetstack,currentscopeoffset());
    enterscopespace();
    resetformalArgoffset();
    funcounter++;
    printf("(%d)(funcprefix->FUNC_ST funcname )\n",++pnum);
}
#line 2925 "parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1170 "parserM.y" /* yacc.c:1646  */
    {
     
     exitscopespace();
   
     SymbolTableEntry *ptr=(SymbolTableEntry*)malloc(sizeof(SymbolTableEntry));
     (yyval.sym)=ptr;
     

     int offset = pop(scopeoffsetstack);
     restorecurrscopeoffset(offset); 
     if((yyvsp[-2].sym)!=NULL){
          (yyval.sym)=(yyvsp[-2].sym);
          (yyval.sym)->totalLocals=(yyvsp[0].un);
   
     }else{
          (yyval.sym)=NULL;
       printf("$funcprefix is NULL in :funcdef:funcprefix funcargs funcbody\n");
     }
    
     
     emit(funcend,function_def((yyvsp[-2].sym)), NULL, NULL);
     patchlabel((yyvsp[-3].intVal),nextquadlabel());
     funcounter--;
     printf("(%d)(funcdef->funcprefix funcargs funcbody )\n",++pnum);
}
#line 2955 "parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1198 "parserM.y" /* yacc.c:1646  */
    {
      (yyval.expr)=newexpr_num_int((yyvsp[0].intVal));
      printf("(%d)(const->NUMBER_INT)\n",++pnum);}
#line 2963 "parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1201 "parserM.y" /* yacc.c:1646  */
    {
      (yyval.expr)=newexpr_num_double((yyvsp[0].doubleVal));
      printf("(%d)(const->NUMBER_REAL)\n",++pnum);}
#line 2971 "parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1204 "parserM.y" /* yacc.c:1646  */
    {
       (yyval.expr)=newexpr_string((yyvsp[0].strVal));
       printf("(%d)(const->STRING)\n",++pnum);}
#line 2979 "parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1207 "parserM.y" /* yacc.c:1646  */
    {
        (yyval.expr)=newexpr_bool(1);
        printf("(%d)(const->TRUE)\n",++pnum);}
#line 2987 "parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1210 "parserM.y" /* yacc.c:1646  */
    {
        (yyval.expr)=newexpr_bool(0);
        printf("(%d)(const->FALSE)\n",++pnum);}
#line 2995 "parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1213 "parserM.y" /* yacc.c:1646  */
    {
        (yyval.expr)=newexpr(nil_e);
        printf("(%d)(const->NIL)\n",++pnum);}
#line 3003 "parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1217 "parserM.y" /* yacc.c:1646  */
    {LookUpFormal((yyvsp[0].strVal) ,yylineno,scope);}
#line 3009 "parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1217 "parserM.y" /* yacc.c:1646  */
    {printf("(%d)(idlist->ID IDS)\n",++pnum);}
#line 3015 "parser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1218 "parserM.y" /* yacc.c:1646  */
    {printf("(%d)(idlist-> )\n",++pnum);}
#line 3021 "parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1221 "parserM.y" /* yacc.c:1646  */
    {LookUpFormal((yyvsp[0].strVal) ,yylineno,scope);}
#line 3027 "parser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1221 "parserM.y" /* yacc.c:1646  */
    {printf("(%d)(IDS->COMMA ID IDS)\n",++pnum);}
#line 3033 "parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1222 "parserM.y" /* yacc.c:1646  */
    {printf("(%d)(IDS-> )\n",++pnum);}
#line 3039 "parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1226 "parserM.y" /* yacc.c:1646  */
    {
       
        emit(jump, NULL, NULL, NULL);
        (yyval.intVal) = currquad();
}
#line 3049 "parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1232 "parserM.y" /* yacc.c:1646  */
    {

            if((yyvsp[-1].expr)->trueList!=0&&(yyvsp[-1].expr)->falseList!=0){
                 Merikh_Assign((yyvsp[-1].expr));
                 lockA=1;
                 lock=1;
             }
            emit(if_eq,NULL,(yyvsp[-1].expr),newexpr_bool(1));
            
            quads[currquad()].label=currquad()+2;
            emit(jump, NULL, NULL, NULL);
            (yyval.intVal) = currquad();
            printf("(%d)(ifprefix->if(expr)\n",++pnum);
        }
#line 3068 "parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1247 "parserM.y" /* yacc.c:1646  */
    {patchlabel((yyvsp[-1].intVal),nextquadlabel()); printf("(%d)(ifstmt->ifprefix stmt )\n",++pnum);}
#line 3074 "parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1249 "parserM.y" /* yacc.c:1646  */
    {
         patchlabel((yyvsp[-3].intVal), (yyvsp[-1].intVal) + 1);
         patchlabel((yyvsp[-1].intVal), nextquadlabel());
         printf("(%d)(ifstmt2->if ifprefix stmt elseprefix stmt ) \n",++pnum);}
#line 3083 "parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1255 "parserM.y" /* yacc.c:1646  */
    { ++loopcounter; }
#line 3089 "parser.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1258 "parserM.y" /* yacc.c:1646  */
    { --loopcounter; }
#line 3095 "parser.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1261 "parserM.y" /* yacc.c:1646  */
    { (yyval.stmt_t) = (yyvsp[-1].stmt_t);
             printf("(%d)(loopstmt->loopstart stmt loopend )\n",++pnum);
          }
#line 3103 "parser.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1267 "parserM.y" /* yacc.c:1646  */
    {
            (yyval.intVal) = nextquadlabel();
            printf("(%d)(whilestart->WHILE_ST)\n",++pnum);
          }
#line 3112 "parser.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1274 "parserM.y" /* yacc.c:1646  */
    {
             if((yyvsp[-1].expr)->trueList!=0&&(yyvsp[-1].expr)->falseList!=0){
                 Merikh_Assign((yyvsp[-1].expr));
                 lockA=1;
                 lock=1;
             }
             emit(if_eq,NULL,(yyvsp[-1].expr),newexpr_bool(1));
             quads[currquad()].label=currquad()+2;
             emit(jump, NULL, NULL,NULL);
             (yyval.intVal) = currquad();
             printf("(%d)(whilecond->(expr) stmt)\n",++pnum);
         }
#line 3129 "parser.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1289 "parserM.y" /* yacc.c:1646  */
    {
             emit(jump, NULL, NULL, NULL);
             quads[currquad()].label=(yyvsp[-2].intVal);
             patchlabel((yyvsp[-1].intVal), nextquadlabel());
             if((yyvsp[0].stmt_t)!=NULL){
                Printpatchlist ((yyvsp[0].stmt_t)->breakList);
                Printpatchlist ((yyvsp[0].stmt_t)->contList);
                patchlist((yyvsp[0].stmt_t)->breakList, nextquadlabel());
                patchlist((yyvsp[0].stmt_t)->contList, (yyvsp[-2].intVal));
             }
             printf("(%d)(whilestart->whilecond whilecond loopstmt)\n",++pnum);
        }
#line 3146 "parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1307 "parserM.y" /* yacc.c:1646  */
    { (yyval.intVal) = nextquadlabel(); emit(jump,NULL,NULL,NULL); }
#line 3152 "parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1310 "parserM.y" /* yacc.c:1646  */
    { (yyval.intVal) = nextquadlabel(); }
#line 3158 "parser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1314 "parserM.y" /* yacc.c:1646  */
    {
             if((yyvsp[-1].expr)->trueList!=0&&(yyvsp[-1].expr)->falseList!=0){
                 Merikh_Assign((yyvsp[-1].expr));
                 lockA=1;
                 lock=1;
             }
            forpre *ptr=(forpre*)malloc(sizeof(forpre));
            ptr->test = (yyvsp[-2].intVal);
            ptr->enter = nextquadlabel();
            (yyval.forpre)=ptr;
            emit(if_eq,NULL,(yyvsp[-1].expr),newexpr_bool(1));
          }
#line 3175 "parser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1329 "parserM.y" /* yacc.c:1646  */
    {
            patchlabel((yyvsp[-6].forpre)->enter,(yyvsp[-2].intVal)+1); 
            patchlabel((yyvsp[-5].intVal), nextquadlabel()); 
            patchlabel((yyvsp[-2].intVal), (yyvsp[-6].forpre)->test);
            patchlabel((yyvsp[0].intVal), (yyvsp[-5].intVal)+1);
             if((yyvsp[-1].stmt_t)!=NULL){
                Printpatchlist ((yyvsp[-1].stmt_t)->breakList);
                Printpatchlist ((yyvsp[-1].stmt_t)->contList);
                patchlist((yyvsp[-1].stmt_t)->breakList, nextquadlabel());
                patchlist((yyvsp[-1].stmt_t)->contList, (yyvsp[-5].intVal)+1);
             }
          }
#line 3192 "parser.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1347 "parserM.y" /* yacc.c:1646  */
    {
            printf("FUNCCOUNTER:%d\n",funcounter);
            if(funcounter>0){
                emit(ret,NULL,NULL,NULL);
                (yyval.stmt_t)=make_stmt( );
                (yyval.stmt_t)->returnList=newlist(nextquadlabel());
                emit(jump,NULL,NULL,NULL);
            }else{
                printf("\033[0;31m");
		      	 printf("Error(%d)	[Return not in function] \n",yylineno); 
		          printf("\033[0m");
                (yyval.stmt_t)=NULL;
            }
            
            printf("(%d)(returnstmt->return ;)\n",++pnum);}
#line 3212 "parser.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1362 "parserM.y" /* yacc.c:1646  */
    {
            printf("FUNCCOUNTER:%d\n",funcounter);
            if(funcounter>0){
                emit(ret,(yyvsp[-1].expr),NULL,NULL);
                (yyval.stmt_t)=make_stmt( );
                (yyval.stmt_t)->returnList=newlist(nextquadlabel());
                emit(jump,NULL,NULL,NULL);
            }else{
                printf("\033[0;31m");
		      	 printf("Error(%d)	[Return not in function] \n",yylineno); 
		          printf("\033[0m");
                (yyval.stmt_t)=NULL;
            }          
            printf("(%d)(returnstmt->return expr;)\n",++pnum);}
#line 3231 "parser.c" /* yacc.c:1646  */
    break;


#line 3235 "parser.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1380 "parserM.y" /* yacc.c:1906  */


int yyerror (char* yaccProvidedMessage)
{
        fprintf(stderr, "%s: at line %d, before token: '%s'\n", yaccProvidedMessage, yylineno, yytext);
}



int main(int argc,char** argv)
{
  if(argc>1){
   if(!(yyin=fopen(argv[1],"r"))){  
      fprintf(stderr,"Cannot read file:%s\n",argv[1]);
      return 1;
   }
  }else{
    yyin=stdin;
  }

    printf("--------------------            Syntax Analysis         --------------------\n");
    InitHash();
    scopeoffsetstack=createStack(1000);
    loopcounterstack=createStack(1000);
    emit(start,NULL,NULL,NULL);
    yyparse();
   // display();
  //  MakeQuadTable();
   // SymbolTableEntry *a=newtmp();
   // SymbolTableEntry *a2=newtmp();
    PrintScopes();
     PrintQuads();
    return 0;
}





