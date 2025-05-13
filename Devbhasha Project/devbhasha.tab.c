
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "devbhasha.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern int line_num;
extern FILE* yyin;

void yyerror(const char* s);

/* Three-address code generation utilities */
int temp_var_counter = 0;
int label_counter = 0;

/* Define ExpressionResult structure first */
typedef struct ExpressionResult {
    char* code;
    char* addr;
    char* true_label;
    char* false_label;
} ExpressionResult;

char* new_temp() {
    char* temp = (char*)malloc(16);
    sprintf(temp, "t%d", temp_var_counter++);
    return temp;
}

char* new_label() {
    char* label = (char*)malloc(16);
    sprintf(label, "L%d", label_counter++);
    return label;
}

ExpressionResult* create_expr_result() {
    ExpressionResult* result = (ExpressionResult*)malloc(sizeof(ExpressionResult));
    result->code = strdup("");
    result->addr = NULL;
    result->true_label = NULL;
    result->false_label = NULL;
    return result;
}

void append_code(ExpressionResult* result, const char* code) {
    char* new_code = (char*)malloc(strlen(result->code) + strlen(code) + 1);
    strcpy(new_code, result->code);
    strcat(new_code, code);
    free(result->code);
    result->code = new_code;
}



/* Line 189 of yacc.c  */
#line 128 "devbhasha.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     LOWER_THAN_ELSE = 258,
     ELSE = 259,
     MOD_ASSIGN = 260,
     DIVIDE_ASSIGN = 261,
     TIMES_ASSIGN = 262,
     MINUS_ASSIGN = 263,
     PLUS_ASSIGN = 264,
     ASSIGN = 265,
     OR = 266,
     AND = 267,
     NEQ = 268,
     EQ = 269,
     GTE = 270,
     LTE = 271,
     GT = 272,
     LT = 273,
     MINUS = 274,
     PLUS = 275,
     MOD = 276,
     DIVIDE = 277,
     TIMES = 278,
     NOT = 279,
     DECREMENT = 280,
     INCREMENT = 281,
     PROGRAM = 282,
     END = 283,
     VAR = 284,
     CONST = 285,
     RETURN = 286,
     NEW = 287,
     BOOL = 288,
     INT = 289,
     FLOAT = 290,
     CHAR = 291,
     STRING = 292,
     NULL_TYPE = 293,
     MAP = 294,
     IF = 295,
     ELSE_IF = 296,
     FOR = 297,
     WHILE = 298,
     DO = 299,
     BREAK = 300,
     CONTINUE = 301,
     FUNCTION = 302,
     CLASS = 303,
     CONSTRUCTOR = 304,
     EXTENDS = 305,
     READ = 306,
     PRINT = 307,
     TRY = 308,
     CATCH = 309,
     FINALLY = 310,
     THROW = 311,
     THIS = 312,
     SUPER = 313,
     LPAREN = 314,
     RPAREN = 315,
     LBRACE = 316,
     RBRACE = 317,
     LBRACKET = 318,
     RBRACKET = 319,
     SEMICOLON = 320,
     COMMA = 321,
     DOT = 322,
     COLON = 323,
     INT_LITERAL = 324,
     FLOAT_LITERAL = 325,
     CHAR_LITERAL = 326,
     STRING_LITERAL = 327,
     BOOL_LITERAL = 328,
     IDENTIFIER = 329
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 55 "devbhasha.y"

    int ival;
    float fval;
    char cval;
    char* sval;
    int bval;
    struct ExpressionResult* expr;



/* Line 214 of yacc.c  */
#line 249 "devbhasha.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 261 "devbhasha.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  20
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   423

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNRULES -- Number of states.  */
#define YYNSTATES  207

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   329

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    14,    21,    23,
      26,    29,    32,    35,    37,    39,    41,    44,    46,    49,
      52,    55,    58,    60,    64,    67,    71,    77,    83,    85,
      87,    89,    91,    93,    95,    97,    99,   101,   105,   112,
     116,   120,   124,   128,   132,   136,   138,   140,   144,   146,
     150,   152,   156,   160,   162,   166,   170,   174,   178,   180,
     184,   188,   192,   196,   198,   202,   206,   210,   212,   215,
     218,   220,   223,   226,   228,   230,   232,   234,   236,   238,
     242,   244,   250,   258,   264,   272,   282,   292,   301,   309,
     316,   318,   322,   325,   329,   334,   336,   340,   343,   345
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      76,     0,    -1,    77,    -1,    78,    -1,    79,    -1,   102,
      -1,    78,   102,    -1,    27,    74,    61,    80,    62,    28,
      -1,    81,    -1,    80,    81,    -1,    83,    65,    -1,    88,
      65,    -1,    89,    65,    -1,    99,    -1,   100,    -1,   101,
      -1,   105,    65,    -1,    82,    -1,   107,    65,    -1,   108,
      65,    -1,    45,    65,    -1,    46,    65,    -1,    65,    -1,
      61,    80,    62,    -1,    61,    62,    -1,    29,    84,    74,
      -1,    29,    84,    74,    10,    89,    -1,    30,    84,    74,
      10,    89,    -1,    85,    -1,    86,    -1,    87,    -1,    33,
      -1,    34,    -1,    35,    -1,    36,    -1,    37,    -1,    38,
      -1,    85,    63,    64,    -1,    39,    18,    84,    66,    84,
      17,    -1,    74,    10,    89,    -1,    74,     9,    89,    -1,
      74,     8,    89,    -1,    74,     7,    89,    -1,    74,     6,
      89,    -1,    74,     5,    89,    -1,    90,    -1,    91,    -1,
      90,    11,    91,    -1,    92,    -1,    91,    12,    92,    -1,
      93,    -1,    92,    14,    93,    -1,    92,    13,    93,    -1,
      94,    -1,    93,    18,    94,    -1,    93,    17,    94,    -1,
      93,    16,    94,    -1,    93,    15,    94,    -1,    95,    -1,
      94,    20,    95,    -1,    94,    19,    95,    -1,    72,    20,
      89,    -1,    89,    20,    72,    -1,    96,    -1,    95,    23,
      96,    -1,    95,    22,    96,    -1,    95,    21,    96,    -1,
      97,    -1,    24,    96,    -1,    19,    96,    -1,    98,    -1,
      74,    26,    -1,    74,    25,    -1,    74,    -1,    69,    -1,
      70,    -1,    71,    -1,    72,    -1,    73,    -1,    59,    89,
      60,    -1,   105,    -1,    40,    59,    89,    60,    82,    -1,
      40,    59,    89,    60,    82,     4,    82,    -1,    43,    59,
      89,    60,    82,    -1,    44,    82,    43,    59,    89,    60,
      65,    -1,    42,    59,    83,    65,    89,    65,    88,    60,
      82,    -1,    42,    59,    88,    65,    89,    65,    88,    60,
      82,    -1,    42,    59,    65,    89,    65,    88,    60,    82,
      -1,    47,    84,    74,    59,   103,    60,    82,    -1,    47,
      84,    74,    59,    60,    82,    -1,   104,    -1,   103,    66,
     104,    -1,    84,    74,    -1,    74,    59,    60,    -1,    74,
      59,   106,    60,    -1,    89,    -1,   106,    66,    89,    -1,
      31,    89,    -1,    31,    -1,    52,    59,    89,    60,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   120,   120,   124,   131,   135,   139,   147,   156,   160,
     168,   172,   176,   180,   184,   188,   192,   196,   200,   204,
     208,   213,   218,   225,   229,   236,   243,   250,   260,   264,
     268,   275,   279,   283,   287,   291,   295,   302,   309,   316,
     323,   333,   343,   353,   363,   376,   383,   387,   400,   404,
     417,   421,   431,   444,   448,   458,   468,   478,   491,   495,
     505,   515,   524,   536,   540,   550,   560,   573,   577,   586,
     598,   602,   610,   621,   626,   632,   638,   644,   649,   654,
     658,   665,   683,   710,   732,   755,   780,   805,   831,   842,
     856,   860,   867,   874,   884,   897,   902,   910,   918,   926
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LOWER_THAN_ELSE", "ELSE", "MOD_ASSIGN",
  "DIVIDE_ASSIGN", "TIMES_ASSIGN", "MINUS_ASSIGN", "PLUS_ASSIGN", "ASSIGN",
  "OR", "AND", "NEQ", "EQ", "GTE", "LTE", "GT", "LT", "MINUS", "PLUS",
  "MOD", "DIVIDE", "TIMES", "NOT", "DECREMENT", "INCREMENT", "PROGRAM",
  "END", "VAR", "CONST", "RETURN", "NEW", "BOOL", "INT", "FLOAT", "CHAR",
  "STRING", "NULL_TYPE", "MAP", "IF", "ELSE_IF", "FOR", "WHILE", "DO",
  "BREAK", "CONTINUE", "FUNCTION", "CLASS", "CONSTRUCTOR", "EXTENDS",
  "READ", "PRINT", "TRY", "CATCH", "FINALLY", "THROW", "THIS", "SUPER",
  "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACKET", "RBRACKET",
  "SEMICOLON", "COMMA", "DOT", "COLON", "INT_LITERAL", "FLOAT_LITERAL",
  "CHAR_LITERAL", "STRING_LITERAL", "BOOL_LITERAL", "IDENTIFIER",
  "$accept", "program_start", "program", "program_body",
  "program_declaration", "statement_list", "statement", "block_statement",
  "variable_declaration", "type", "basic_type", "array_type", "map_type",
  "assignment_expression", "expression", "logical_or_expression",
  "logical_and_expression", "equality_expression", "relational_expression",
  "additive_expression", "multiplicative_expression", "unary_expression",
  "postfix_expression", "primary_expression", "if_statement",
  "while_statement", "for_statement", "function_declaration",
  "parameter_list", "parameter", "function_call", "argument_list",
  "return_statement", "print_statement", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    75,    76,    77,    78,    78,    78,    79,    80,    80,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    82,    82,    83,    83,    83,    84,    84,
      84,    85,    85,    85,    85,    85,    85,    86,    87,    88,
      88,    88,    88,    88,    88,    89,    90,    90,    91,    91,
      92,    92,    92,    93,    93,    93,    93,    93,    94,    94,
      94,    94,    94,    95,    95,    95,    95,    96,    96,    96,
      97,    97,    97,    98,    98,    98,    98,    98,    98,    98,
      98,    99,    99,   100,   100,   101,   101,   101,   102,   102,
     103,   103,   104,   105,   105,   106,   106,   107,   107,   108
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     2,     6,     1,     2,
       2,     2,     2,     1,     1,     1,     2,     1,     2,     2,
       2,     2,     1,     3,     2,     3,     5,     5,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     6,     3,
       3,     3,     3,     3,     3,     1,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     3,     1,     2,     2,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     3,
       1,     5,     7,     5,     7,     9,     9,     8,     7,     6,
       1,     3,     2,     3,     4,     1,     3,     2,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     2,     3,     4,     5,     0,    31,
      32,    33,    34,    35,    36,     0,     0,    28,    29,    30,
       1,     6,     0,     0,     0,     0,     0,     0,     0,     0,
      98,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      22,    74,    75,    76,    77,    78,    73,     0,     8,    17,
       0,     0,     0,    45,    46,    48,    50,    53,    58,    63,
      67,    70,    13,    14,    15,    80,     0,     0,     0,     0,
      37,    77,    73,    69,    80,    68,     0,     0,    97,     0,
       0,     0,     0,    20,    21,     0,     0,    24,     0,     0,
       0,     0,     0,     0,     0,     0,    72,    71,     0,     0,
       9,    10,    11,     0,    12,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    16,    18,
      19,     0,     0,     0,     0,    90,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    79,    23,    61,    44,
      43,    42,    41,    40,    39,    93,    95,     0,     7,    62,
       0,    47,    49,    50,    50,    53,    53,    53,    53,    60,
      59,    66,    65,    64,     0,    89,    92,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    99,    94,     0,
      38,    88,    91,    26,    27,    81,     0,     0,     0,    83,
       0,    96,     0,     0,     0,     0,     0,    82,     0,     0,
       0,    84,    87,     0,     0,    85,    86
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,    47,    48,    49,    50,   123,
      17,    18,    19,    51,   150,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,     7,   124,   125,
      74,   147,    66,    67
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -80
static const yytype_int16 yypact[] =
{
       8,   -65,   191,    56,   -80,   -26,   -80,   -80,    42,   -80,
     -80,   -80,   -80,   -80,   -80,   105,    57,    -1,   -80,   -80,
     -80,   -80,   304,   191,    81,    78,   312,   312,   191,   191,
     321,   102,   104,   113,    84,    83,   106,   116,   321,   136,
     -80,   -80,   -80,   -80,   142,   -80,     7,   192,   -80,   -80,
     118,   120,    11,   166,   174,   112,   103,    18,    89,   -80,
     -80,   -80,   -80,   -80,   -80,   122,   131,   134,   137,   363,
     -80,   -80,    88,   -80,   -80,   -80,   128,   138,   184,   321,
      -7,   321,   170,   -80,   -80,   321,     0,   -80,   248,   321,
     321,   321,   321,   321,   321,   321,   -80,   -80,    27,   186,
     -80,   -80,   -80,   143,   -80,   321,   321,   321,   321,   321,
     321,   321,   321,   312,   312,   312,   312,   312,   -80,   -80,
     -80,   191,    84,   144,   -16,   -80,   207,   209,    25,   321,
     240,   155,   168,    44,   172,    72,   -80,   -80,   -80,   184,
     184,   184,   184,   184,   184,   -80,   184,   -12,   -80,   -80,
     184,    14,   180,    24,    64,   -13,    86,   108,   124,    89,
      89,   -80,   -80,   -80,   226,   -80,   -80,    84,   191,   321,
     321,    84,    37,   321,   321,    84,   321,   -80,   -80,   321,
     -80,   -80,   -80,   184,   184,   251,   178,    43,    71,   -80,
      97,   184,    84,   196,   178,   178,   193,   -80,    84,   199,
     200,   -80,   -80,    84,    84,   -80,   -80
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -80,   -80,   -80,   -80,   -80,   229,   -39,   -34,   189,     1,
     -80,   -80,   -80,   -79,   -20,   -80,   165,   167,    31,   130,
      21,   -22,   -80,   -80,   -80,   -80,   -80,   266,   -80,   107,
     -11,   -80,   -80,   -80
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -58
static const yytype_int16 yytable[] =
{
      82,   132,    52,    16,    73,    75,   113,   114,   100,     8,
      78,    65,    90,    91,    92,    93,    94,    95,    86,    52,
     103,     2,    28,    29,    68,   -46,   106,    52,    65,    76,
      77,   103,    96,    97,   -46,     1,    65,   113,   114,   109,
     110,   111,   112,   -52,   167,   103,    26,   -57,   178,   100,
     168,    27,   -57,   -57,   179,     2,    20,   103,   129,   128,
     136,   133,    25,   103,   103,   135,    98,   130,    52,   138,
     139,   140,   141,   142,   143,   144,   104,    65,   146,   109,
     110,   111,   112,   -51,   -52,   171,    38,   145,   165,   -52,
     -52,   103,   103,   161,   162,   163,    41,    42,    43,    44,
      45,    72,   186,    22,   175,   113,   114,   193,   194,   172,
     115,   116,   117,    96,    97,   199,   200,   103,   109,   110,
     111,   112,   164,    23,   -51,   107,   108,   113,   114,   -51,
     -51,    24,   177,   181,   159,   160,   195,   185,   153,   154,
      69,   189,    70,   113,   114,    39,   -56,    98,    83,   183,
     184,   -56,   -56,   187,   188,    26,   190,   196,   197,   191,
      27,    79,    89,    80,   202,    28,    29,    30,   -55,   205,
     206,    84,    81,   -55,   -55,    85,    31,   105,    32,    33,
      34,    35,    36,   101,   -54,   102,   106,   118,    37,   -54,
     -54,   -48,   -48,   107,   108,    38,   119,    39,    87,   120,
     -48,    40,   126,   121,   103,    41,    42,    43,    44,    45,
      46,    26,   127,   134,   148,   149,    27,   169,   166,   170,
     173,    28,    29,    30,     9,    10,    11,    12,    13,    14,
      15,   176,    31,   174,    32,    33,    34,    35,    36,   155,
     156,   157,   158,   180,    37,    90,    91,    92,    93,    94,
      95,    38,   130,    39,    99,   192,   198,    40,   201,   203,
     204,    41,    42,    43,    44,    45,    46,    26,    88,   131,
     151,    21,    27,   152,     0,   182,     0,    28,    29,    30,
       0,     0,     0,     0,     0,     0,     0,     0,    31,     0,
      32,    33,    34,    35,    36,     0,     0,     0,     0,     0,
      37,     0,     0,     0,     0,     0,     0,    38,     0,    39,
     137,     0,     0,    40,     0,     0,     0,    41,    42,    43,
      44,    45,    46,    26,     0,     0,     0,     0,    27,     0,
       0,    26,     0,    28,    29,    30,    27,     0,     0,     0,
      26,     0,     0,     0,    31,    27,    32,    33,    34,    35,
      36,     0,     0,     0,     0,     0,    37,     0,     0,     0,
       0,     0,     0,    38,     0,    39,     0,     0,     0,    40,
       0,    38,     0,    41,    42,    43,    44,    45,    46,     0,
      38,    41,    42,    43,    71,    45,    72,     0,     0,     0,
      41,    42,    43,    44,    45,    72,     9,    10,    11,    12,
      13,    14,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   122
};

static const yytype_int16 yycheck[] =
{
      34,    80,    22,     2,    26,    27,    19,    20,    47,    74,
      30,    22,     5,     6,     7,     8,     9,    10,    38,    39,
      20,    47,    29,    30,    23,    11,    12,    47,    39,    28,
      29,    20,    25,    26,    20,    27,    47,    19,    20,    15,
      16,    17,    18,    19,    60,    20,    19,    60,    60,    88,
      66,    24,    65,    66,    66,    47,     0,    20,    65,    79,
      60,    81,    63,    20,    20,    85,    59,    74,    88,    89,
      90,    91,    92,    93,    94,    95,    65,    88,    98,    15,
      16,    17,    18,    19,    60,    60,    59,    60,   122,    65,
      66,    20,    20,   115,   116,   117,    69,    70,    71,    72,
      73,    74,    65,    61,    60,    19,    20,   186,    65,   129,
      21,    22,    23,    25,    26,   194,   195,    20,    15,    16,
      17,    18,   121,    18,    60,    13,    14,    19,    20,    65,
      66,    74,    60,   167,   113,   114,    65,   171,   107,   108,
      59,   175,    64,    19,    20,    61,    60,    59,    65,   169,
     170,    65,    66,   173,   174,    19,   176,    60,   192,   179,
      24,    59,    20,    59,   198,    29,    30,    31,    60,   203,
     204,    65,    59,    65,    66,    59,    40,    11,    42,    43,
      44,    45,    46,    65,    60,    65,    12,    65,    52,    65,
      66,    11,    12,    13,    14,    59,    65,    61,    62,    65,
      20,    65,    74,    66,    20,    69,    70,    71,    72,    73,
      74,    19,    74,    43,    28,    72,    24,    10,    74,    10,
      65,    29,    30,    31,    33,    34,    35,    36,    37,    38,
      39,    59,    40,    65,    42,    43,    44,    45,    46,   109,
     110,   111,   112,    17,    52,     5,     6,     7,     8,     9,
      10,    59,    74,    61,    62,     4,    60,    65,    65,    60,
      60,    69,    70,    71,    72,    73,    74,    19,    39,    80,
     105,     5,    24,   106,    -1,   168,    -1,    29,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,
      42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,    61,
      62,    -1,    -1,    65,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    19,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    19,    -1,    29,    30,    31,    24,    -1,    -1,    -1,
      19,    -1,    -1,    -1,    40,    24,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    -1,    61,    -1,    -1,    -1,    65,
      -1,    59,    -1,    69,    70,    71,    72,    73,    74,    -1,
      59,    69,    70,    71,    72,    73,    74,    -1,    -1,    -1,
      69,    70,    71,    72,    73,    74,    33,    34,    35,    36,
      37,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    27,    47,    76,    77,    78,    79,   102,    74,    33,
      34,    35,    36,    37,    38,    39,    84,    85,    86,    87,
       0,   102,    61,    18,    74,    63,    19,    24,    29,    30,
      31,    40,    42,    43,    44,    45,    46,    52,    59,    61,
      65,    69,    70,    71,    72,    73,    74,    80,    81,    82,
      83,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   105,   107,   108,    84,    59,
      64,    72,    74,    96,   105,    96,    84,    84,    89,    59,
      59,    59,    82,    65,    65,    59,    89,    62,    80,    20,
       5,     6,     7,     8,     9,    10,    25,    26,    59,    62,
      81,    65,    65,    20,    65,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    65,    65,
      65,    66,    60,    84,   103,   104,    74,    74,    89,    65,
      74,    83,    88,    89,    43,    89,    60,    62,    89,    89,
      89,    89,    89,    89,    89,    60,    89,   106,    28,    72,
      89,    91,    92,    93,    93,    94,    94,    94,    94,    95,
      95,    96,    96,    96,    84,    82,    74,    60,    66,    10,
      10,    60,    89,    65,    65,    60,    59,    60,    60,    66,
      17,    82,   104,    89,    89,    82,    65,    89,    89,    82,
      89,    89,     4,    88,    65,    65,    60,    82,    60,    88,
      88,    65,    82,    60,    60,    82,    82
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:

/* Line 1455 of yacc.c  */
#line 125 "devbhasha.y"
    {
        /* Complete program */
    ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 132 "devbhasha.y"
    {
        (yyval.expr) = (yyvsp[(1) - (1)].expr);
    ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 136 "devbhasha.y"
    {
        (yyval.expr) = (yyvsp[(1) - (1)].expr);
    ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 140 "devbhasha.y"
    {
        (yyval.expr) = (yyvsp[(1) - (2)].expr);
        append_code((yyval.expr), (yyvsp[(2) - (2)].expr)->code);
    ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 148 "devbhasha.y"
    {
        (yyval.expr) = (yyvsp[(4) - (6)].expr);
        printf("// Three-address code for Devbhasha program '%s'\n", (yyvsp[(2) - (6)].sval));
        printf("%s", (yyvsp[(4) - (6)].expr)->code);
    ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 157 "devbhasha.y"
    {
        (yyval.expr) = (yyvsp[(1) - (1)].expr);
    ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 161 "devbhasha.y"
    {
        (yyval.expr) = (yyvsp[(1) - (2)].expr);
        append_code((yyval.expr), (yyvsp[(2) - (2)].expr)->code);
    ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 169 "devbhasha.y"
    {
        (yyval.expr) = (yyvsp[(1) - (2)].expr);
    ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 173 "devbhasha.y"
    {
        (yyval.expr) = (yyvsp[(1) - (2)].expr);
    ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 177 "devbhasha.y"
    {
        (yyval.expr) = (yyvsp[(1) - (2)].expr);
    ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 181 "devbhasha.y"
    {
        (yyval.expr) = (yyvsp[(1) - (1)].expr);
    ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 185 "devbhasha.y"
    {
        (yyval.expr) = (yyvsp[(1) - (1)].expr);
    ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 189 "devbhasha.y"
    {
        (yyval.expr) = (yyvsp[(1) - (1)].expr);
    ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 193 "devbhasha.y"
    {
        (yyval.expr) = (yyvsp[(1) - (2)].expr);
    ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 197 "devbhasha.y"
    {
        (yyval.expr) = (yyvsp[(1) - (1)].expr);
    ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 201 "devbhasha.y"
    {
        (yyval.expr) = (yyvsp[(1) - (2)].expr);
    ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 205 "devbhasha.y"
    {
        (yyval.expr) = (yyvsp[(1) - (2)].expr);
    ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 209 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        append_code((yyval.expr), "break\n");
    ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 214 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        append_code((yyval.expr), "continue\n");
    ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 219 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
    ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 226 "devbhasha.y"
    {
        (yyval.expr) = (yyvsp[(2) - (3)].expr);
    ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 230 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
    ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 237 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        char code[128];
        sprintf(code, "// Declaration: %s\n", (yyvsp[(3) - (3)].sval));
        append_code((yyval.expr), code);
    ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 244 "devbhasha.y"
    {
        (yyval.expr) = (yyvsp[(5) - (5)].expr);
        char code[128];
        sprintf(code, "%s = %s\n", (yyvsp[(3) - (5)].sval), (yyvsp[(5) - (5)].expr)->addr);
        append_code((yyval.expr), code);
    ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 251 "devbhasha.y"
    {
        (yyval.expr) = (yyvsp[(5) - (5)].expr);
        char code[128];
        sprintf(code, "// Constant declaration\n%s = %s\n", (yyvsp[(3) - (5)].sval), (yyvsp[(5) - (5)].expr)->addr);
        append_code((yyval.expr), code);
    ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 261 "devbhasha.y"
    {
        (yyval.expr) = (yyvsp[(1) - (1)].expr);
    ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 265 "devbhasha.y"
    {
        (yyval.expr) = (yyvsp[(1) - (1)].expr);
    ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 269 "devbhasha.y"
    {
        (yyval.expr) = (yyvsp[(1) - (1)].expr);
    ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 276 "devbhasha.y"
    { 
        (yyval.expr) = create_expr_result(); 
    ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 280 "devbhasha.y"
    { 
        (yyval.expr) = create_expr_result(); 
    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 284 "devbhasha.y"
    { 
        (yyval.expr) = create_expr_result(); 
    ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 288 "devbhasha.y"
    { 
        (yyval.expr) = create_expr_result(); 
    ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 292 "devbhasha.y"
    { 
        (yyval.expr) = create_expr_result(); 
    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 296 "devbhasha.y"
    { 
        (yyval.expr) = create_expr_result(); 
    ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 303 "devbhasha.y"
    {
        (yyval.expr) = (yyvsp[(1) - (3)].expr);
    ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 310 "devbhasha.y"
    { 
        (yyval.expr) = create_expr_result(); 
    ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 317 "devbhasha.y"
    {
        (yyval.expr) = (yyvsp[(3) - (3)].expr);
        char code[128];
        sprintf(code, "%s = %s\n", (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].expr)->addr);
        append_code((yyval.expr), code);
    ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 324 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        (yyval.expr)->addr = new_temp();
        char code[256];
        sprintf(code, "%s = %s + %s\n%s = %s\n", 
                (yyval.expr)->addr, (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].expr)->addr, (yyvsp[(1) - (3)].sval), (yyval.expr)->addr);
        append_code((yyval.expr), (yyvsp[(3) - (3)].expr)->code);
        append_code((yyval.expr), code);
    ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 334 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        (yyval.expr)->addr = new_temp();
        char code[256];
        sprintf(code, "%s = %s - %s\n%s = %s\n", 
                (yyval.expr)->addr, (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].expr)->addr, (yyvsp[(1) - (3)].sval), (yyval.expr)->addr);
        append_code((yyval.expr), (yyvsp[(3) - (3)].expr)->code);
        append_code((yyval.expr), code);
    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 344 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        (yyval.expr)->addr = new_temp();
        char code[256];
        sprintf(code, "%s = %s * %s\n%s = %s\n", 
                (yyval.expr)->addr, (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].expr)->addr, (yyvsp[(1) - (3)].sval), (yyval.expr)->addr);
        append_code((yyval.expr), (yyvsp[(3) - (3)].expr)->code);
        append_code((yyval.expr), code);
    ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 354 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        (yyval.expr)->addr = new_temp();
        char code[256];
        sprintf(code, "%s = %s / %s\n%s = %s\n", 
                (yyval.expr)->addr, (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].expr)->addr, (yyvsp[(1) - (3)].sval), (yyval.expr)->addr);
        append_code((yyval.expr), (yyvsp[(3) - (3)].expr)->code);
        append_code((yyval.expr), code);
    ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 364 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        (yyval.expr)->addr = new_temp();
        char code[256];
        sprintf(code, "%s = %s %% %s\n%s = %s\n", 
                (yyval.expr)->addr, (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].expr)->addr, (yyvsp[(1) - (3)].sval), (yyval.expr)->addr);
        append_code((yyval.expr), (yyvsp[(3) - (3)].expr)->code);
        append_code((yyval.expr), code);
    ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 377 "devbhasha.y"
    {
        (yyval.expr) = (yyvsp[(1) - (1)].expr);
    ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 384 "devbhasha.y"
    {
        (yyval.expr) = (yyvsp[(1) - (1)].expr);
    ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 388 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        (yyval.expr)->addr = new_temp();
        append_code((yyval.expr), (yyvsp[(1) - (3)].expr)->code);
        append_code((yyval.expr), (yyvsp[(3) - (3)].expr)->code);
        char code[128];
        sprintf(code, "%s = %s || %s\n", (yyval.expr)->addr, (yyvsp[(1) - (3)].expr)->addr, (yyvsp[(3) - (3)].expr)->addr);
        append_code((yyval.expr), code);
    ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 401 "devbhasha.y"
    {
        (yyval.expr) = (yyvsp[(1) - (1)].expr);
    ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 405 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        (yyval.expr)->addr = new_temp();
        append_code((yyval.expr), (yyvsp[(1) - (3)].expr)->code);
        append_code((yyval.expr), (yyvsp[(3) - (3)].expr)->code);
        char code[128];
        sprintf(code, "%s = %s && %s\n", (yyval.expr)->addr, (yyvsp[(1) - (3)].expr)->addr, (yyvsp[(3) - (3)].expr)->addr);
        append_code((yyval.expr), code);
    ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 418 "devbhasha.y"
    {
        (yyval.expr) = (yyvsp[(1) - (1)].expr);
    ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 422 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        (yyval.expr)->addr = new_temp();
        append_code((yyval.expr), (yyvsp[(1) - (3)].expr)->code);
        append_code((yyval.expr), (yyvsp[(3) - (3)].expr)->code);
        char code[128];
        sprintf(code, "%s = %s == %s\n", (yyval.expr)->addr, (yyvsp[(1) - (3)].expr)->addr, (yyvsp[(3) - (3)].expr)->addr);
        append_code((yyval.expr), code);
    ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 432 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        (yyval.expr)->addr = new_temp();
        append_code((yyval.expr), (yyvsp[(1) - (3)].expr)->code);
        append_code((yyval.expr), (yyvsp[(3) - (3)].expr)->code);
        char code[128];
        sprintf(code, "%s = %s != %s\n", (yyval.expr)->addr, (yyvsp[(1) - (3)].expr)->addr, (yyvsp[(3) - (3)].expr)->addr);
        append_code((yyval.expr), code);
    ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 445 "devbhasha.y"
    {
        (yyval.expr) = (yyvsp[(1) - (1)].expr);
    ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 449 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        (yyval.expr)->addr = new_temp();
        append_code((yyval.expr), (yyvsp[(1) - (3)].expr)->code);
        append_code((yyval.expr), (yyvsp[(3) - (3)].expr)->code);
        char code[128];
        sprintf(code, "%s = %s < %s\n", (yyval.expr)->addr, (yyvsp[(1) - (3)].expr)->addr, (yyvsp[(3) - (3)].expr)->addr);
        append_code((yyval.expr), code);
    ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 459 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        (yyval.expr)->addr = new_temp();
        append_code((yyval.expr), (yyvsp[(1) - (3)].expr)->code);
        append_code((yyval.expr), (yyvsp[(3) - (3)].expr)->code);
        char code[128];
        sprintf(code, "%s = %s > %s\n", (yyval.expr)->addr, (yyvsp[(1) - (3)].expr)->addr, (yyvsp[(3) - (3)].expr)->addr);
        append_code((yyval.expr), code);
    ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 469 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        (yyval.expr)->addr = new_temp();
        append_code((yyval.expr), (yyvsp[(1) - (3)].expr)->code);
        append_code((yyval.expr), (yyvsp[(3) - (3)].expr)->code);
        char code[128];
        sprintf(code, "%s = %s <= %s\n", (yyval.expr)->addr, (yyvsp[(1) - (3)].expr)->addr, (yyvsp[(3) - (3)].expr)->addr);
        append_code((yyval.expr), code);
    ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 479 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        (yyval.expr)->addr = new_temp();
        append_code((yyval.expr), (yyvsp[(1) - (3)].expr)->code);
        append_code((yyval.expr), (yyvsp[(3) - (3)].expr)->code);
        char code[128];
        sprintf(code, "%s = %s >= %s\n", (yyval.expr)->addr, (yyvsp[(1) - (3)].expr)->addr, (yyvsp[(3) - (3)].expr)->addr);
        append_code((yyval.expr), code);
    ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 492 "devbhasha.y"
    {
        (yyval.expr) = (yyvsp[(1) - (1)].expr);
    ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 496 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        (yyval.expr)->addr = new_temp();
        append_code((yyval.expr), (yyvsp[(1) - (3)].expr)->code);
        append_code((yyval.expr), (yyvsp[(3) - (3)].expr)->code);
        char code[128];
        sprintf(code, "%s = %s + %s\n", (yyval.expr)->addr, (yyvsp[(1) - (3)].expr)->addr, (yyvsp[(3) - (3)].expr)->addr);
        append_code((yyval.expr), code);
    ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 506 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        (yyval.expr)->addr = new_temp();
        append_code((yyval.expr), (yyvsp[(1) - (3)].expr)->code);
        append_code((yyval.expr), (yyvsp[(3) - (3)].expr)->code);
        char code[128];
        sprintf(code, "%s = %s - %s\n", (yyval.expr)->addr, (yyvsp[(1) - (3)].expr)->addr, (yyvsp[(3) - (3)].expr)->addr);
        append_code((yyval.expr), code);
    ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 516 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        (yyval.expr)->addr = new_temp();
        append_code((yyval.expr), (yyvsp[(3) - (3)].expr)->code);
        char code[256];
        sprintf(code, "%s = concat(%s, %s)\n", (yyval.expr)->addr, (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].expr)->addr);
        append_code((yyval.expr), code);
    ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 525 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        (yyval.expr)->addr = new_temp();
        append_code((yyval.expr), (yyvsp[(1) - (3)].expr)->code);
        char code[256];
        sprintf(code, "%s = concat(%s, %s)\n", (yyval.expr)->addr, (yyvsp[(1) - (3)].expr)->addr, (yyvsp[(3) - (3)].sval));
        append_code((yyval.expr), code);
    ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 537 "devbhasha.y"
    {
        (yyval.expr) = (yyvsp[(1) - (1)].expr);
    ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 541 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        (yyval.expr)->addr = new_temp();
        append_code((yyval.expr), (yyvsp[(1) - (3)].expr)->code);
        append_code((yyval.expr), (yyvsp[(3) - (3)].expr)->code);
        char code[128];
        sprintf(code, "%s = %s * %s\n", (yyval.expr)->addr, (yyvsp[(1) - (3)].expr)->addr, (yyvsp[(3) - (3)].expr)->addr);
        append_code((yyval.expr), code);
    ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 551 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        (yyval.expr)->addr = new_temp();
        append_code((yyval.expr), (yyvsp[(1) - (3)].expr)->code);
        append_code((yyval.expr), (yyvsp[(3) - (3)].expr)->code);
        char code[128];
        sprintf(code, "%s = %s / %s\n", (yyval.expr)->addr, (yyvsp[(1) - (3)].expr)->addr, (yyvsp[(3) - (3)].expr)->addr);
        append_code((yyval.expr), code);
    ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 561 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        (yyval.expr)->addr = new_temp();
        append_code((yyval.expr), (yyvsp[(1) - (3)].expr)->code);
        append_code((yyval.expr), (yyvsp[(3) - (3)].expr)->code);
        char code[128];
        sprintf(code, "%s = %s %% %s\n", (yyval.expr)->addr, (yyvsp[(1) - (3)].expr)->addr, (yyvsp[(3) - (3)].expr)->addr);
        append_code((yyval.expr), code);
    ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 574 "devbhasha.y"
    {
        (yyval.expr) = (yyvsp[(1) - (1)].expr);
    ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 578 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        (yyval.expr)->addr = new_temp();
        append_code((yyval.expr), (yyvsp[(2) - (2)].expr)->code);
        char code[128];
        sprintf(code, "%s = !%s\n", (yyval.expr)->addr, (yyvsp[(2) - (2)].expr)->addr);
        append_code((yyval.expr), code);
    ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 587 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        (yyval.expr)->addr = new_temp();
        append_code((yyval.expr), (yyvsp[(2) - (2)].expr)->code);
        char code[128];
        sprintf(code, "%s = -%s\n", (yyval.expr)->addr, (yyvsp[(2) - (2)].expr)->addr);
        append_code((yyval.expr), code);
    ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 599 "devbhasha.y"
    {
        (yyval.expr) = (yyvsp[(1) - (1)].expr);
    ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 603 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        (yyval.expr)->addr = new_temp();
        char code[128];
        sprintf(code, "%s = %s\n%s = %s + 1\n", (yyval.expr)->addr, (yyvsp[(1) - (2)].sval), (yyvsp[(1) - (2)].sval), (yyvsp[(1) - (2)].sval));
        append_code((yyval.expr), code);
    ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 611 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        (yyval.expr)->addr = new_temp();
        char code[128];
        sprintf(code, "%s = %s\n%s = %s - 1\n", (yyval.expr)->addr, (yyvsp[(1) - (2)].sval), (yyvsp[(1) - (2)].sval), (yyvsp[(1) - (2)].sval));
        append_code((yyval.expr), code);
    ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 622 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        (yyval.expr)->addr = strdup((yyvsp[(1) - (1)].sval));
    ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 627 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        (yyval.expr)->addr = (char*)malloc(16);
        sprintf((yyval.expr)->addr, "%d", (yyvsp[(1) - (1)].ival));
    ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 633 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        (yyval.expr)->addr = (char*)malloc(16);
        sprintf((yyval.expr)->addr, "%f", (yyvsp[(1) - (1)].fval));
    ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 639 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        (yyval.expr)->addr = (char*)malloc(8);
        sprintf((yyval.expr)->addr, "'%c'", (yyvsp[(1) - (1)].cval));
    ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 645 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        (yyval.expr)->addr = strdup((yyvsp[(1) - (1)].sval));
    ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 650 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        (yyval.expr)->addr = strdup((yyvsp[(1) - (1)].bval) ? "haan" : "nahi");
    ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 655 "devbhasha.y"
    {
        (yyval.expr) = (yyvsp[(2) - (3)].expr);
    ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 659 "devbhasha.y"
    {
        (yyval.expr) = (yyvsp[(1) - (1)].expr);
    ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 666 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        char* true_label = new_label();
        char* end_label = new_label();
        
        append_code((yyval.expr), (yyvsp[(3) - (5)].expr)->code);
        
        char code[256];
        sprintf(code, "if %s goto %s\ngoto %s\n%s:\n", 
                (yyvsp[(3) - (5)].expr)->addr, true_label, end_label, true_label);
        append_code((yyval.expr), code);
        
        append_code((yyval.expr), (yyvsp[(5) - (5)].expr)->code);
        
        sprintf(code, "%s:\n", end_label);
        append_code((yyval.expr), code);
    ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 684 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        char* true_label = new_label();
        char* false_label = new_label();
        char* end_label = new_label();
        
        append_code((yyval.expr), (yyvsp[(3) - (7)].expr)->code);
        
        char code[256];
        sprintf(code, "if %s goto %s\ngoto %s\n%s:\n", 
                (yyvsp[(3) - (7)].expr)->addr, true_label, false_label, true_label);
        append_code((yyval.expr), code);
        
        append_code((yyval.expr), (yyvsp[(5) - (7)].expr)->code);
        
        sprintf(code, "goto %s\n%s:\n", end_label, false_label);
        append_code((yyval.expr), code);
        
        append_code((yyval.expr), (yyvsp[(7) - (7)].expr)->code);
        
        sprintf(code, "%s:\n", end_label);
        append_code((yyval.expr), code);
    ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 711 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        char* begin_label = new_label();
        char* true_label = new_label();
        char* end_label = new_label();
        
        char code[256];
        sprintf(code, "%s:\n", begin_label);
        append_code((yyval.expr), code);
        
        append_code((yyval.expr), (yyvsp[(3) - (5)].expr)->code);
        
        sprintf(code, "if %s goto %s\ngoto %s\n%s:\n", 
                (yyvsp[(3) - (5)].expr)->addr, true_label, end_label, true_label);
        append_code((yyval.expr), code);
        
        append_code((yyval.expr), (yyvsp[(5) - (5)].expr)->code);
        
        sprintf(code, "goto %s\n%s:\n", begin_label, end_label);
        append_code((yyval.expr), code);
    ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 733 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        char* begin_label = new_label();
        char* continue_label = new_label();
        
        char code[256];
        sprintf(code, "%s:\n", begin_label);
        append_code((yyval.expr), code);
        
        append_code((yyval.expr), (yyvsp[(2) - (7)].expr)->code);
        
        sprintf(code, "%s:\n", continue_label);
        append_code((yyval.expr), code);
        
        append_code((yyval.expr), (yyvsp[(5) - (7)].expr)->code);
        
        sprintf(code, "if %s goto %s\n", (yyvsp[(5) - (7)].expr)->addr, begin_label);
        append_code((yyval.expr), code);
    ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 756 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        char* begin_label = new_label();
        char* true_label = new_label();
        char* end_label = new_label();
        
        append_code((yyval.expr), (yyvsp[(3) - (9)].expr)->code);
        
        char code[256];
        sprintf(code, "%s:\n", begin_label);
        append_code((yyval.expr), code);
        
        append_code((yyval.expr), (yyvsp[(5) - (9)].expr)->code);
        
        sprintf(code, "if %s goto %s\ngoto %s\n%s:\n", 
                (yyvsp[(5) - (9)].expr)->addr, true_label, end_label, true_label);
        append_code((yyval.expr), code);
        
        append_code((yyval.expr), (yyvsp[(9) - (9)].expr)->code);
        append_code((yyval.expr), (yyvsp[(7) - (9)].expr)->code);
        
        sprintf(code, "goto %s\n%s:\n", begin_label, end_label);
        append_code((yyval.expr), code);
    ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 781 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        char* begin_label = new_label();
        char* true_label = new_label();
        char* end_label = new_label();
        
        append_code((yyval.expr), (yyvsp[(3) - (9)].expr)->code);
        
        char code[256];
        sprintf(code, "%s:\n", begin_label);
        append_code((yyval.expr), code);
        
        append_code((yyval.expr), (yyvsp[(5) - (9)].expr)->code);
        
        sprintf(code, "if %s goto %s\ngoto %s\n%s:\n", 
                (yyvsp[(5) - (9)].expr)->addr, true_label, end_label, true_label);
        append_code((yyval.expr), code);
        
        append_code((yyval.expr), (yyvsp[(9) - (9)].expr)->code);
        append_code((yyval.expr), (yyvsp[(7) - (9)].expr)->code);
        
        sprintf(code, "goto %s\n%s:\n", begin_label, end_label);
        append_code((yyval.expr), code);
    ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 806 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        char* begin_label = new_label();
        char* true_label = new_label();
        char* end_label = new_label();
        
        char code[256];
        sprintf(code, "%s:\n", begin_label);
        append_code((yyval.expr), code);
        
        append_code((yyval.expr), (yyvsp[(4) - (8)].expr)->code);
        
        sprintf(code, "if %s goto %s\ngoto %s\n%s:\n", 
                (yyvsp[(4) - (8)].expr)->addr, true_label, end_label, true_label);
        append_code((yyval.expr), code);
        
        append_code((yyval.expr), (yyvsp[(8) - (8)].expr)->code);
        append_code((yyval.expr), (yyvsp[(6) - (8)].expr)->code);
        
        sprintf(code, "goto %s\n%s:\n", begin_label, end_label);
        append_code((yyval.expr), code);
    ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 832 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        char code[256];
        sprintf(code, "// Function: %s\n", (yyvsp[(3) - (7)].sval));
        append_code((yyval.expr), code);
        sprintf(code, "func %s:\n", (yyvsp[(3) - (7)].sval));
        append_code((yyval.expr), code);
        append_code((yyval.expr), (yyvsp[(7) - (7)].expr)->code);
        append_code((yyval.expr), "return\n");
    ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 843 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        char code[256];
        sprintf(code, "// Function: %s\n", (yyvsp[(3) - (6)].sval));
        append_code((yyval.expr), code);
        sprintf(code, "func %s:\n", (yyvsp[(3) - (6)].sval));
        append_code((yyval.expr), code);
        append_code((yyval.expr), (yyvsp[(6) - (6)].expr)->code);
        append_code((yyval.expr), "return\n");
    ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 857 "devbhasha.y"
    {
        (yyval.expr) = (yyvsp[(1) - (1)].expr);
    ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 861 "devbhasha.y"
    {
        (yyval.expr) = (yyvsp[(1) - (3)].expr);
    ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 868 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
    ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 875 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        char code[128];
        (yyval.expr)->addr = new_temp();
        sprintf(code, "// Function call: %s\n", (yyvsp[(1) - (3)].sval));
        append_code((yyval.expr), code);
        sprintf(code, "%s = call %s\n", (yyval.expr)->addr, (yyvsp[(1) - (3)].sval));
        append_code((yyval.expr), code);
    ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 885 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        char code[128];
        (yyval.expr)->addr = new_temp();
        sprintf(code, "// Function call: %s\n", (yyvsp[(1) - (4)].sval));
        append_code((yyval.expr), code);
        sprintf(code, "%s = call %s\n", (yyval.expr)->addr, (yyvsp[(1) - (4)].sval));
        append_code((yyval.expr), code);
    ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 898 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        append_code((yyval.expr), (yyvsp[(1) - (1)].expr)->code);
    ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 903 "devbhasha.y"
    {
        (yyval.expr) = (yyvsp[(1) - (3)].expr);
        append_code((yyval.expr), (yyvsp[(3) - (3)].expr)->code);
    ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 911 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        append_code((yyval.expr), (yyvsp[(2) - (2)].expr)->code);
        char code[128];
        sprintf(code, "return %s\n", (yyvsp[(2) - (2)].expr)->addr);
        append_code((yyval.expr), code);
    ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 919 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        append_code((yyval.expr), "return\n");
    ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 927 "devbhasha.y"
    {
        (yyval.expr) = create_expr_result();
        append_code((yyval.expr), (yyvsp[(3) - (4)].expr)->code);
        char code[128];
        sprintf(code, "print %s\n", (yyvsp[(3) - (4)].expr)->addr);
        append_code((yyval.expr), code);
    ;}
    break;



/* Line 1455 of yacc.c  */
#line 2893 "devbhasha.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 936 "devbhasha.y"


void yyerror(const char* s) {
    fprintf(stderr, "Error on line %d: %s\n", line_num, s);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }
    
    FILE* input_file = fopen(argv[1], "r");
    if (!input_file) {
        fprintf(stderr, "Cannot open input file %s\n", argv[1]);
        return 1;
    }
    
    yyin = input_file;
    yyparse();
    
    fclose(input_file);
    return 0;
}
