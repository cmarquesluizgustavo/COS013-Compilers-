/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     _ID = 258,
     _NUM = 259,
     _STRING = 260,
     _LET = 261,
     _VAR = 262,
     _CONST = 263,
     _FOR = 264,
     _FUNCTION = 265,
     _IF = 266,
     _ELSE = 267,
     _INC_UM = 268,
     _RETURN = 269,
     _SETA = 270,
     _FPSETA = 271,
     _INC_A = 272,
     _IGUAL_A = 273,
     _DEC_A = 274,
     _WHILE = 275
   };
#endif
/* Tokens.  */
#define _ID 258
#define _NUM 259
#define _STRING 260
#define _LET 261
#define _VAR 262
#define _CONST 263
#define _FOR 264
#define _FUNCTION 265
#define _IF 266
#define _ELSE 267
#define _INC_UM 268
#define _RETURN 269
#define _SETA 270
#define _FPSETA 271
#define _INC_A 272
#define _IGUAL_A 273
#define _DEC_A 274
#define _WHILE 275




/* Copy the first part of user declarations.  */
#line 1 "glc_js.y"

// Includes em C/C++ e outras definições.
#include <iostream>
#include <string>
#include <string.h>
#include <map>
#include <vector>

using namespace std;

struct Atributos {
    vector<string> c;
    int linha, coluna;
};

struct Simbolo { 
    int linha, coluna; 
    string tipo_decl; // "let", "const" e "var"
};


// Tenta declarar uma variável "let", "var" ou "const"
void tenta_declarar_let( string nome, int linha, int coluna );
void tenta_declarar_const( string nome, int linha, int coluna );

// Verifica se a variável já foi declarada como "var" anteriormente
bool ja_declarou_var( string nome, int linha, int coluna );
void const_declarado_check(string nome, int linha, int coluna);

vector<map<string,Simbolo>> ts = { { } };
vector<string> concatena( vector<string> a, vector<string> b );
vector<string> operator+( vector<string> a, vector<string> b );
vector<string> operator+( vector<string> a, string b );
vector<string> operator+( string a, vector<string> b );
string gera_label( string prefixo );
vector<string> resolve_enderecos( vector<string> entrada );

int linha = 1;
int coluna = 1;

// Tipo dos atributos: YYSTYPE é o tipo usado para os atributos.
#define YYSTYPE Atributos

void erro( string msg );
void imprime_codigo( vector<string> codigo );

// protótipo para o analisador léxico (gerado pelo lex)
extern "C" int yylex();
void yyerror( const char* );



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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 198 "y.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  63
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   502

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNRULES -- Number of states.  */
#define YYNSTATES  202

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   275

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    29,     2,     2,
      31,    37,    27,    25,    21,    26,    32,    28,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    33,    34,
      23,    22,    24,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    30,     2,    38,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,    36,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    12,    15,    16,    18,    20,
      22,    25,    30,    33,    35,    38,    42,    50,    56,    66,
      76,    82,    84,    85,    88,    91,    94,   104,   115,   116,
     117,   121,   123,   127,   129,   133,   135,   139,   141,   145,
     147,   151,   153,   159,   163,   167,   169,   171,   174,   178,
     182,   186,   190,   197,   200,   204,   209,   215,   221,   228,
     237,   244,   253,   257,   261,   265,   269,   273,   277,   281,
     285,   287,   289,   291,   293,   297,   301,   306,   311,   314,
     318,   322,   326,   328,   335,   343,   347,   351,   355
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      40,     0,    -1,    41,    -1,    42,    41,    -1,    47,    34,
      41,    -1,    48,    41,    -1,    -1,    44,    -1,    43,    -1,
      45,    -1,    58,    34,    -1,    35,    42,    41,    36,    -1,
      35,    36,    -1,    34,    -1,    14,    34,    -1,    14,    59,
      34,    -1,    11,    31,    60,    37,    42,    12,    42,    -1,
      11,    31,    60,    37,    42,    -1,     9,    31,    46,    34,
      46,    34,    46,    37,    42,    -1,     9,    31,    47,    34,
      46,    34,    46,    37,    42,    -1,    20,    31,    60,    37,
      42,    -1,    58,    -1,    -1,     6,    53,    -1,     7,    54,
      -1,     8,    57,    -1,    10,     3,    31,    37,    35,    49,
      41,    36,    50,    -1,    10,     3,    31,    49,    51,    37,
      35,    41,    36,    50,    -1,    -1,    -1,    52,    21,    51,
      -1,    52,    -1,     3,    22,    59,    -1,     3,    -1,    55,
      21,    53,    -1,    55,    -1,    56,    21,    54,    -1,    56,
      -1,     3,    22,    59,    -1,     3,    -1,     3,    22,    59,
      -1,     3,    -1,     3,    22,    59,    21,    57,    -1,     3,
      22,    59,    -1,    60,    21,    58,    -1,    60,    -1,    60,
      -1,    35,    36,    -1,     3,    22,    59,    -1,     3,    17,
      59,    -1,     3,    19,    59,    -1,     3,    15,    59,    -1,
       3,    15,    35,    42,    41,    36,    -1,    59,    13,    -1,
      31,    16,    59,    -1,    31,    51,    16,    59,    -1,    61,
      32,     3,    22,    59,    -1,    61,    32,     3,    17,    59,
      -1,    61,    30,    59,    38,    22,    59,    -1,    61,    32,
       3,    30,    59,    38,    22,    59,    -1,    61,    30,    59,
      38,    17,    59,    -1,    61,    32,     3,    30,    59,    38,
      17,    59,    -1,    59,    23,    59,    -1,    59,    27,    59,
      -1,    59,    25,    59,    -1,    59,    26,    59,    -1,    59,
      28,    59,    -1,    59,    24,    59,    -1,    59,    29,    59,
      -1,    59,    18,    59,    -1,    61,    -1,     3,    -1,     4,
      -1,     5,    -1,    31,    59,    37,    -1,    61,    31,    37,
      -1,    61,    30,    59,    38,    -1,    61,    31,    64,    37,
      -1,    30,    38,    -1,    30,    64,    38,    -1,    35,    63,
      36,    -1,    61,    32,     3,    -1,    62,    -1,    10,    31,
      37,    35,    41,    36,    -1,    10,    31,    51,    37,    35,
      41,    36,    -1,    63,    21,    63,    -1,     3,    33,    59,
      -1,    59,    21,    64,    -1,    59,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    70,    70,    73,    74,    75,    76,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    90,   100,   110,   118,
     128,   138,   139,   142,   143,   144,   147,   148,   151,   154,
     157,   158,   161,   162,   165,   166,   169,   170,   173,   178,
     184,   196,   203,   208,   216,   217,   220,   221,   224,   229,
     233,   237,   238,   239,   243,   244,   245,   247,   249,   253,
     255,   256,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   283,   284,   288,   289,   293,   294
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_ID", "_NUM", "_STRING", "_LET", "_VAR",
  "_CONST", "_FOR", "_FUNCTION", "_IF", "_ELSE", "_INC_UM", "_RETURN",
  "_SETA", "_FPSETA", "_INC_A", "_IGUAL_A", "_DEC_A", "_WHILE", "','",
  "'='", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'['", "'('",
  "'.'", "':'", "';'", "'{'", "'}'", "')'", "']'", "$accept", "S", "CMDs",
  "CMD", "CMD_IF", "CMD_FOR", "CMD_WHILE", "E_OPC", "DECL_VAR", "DECL_FUN",
  "NOVO_ESCOPO", "DESTROI_ESCOPO", "PARAMs", "PARAM", "LVARs", "VVARs",
  "LVAR", "VVAR", "CTEs", "E_V", "EE", "E", "F", "FUNC_ANON", "CAMPOs",
  "ARGs", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,    44,    61,    60,    62,    43,    45,    42,    47,    37,
      91,    40,    46,    58,    59,   123,   125,    41,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    41,    41,    41,    41,    42,    42,    42,
      42,    42,    42,    42,    42,    42,    43,    43,    44,    44,
      45,    46,    46,    47,    47,    47,    48,    48,    49,    50,
      51,    51,    52,    52,    53,    53,    54,    54,    55,    55,
      56,    56,    57,    57,    58,    58,    59,    59,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    62,    62,    63,    63,    64,    64
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     3,     2,     0,     1,     1,     1,
       2,     4,     2,     1,     2,     3,     7,     5,     9,     9,
       5,     1,     0,     2,     2,     2,     9,    10,     0,     0,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     5,     3,     3,     1,     1,     2,     3,     3,
       3,     3,     6,     2,     3,     4,     5,     5,     6,     8,
       6,     8,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     3,     3,     4,     4,     2,     3,
       3,     3,     1,     6,     7,     3,     3,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,    71,    72,    73,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    13,     0,     0,     2,     6,     8,
       7,     9,     0,     6,     0,     0,    46,    70,    82,     0,
       0,     0,     0,    39,    23,    35,    41,    24,    37,     0,
      25,    22,     0,     0,     0,     0,    14,     0,     0,    46,
       0,    78,    88,     0,    71,     0,     0,    31,     0,    71,
      12,     6,     0,     1,     3,     6,     5,    10,    53,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    51,    49,    50,    48,     0,     0,     0,     0,
       0,     0,     0,    21,    28,    33,     0,     0,    46,     0,
      47,    15,    46,     0,    79,     0,    54,     0,     0,    74,
       0,     0,     0,    80,     4,    69,    62,    67,    64,    65,
      63,    66,    68,    44,     0,    75,     0,    81,     6,    38,
      34,    40,    36,    43,    22,    22,     0,     0,     0,     6,
       0,     0,     0,    87,    32,    55,    30,    86,    11,    85,
      76,    77,     0,     0,     0,     0,     0,     0,     0,    28,
       0,    32,     0,     6,    17,    20,     0,     0,    57,    56,
       0,    52,    42,    22,    22,     6,     0,    83,     0,     0,
      60,    58,     0,     0,     0,     0,     6,    84,    16,     0,
       0,     0,     0,    29,     0,    61,    59,    18,    19,    26,
      29,    27
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    16,    17,    18,    19,    20,    21,    91,    22,    23,
     137,   199,    56,    57,    34,    37,    35,    38,    40,    24,
      25,    49,    27,    28,    62,    53
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -116
static const yytype_int16 yypact[] =
{
     239,    98,  -116,  -116,     4,    18,    21,   -26,    11,    -1,
     273,     1,    70,   284,  -116,   193,    34,  -116,   239,  -116,
    -116,  -116,    19,   239,    22,   439,   -12,   -20,  -116,   287,
     306,   306,   306,    38,  -116,    12,    44,  -116,    48,    50,
    -116,   154,    45,    -2,   306,    47,  -116,     3,   388,  -116,
     306,  -116,   405,    55,   130,   306,    66,    78,   354,    92,
     456,   239,    -5,  -116,  -116,   239,  -116,  -116,  -116,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,    33,
     100,   205,   439,   439,   439,   439,   306,     4,   306,    18,
     306,    76,    88,  -116,    75,   102,   105,    90,    96,   115,
    -116,  -116,   101,   306,  -116,   306,   439,   306,   147,  -116,
     306,   119,   153,  -116,  -116,   473,   473,   473,   103,   103,
     158,   158,   158,  -116,   320,  -116,   129,    32,   239,   439,
    -116,   439,  -116,   422,   306,   306,   132,   147,   306,   239,
     137,   251,   251,  -116,   371,   439,  -116,   439,  -116,  -116,
      35,  -116,   306,   306,   306,   141,    21,   144,   146,  -116,
     150,   439,   152,   239,   178,  -116,   306,   306,   439,   439,
     337,  -116,  -116,   306,   306,   239,   160,  -116,   163,   251,
     439,   439,    62,   164,   174,   176,   239,  -116,  -116,   306,
     306,   251,   251,  -116,   181,   439,   439,  -116,  -116,  -116,
    -116,  -116
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -116,  -116,   -10,     2,  -116,  -116,  -116,  -115,   159,  -116,
      59,    20,   -41,  -116,   134,   133,  -116,  -116,    74,   -37,
      16,     0,  -116,  -116,   114,   -76
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -49
static const yytype_int16 yytable[] =
{
      26,    95,    97,   126,    93,    41,    99,    33,    64,    77,
      78,    79,    80,    66,    42,    26,   112,    61,    26,   157,
     158,    36,   -45,    26,    39,   -45,    48,   143,    52,    58,
      44,   113,    50,    87,    63,    96,     1,     2,     3,   100,
     123,    26,    43,    45,    98,    82,    83,    84,    85,   152,
     102,   111,   166,    65,   153,   114,    67,   167,   183,   184,
      86,    26,   154,    12,    13,    26,    88,   146,    47,    89,
     125,   106,    90,     1,     2,     3,    94,    26,    43,   189,
      45,    26,   107,   128,   190,   115,   116,   117,   118,   119,
     120,   121,   122,   104,   124,    52,   160,    93,    93,   108,
      12,    13,   129,   127,   131,    47,   133,    29,    51,    30,
     134,    31,   136,    29,    32,    30,    68,    31,   155,    52,
      32,   144,   135,   145,   138,   110,   147,   140,    26,   162,
      74,    75,    76,   141,    26,    26,    93,    93,   142,    26,
     139,    26,    26,   164,   165,    29,   -33,    30,   110,    31,
      95,   -33,   105,   178,   161,   148,    99,     1,     2,     3,
       4,     5,     6,    26,    45,   185,   151,   159,   168,   169,
     170,    68,   163,    26,    26,    26,   194,   171,   173,    26,
     174,   188,   180,   181,    12,    13,    26,   176,   177,    47,
     179,    26,    26,   197,   198,   186,    59,     2,     3,   187,
      92,   191,     7,    45,     9,   195,   196,    10,    59,     2,
       3,   192,   193,    11,     7,    45,     9,   200,   175,    10,
     201,   130,   132,    12,    13,    11,   149,    14,    15,    60,
     172,     0,     0,     0,     0,    12,    13,     0,     0,    14,
      15,   100,     1,     2,     3,     4,     5,     6,     7,     8,
       9,     0,     0,    10,     1,     2,     3,     0,     0,    11,
       7,    45,     9,     0,     0,    10,     0,     0,     0,    12,
      13,    11,     0,    14,    15,     0,     1,     2,     3,     0,
       0,    12,    13,    45,     0,    14,    15,    54,     2,     3,
       1,     2,     3,     0,    45,     0,     0,    45,     0,     0,
      55,     0,     0,    12,    13,     0,     0,    46,    47,     1,
       2,     3,     0,     0,    12,    13,    45,    12,    13,    47,
       0,     0,    81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    68,     0,     0,    12,    13,    69,     0,
       0,    47,     0,    70,    71,    72,    73,    74,    75,    76,
      68,     0,     0,     0,     0,    69,     0,     0,   150,     0,
      70,    71,    72,    73,    74,    75,    76,    68,     0,     0,
       0,     0,    69,     0,     0,   182,     0,    70,    71,    72,
      73,    74,    75,    76,    68,     0,     0,     0,     0,    69,
       0,   109,     0,     0,    70,    71,    72,    73,    74,    75,
      76,    68,     0,     0,     0,     0,    69,     0,   -48,     0,
       0,    70,    71,    72,    73,    74,    75,    76,    68,     0,
       0,     0,   101,    69,     0,     0,   103,     0,    70,    71,
      72,    73,    74,    75,    76,    68,     0,     0,     0,     0,
      69,     0,     0,   156,     0,    70,    71,    72,    73,    74,
      75,    76,    68,     0,     0,     0,     0,    69,     0,     0,
       0,     0,    70,    71,    72,    73,    74,    75,    76,   -47,
       0,     0,     0,     0,   -47,     0,     0,     0,     0,   -47,
     -47,   -47,   -47,   -47,   -47,   -47,    68,     0,     0,     0,
       0,   -49,     0,     0,     0,     0,   -49,   -49,    72,    73,
      74,    75,    76
};

static const yytype_int16 yycheck[] =
{
       0,     3,    43,    79,    41,    31,     3,     3,    18,    21,
      30,    31,    32,    23,     3,    15,    21,    15,    18,   134,
     135,     3,    34,    23,     3,    37,    10,   103,    12,    13,
      31,    36,    31,    21,     0,    37,     3,     4,     5,    36,
      77,    41,    31,    10,    44,    29,    30,    31,    32,    17,
      50,    61,    17,    34,    22,    65,    34,    22,   173,   174,
      22,    61,    30,    30,    31,    65,    22,   108,    35,    21,
      37,    55,    22,     3,     4,     5,    31,    77,    31,    17,
      10,    81,    16,    81,    22,    69,    70,    71,    72,    73,
      74,    75,    76,    38,    78,    79,   137,   134,   135,    21,
      30,    31,    86,     3,    88,    35,    90,    15,    38,    17,
      34,    19,    37,    15,    22,    17,    13,    19,   128,   103,
      22,   105,    34,   107,    22,    33,   110,    37,   128,   139,
      27,    28,    29,    37,   134,   135,   173,   174,    37,   139,
      35,   141,   142,   141,   142,    15,    16,    17,    33,    19,
       3,    21,    22,   163,   138,    36,     3,     3,     4,     5,
       6,     7,     8,   163,    10,   175,    37,    35,   152,   153,
     154,    13,    35,   173,   174,   175,   186,    36,    34,   179,
      34,   179,   166,   167,    30,    31,   186,    37,    36,    35,
      12,   191,   192,   191,   192,    35,     3,     4,     5,    36,
      41,    37,     9,    10,    11,   189,   190,    14,     3,     4,
       5,    37,    36,    20,     9,    10,    11,    36,   159,    14,
     200,    87,    89,    30,    31,    20,   112,    34,    35,    36,
     156,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    34,
      35,    36,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    14,     3,     4,     5,    -1,    -1,    20,
       9,    10,    11,    -1,    -1,    14,    -1,    -1,    -1,    30,
      31,    20,    -1,    34,    35,    -1,     3,     4,     5,    -1,
      -1,    30,    31,    10,    -1,    34,    35,     3,     4,     5,
       3,     4,     5,    -1,    10,    -1,    -1,    10,    -1,    -1,
      16,    -1,    -1,    30,    31,    -1,    -1,    34,    35,     3,
       4,     5,    -1,    -1,    30,    31,    10,    30,    31,    35,
      -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    13,    -1,    -1,    30,    31,    18,    -1,
      -1,    35,    -1,    23,    24,    25,    26,    27,    28,    29,
      13,    -1,    -1,    -1,    -1,    18,    -1,    -1,    38,    -1,
      23,    24,    25,    26,    27,    28,    29,    13,    -1,    -1,
      -1,    -1,    18,    -1,    -1,    38,    -1,    23,    24,    25,
      26,    27,    28,    29,    13,    -1,    -1,    -1,    -1,    18,
      -1,    37,    -1,    -1,    23,    24,    25,    26,    27,    28,
      29,    13,    -1,    -1,    -1,    -1,    18,    -1,    37,    -1,
      -1,    23,    24,    25,    26,    27,    28,    29,    13,    -1,
      -1,    -1,    34,    18,    -1,    -1,    21,    -1,    23,    24,
      25,    26,    27,    28,    29,    13,    -1,    -1,    -1,    -1,
      18,    -1,    -1,    21,    -1,    23,    24,    25,    26,    27,
      28,    29,    13,    -1,    -1,    -1,    -1,    18,    -1,    -1,
      -1,    -1,    23,    24,    25,    26,    27,    28,    29,    13,
      -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,    23,
      24,    25,    26,    27,    28,    29,    13,    -1,    -1,    -1,
      -1,    18,    -1,    -1,    -1,    -1,    23,    24,    25,    26,
      27,    28,    29
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      14,    20,    30,    31,    34,    35,    40,    41,    42,    43,
      44,    45,    47,    48,    58,    59,    60,    61,    62,    15,
      17,    19,    22,     3,    53,    55,     3,    54,    56,     3,
      57,    31,     3,    31,    31,    10,    34,    35,    59,    60,
      31,    38,    59,    64,     3,    16,    51,    52,    59,     3,
      36,    42,    63,     0,    41,    34,    41,    34,    13,    18,
      23,    24,    25,    26,    27,    28,    29,    21,    30,    31,
      32,    35,    59,    59,    59,    59,    22,    21,    22,    21,
      22,    46,    47,    58,    31,     3,    37,    51,    60,     3,
      36,    34,    60,    21,    38,    22,    59,    16,    21,    37,
      33,    41,    21,    36,    41,    59,    59,    59,    59,    59,
      59,    59,    59,    58,    59,    37,    64,     3,    42,    59,
      53,    59,    54,    59,    34,    34,    37,    49,    22,    35,
      37,    37,    37,    64,    59,    59,    51,    59,    36,    63,
      38,    37,    17,    22,    30,    41,    21,    46,    46,    35,
      51,    59,    41,    35,    42,    42,    17,    22,    59,    59,
      59,    36,    57,    34,    34,    49,    37,    36,    41,    12,
      59,    59,    38,    46,    46,    41,    35,    36,    42,    17,
      22,    37,    37,    36,    41,    59,    59,    42,    42,    50,
      36,    50
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
        case 2:
#line 70 "glc_js.y"
    { imprime_codigo( resolve_enderecos( (yyvsp[(1) - (1)]).c + "." ) ); cout << endl;}
    break;

  case 3:
#line 73 "glc_js.y"
    { (yyval).c = (yyvsp[(1) - (2)]).c + (yyvsp[(2) - (2)]).c; }
    break;

  case 4:
#line 74 "glc_js.y"
    { (yyval).c = (yyvsp[(1) - (3)]).c + (yyvsp[(3) - (3)]).c; }
    break;

  case 5:
#line 75 "glc_js.y"
    { (yyval).c = (yyvsp[(1) - (2)]).c + (yyvsp[(2) - (2)]).c; }
    break;

  case 6:
#line 76 "glc_js.y"
    { (yyval).c.clear(); }
    break;

  case 11:
#line 83 "glc_js.y"
    { (yyval).c = "<{" + (yyvsp[(2) - (4)]).c + (yyvsp[(3) - (4)]).c + "}>"; }
    break;

  case 12:
#line 84 "glc_js.y"
    { (yyval).c.clear(); (yyval).c.push_back("<{}>"); }
    break;

  case 13:
#line 85 "glc_js.y"
    { (yyval).c.clear(); }
    break;

  case 16:
#line 91 "glc_js.y"
    {  string lbl_fim = gera_label( "fim_if" ), 
                   lbl_true = gera_label( "then" ), 
                   lbl_false = gera_label( "else" );
                   
            (yyval).c = (yyvsp[(3) - (7)]).c + lbl_true + "?" + lbl_false + "#" + 
                   (":" + lbl_true) + (yyvsp[(5) - (7)]).c + lbl_fim + "#" +
                   (":" + lbl_false) + (yyvsp[(7) - (7)]).c + 
                   (":" + lbl_fim);
         }
    break;

  case 17:
#line 101 "glc_js.y"
    {  string lbl_fim = gera_label( "fim_if" ), 
                 lbl_true = gera_label( "then" );
                    
            (yyval).c = (yyvsp[(3) - (5)]).c + lbl_true + "?" + lbl_fim + "#" + 
                   (":" + lbl_true) + (yyvsp[(5) - (5)]).c + 
                   (":" + lbl_fim);
        }
    break;

  case 18:
#line 111 "glc_js.y"
    {   string lbl_fim = gera_label( "fim_for" ), 
                   lbl_true = gera_label( "then" );

            (yyval).c =  (yyvsp[(3) - (9)]).c + (yyvsp[(5) - (9)]).c + lbl_true + "?" + lbl_fim + "#" + 
                    (":" + lbl_true) + (yyvsp[(9) - (9)]).c + (yyvsp[(7) - (9)]).c + (yyvsp[(5) - (9)]).c + lbl_true + "?" + lbl_fim + "#" +  
                    (":" + lbl_fim);
        }
    break;

  case 19:
#line 119 "glc_js.y"
    {   string lbl_fim = gera_label( "fim_for" ),
                   lbl_true = gera_label( "then" );

            (yyval).c =  (yyvsp[(3) - (9)]).c + (yyvsp[(5) - (9)]).c + lbl_true + "?" + lbl_fim + "#" + 
                    (":" + lbl_true) + (yyvsp[(9) - (9)]).c + (yyvsp[(7) - (9)]).c + (yyvsp[(5) - (9)]).c + lbl_true + "?" + lbl_fim + "#" +  
                    (":" + lbl_fim);
        }
    break;

  case 20:
#line 129 "glc_js.y"
    {   string lbl_fim = gera_label( "fim_while" ),
                   lbl_true = gera_label( "then" );

            (yyval).c = (yyvsp[(3) - (5)]).c + lbl_true + "?" + lbl_fim + "#" + 
                   (":" + lbl_true) + (yyvsp[(5) - (5)]).c + (yyvsp[(3) - (5)]).c + lbl_true + "?" + lbl_fim + "#" +  
                   (":" + lbl_fim);
          }
    break;

  case 23:
#line 142 "glc_js.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 24:
#line 143 "glc_js.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 25:
#line 144 "glc_js.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 28:
#line 151 "glc_js.y"
    { ts.push_back( {} ); }
    break;

  case 29:
#line 154 "glc_js.y"
    { ts.pop_back(); }
    break;

  case 34:
#line 165 "glc_js.y"
    { (yyval).c = (yyvsp[(1) - (3)]).c + (yyvsp[(3) - (3)]).c; }
    break;

  case 36:
#line 169 "glc_js.y"
    { (yyval).c = (yyvsp[(1) - (3)]).c + (yyvsp[(3) - (3)]).c; }
    break;

  case 38:
#line 174 "glc_js.y"
    {   tenta_declarar_let( (yyvsp[(1) - (3)]).c[0], (yyvsp[(1) - (3)]).linha, (yyvsp[(1) - (3)]).coluna );
            if ( (yyvsp[(3) - (3)]).c[0][0] == '-' )  (yyval).c = (yyvsp[(1) - (3)]).c + "&" + (yyvsp[(1) - (3)]).c + "0" + (yyvsp[(3) - (3)]).c[0].substr(1) + "-" + "=" + "^";
            else  (yyval).c = (yyvsp[(1) - (3)]).c + "&" + (yyvsp[(1) - (3)]).c + (yyvsp[(3) - (3)]).c + "=" + "^";
        }
    break;

  case 39:
#line 179 "glc_js.y"
    {   tenta_declarar_let( (yyvsp[(1) - (1)]).c[0], (yyvsp[(1) - (1)]).linha, (yyvsp[(1) - (1)]).coluna );
            (yyval).c = (yyvsp[(1) - (1)]).c + "&"; 
        }
    break;

  case 40:
#line 185 "glc_js.y"
    {   if ( ja_declarou_var( (yyvsp[(1) - (3)]).c[0], (yyvsp[(1) - (3)]).linha, (yyvsp[(1) - (3)]).coluna ) )
                {
                    if ( (yyvsp[(3) - (3)]).c[0][0] == '-' )  (yyval).c = (yyvsp[(1) - (3)]).c + "0" + (yyvsp[(3) - (3)]).c[0].substr(1) + "-" + "=" + "^";
                    else  (yyval).c = (yyvsp[(1) - (3)]).c + (yyvsp[(3) - (3)]).c + "=" + "^";
                }

            else 
            {   if ( (yyvsp[(3) - (3)]).c[0][0] == '-' )  (yyval).c = (yyvsp[(1) - (3)]).c + "&" + (yyvsp[(1) - (3)]).c + "0" + (yyvsp[(3) - (3)]).c[0].substr(1) + "-" + "=" + "^";
                else  (yyval).c = (yyvsp[(1) - (3)]).c + "&" + (yyvsp[(1) - (3)]).c + (yyvsp[(3) - (3)]).c + "=" + "^";
            }
        }
    break;

  case 41:
#line 197 "glc_js.y"
    {   if( !ja_declarou_var( (yyvsp[(1) - (1)]).c[0], (yyvsp[(1) - (1)]).linha, (yyvsp[(1) - (1)]).coluna ) )
                (yyval).c = (yyvsp[(1) - (1)]).c + "&";
            else
                (yyval).c.clear(); }
    break;

  case 42:
#line 204 "glc_js.y"
    {   tenta_declarar_const( (yyvsp[(1) - (5)]).c[0], (yyvsp[(1) - (5)]).linha, (yyvsp[(1) - (5)]).coluna );
            if ( (yyvsp[(3) - (5)]).c[0][0] == '-' )  (yyval).c = (yyvsp[(1) - (5)]).c + "&" + (yyvsp[(1) - (5)]).c + "0" + (yyvsp[(3) - (5)]).c[0].substr(1) + "-" + "=" + "^" + (yyvsp[(5) - (5)]).c;
            else  (yyval).c = (yyvsp[(1) - (5)]).c + "&" + (yyvsp[(1) - (5)]).c + (yyvsp[(3) - (5)]).c + "=" + "^" + (yyvsp[(5) - (5)]).c;
        }
    break;

  case 43:
#line 209 "glc_js.y"
    {   tenta_declarar_const( (yyvsp[(1) - (3)]).c[0], (yyvsp[(1) - (3)]).linha, (yyvsp[(1) - (3)]).coluna );
            if ( (yyvsp[(3) - (3)]).c[0][0] == '-' )  (yyval).c = (yyvsp[(1) - (3)]).c + "&" + (yyvsp[(1) - (3)]).c + "0" + (yyvsp[(3) - (3)]).c[0].substr(1) + "-" + "=" + "^";
            else  (yyval).c = (yyvsp[(1) - (3)]).c + "&" + (yyvsp[(1) - (3)]).c + (yyvsp[(3) - (3)]).c + "=" + "^"; 
        }
    break;

  case 47:
#line 221 "glc_js.y"
    {  (yyval).c.clear(); (yyval).c.push_back("{}"); }
    break;

  case 48:
#line 225 "glc_js.y"
    {   const_declarado_check( (yyvsp[(1) - (3)]).c[0], (yyvsp[(1) - (3)]).linha, (yyvsp[(1) - (3)]).coluna );
        if ( (yyvsp[(3) - (3)]).c[(yyvsp[(3) - (3)]).c.size()-1] == "^" ) (yyvsp[(3) - (3)]).c.pop_back();
        (yyval).c = (yyvsp[(1) - (3)]).c + (yyvsp[(3) - (3)]).c + "=" + "^";
    }
    break;

  case 49:
#line 230 "glc_js.y"
    {   const_declarado_check( (yyvsp[(1) - (3)]).c[0], (yyvsp[(1) - (3)]).linha, (yyvsp[(1) - (3)]).coluna );
        (yyval).c = (yyvsp[(1) - (3)]).c + (yyvsp[(1) - (3)]).c + "@" + (yyvsp[(3) - (3)]).c + "+" + "=" + "^"; 
    }
    break;

  case 50:
#line 234 "glc_js.y"
    {   const_declarado_check( (yyvsp[(1) - (3)]).c[0], (yyvsp[(1) - (3)]).linha, (yyvsp[(1) - (3)]).coluna );
        (yyval).c = (yyvsp[(1) - (3)]).c + (yyvsp[(1) - (3)]).c + "@" + (yyvsp[(3) - (3)]).c + "-" + "=" + "^"; 
    }
    break;

  case 53:
#line 240 "glc_js.y"
    {   if ( (yyvsp[(1) - (2)]).c[(yyvsp[(1) - (2)]).c.size()-1] == "@" ) (yyvsp[(1) - (2)]).c.pop_back();
        (yyval).c = (yyvsp[(1) - (2)]).c + "@" + (yyvsp[(1) - (2)]).c + (yyvsp[(1) - (2)]).c + "@" + "1" + "+" + "=" + "^"; 
    }
    break;

  case 56:
#line 246 "glc_js.y"
    {   (yyval).c = (yyvsp[(1) - (5)]).c + (yyvsp[(3) - (5)]).c + (yyvsp[(5) - (5)]).c + "[=]" + "^"; }
    break;

  case 57:
#line 248 "glc_js.y"
    {   (yyval).c =  (yyvsp[(1) - (5)]).c + "@" + (yyvsp[(3) - (5)]).c + (yyvsp[(1) - (5)]).c + "@" + (yyvsp[(3) - (5)]).c + "[@]" + (yyvsp[(5) - (5)]).c + "+" + "=" + "^";}
    break;

  case 58:
#line 250 "glc_js.y"
    {   if ( (yyvsp[(3) - (6)]).c[(yyvsp[(3) - (6)]).c.size()-1] == "^" ) (yyvsp[(3) - (6)]).c.pop_back();
        (yyval).c = (yyvsp[(1) - (6)]).c + (yyvsp[(3) - (6)]).c + (yyvsp[(6) - (6)]).c + "[=]" + "^";
    }
    break;

  case 59:
#line 254 "glc_js.y"
    {   (yyval).c = (yyvsp[(1) - (8)]).c + (yyvsp[(3) - (8)]).c + "[@]" + (yyvsp[(5) - (8)]).c + (yyvsp[(8) - (8)]).c + "[=]" + "^";}
    break;

  case 61:
#line 257 "glc_js.y"
    {   (yyval).c =  (yyvsp[(1) - (8)]).c + (yyvsp[(3) - (8)]).c + "[@]" + (yyvsp[(5) - (8)]).c + (yyvsp[(1) - (8)]).c + (yyvsp[(3) - (8)]).c + "[@]" + (yyvsp[(5) - (8)]).c + "[@]" + (yyvsp[(8) - (8)]).c + "+" + "[=]" + "^";}
    break;

  case 62:
#line 258 "glc_js.y"
    { (yyval).c = (yyvsp[(1) - (3)]).c + (yyvsp[(3) - (3)]).c + "<"; }
    break;

  case 63:
#line 259 "glc_js.y"
    { (yyval).c = (yyvsp[(1) - (3)]).c + (yyvsp[(3) - (3)]).c + "*"; }
    break;

  case 64:
#line 260 "glc_js.y"
    { (yyval).c = (yyvsp[(1) - (3)]).c + (yyvsp[(3) - (3)]).c + "+"; }
    break;

  case 65:
#line 261 "glc_js.y"
    { (yyval).c = (yyvsp[(1) - (3)]).c + (yyvsp[(3) - (3)]).c + "-"; }
    break;

  case 66:
#line 262 "glc_js.y"
    { (yyval).c = (yyvsp[(1) - (3)]).c + (yyvsp[(3) - (3)]).c + "/"; }
    break;

  case 67:
#line 263 "glc_js.y"
    { (yyval).c = (yyvsp[(1) - (3)]).c + (yyvsp[(3) - (3)]).c + ">"; }
    break;

  case 68:
#line 264 "glc_js.y"
    { (yyval).c = (yyvsp[(1) - (3)]).c + (yyvsp[(3) - (3)]).c + "%"; }
    break;

  case 69:
#line 265 "glc_js.y"
    { (yyval).c = (yyvsp[(1) - (3)]).c + (yyvsp[(3) - (3)]).c + "=="; }
    break;

  case 71:
#line 269 "glc_js.y"
    { (yyval).c = (yyvsp[(1) - (1)]).c + "@"; }
    break;

  case 72:
#line 270 "glc_js.y"
    { (yyval).c = (yyvsp[(1) - (1)]).c; }
    break;

  case 73:
#line 271 "glc_js.y"
    { (yyval).c = (yyvsp[(1) - (1)]).c; }
    break;

  case 74:
#line 272 "glc_js.y"
    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 78:
#line 276 "glc_js.y"
    { (yyval).c.clear(); (yyval).c.push_back("[]");}
    break;

  case 81:
#line 279 "glc_js.y"
    { (yyval).c = (yyvsp[(1) - (3)]).c + (yyvsp[(3) - (3)]).c + "[@]"; }
    break;


/* Line 1267 of yacc.c.  */
#line 1937 "y.tab.c"
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
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
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


#line 297 "glc_js.y"


#include "lex.yy.c"

vector<string> concatena ( vector<string> a, vector<string> b ) {
  a.insert( a.end(), b.begin(), b.end() );
  return a;
}

void yyerror( const char* msg ) {
    cout << endl << "Erro: " << msg << endl
        << "Perto de : '" << yylval.c[0] << "'" << endl
        << "Linha: " << yylval.linha << ", coluna: " << yylval.coluna << endl;
  
  exit(1);
}

vector<string> operator+( vector<string> a, vector<string> b ) {
  return concatena( a, b );
}

vector<string> operator+( vector<string> a, string b ) {
  a.push_back( b );
  return a;
}

vector<string> operator+( string a, vector<string> b ) {
  vector<string> aux{ a };

  return aux + b;
}

string gera_label( string prefixo ) {
  static int n = 0;
  return prefixo + "_" + to_string( ++n ) + ":";
}

vector<string> resolve_enderecos( vector<string> entrada ) {
  map<string,int> label;
  vector<string> saida;
  for( int i = 0; i < entrada.size(); i++ ) 
    if( entrada[i][0] == ':' ) 
        label[entrada[i].substr(1)] = saida.size();
    else
      saida.push_back( entrada[i] );
  
  for( int i = 0; i < saida.size(); i++ ) 
    if( label.count( saida[i] ) > 0 )
        saida[i] = to_string(label[saida[i]]);
    
  return saida;
}

void imprime_codigo( vector<string> codigo ) {
    for( int i = 0; i < codigo.size(); i++ )
        cout << codigo[i] << " ";
}

void tenta_declarar_let( string nome, int linha, int coluna ){   
    if( ts.back().count( nome ) > 0 ) {
       erro("Erro: a variável '" + nome + "' já foi declarada na linha " + to_string( ts.back()[nome].linha ) + ".");
    }
    
    ts.back()[nome] = Simbolo{ linha, coluna, "let" }; 
}

void tenta_declarar_const( string nome, int linha, int coluna ){  
    if( ts.back().count( nome ) > 0 ) {
        erro("Erro: a variável '" + nome + "' já foi declarada na linha " + to_string( ts.back()[nome].linha ) + ".");
    }
    
    ts.back()[nome] = Simbolo{ linha, coluna, "const" }; 
}

bool ja_declarou_var( string nome, int linha, int coluna ){   
    if( ts.back().count( nome ) > 0 ) {
      if( ts.back()[nome].tipo_decl != "var" ) 
        erro("Erro: variável '" + nome + "' já foi declarada na linha " + to_string( ts.back()[nome].linha ) + ".");
      
      return true;
    }
    
    ts.back()[nome] = Simbolo{ linha, coluna, "var" }; 
    return false;
}

void const_declarado_check(string nome, int linha, int coluna) {
    if( ts.back().count( nome ) > 0 ) {
        if( ts.back()[nome].tipo_decl == "const" ) 
            erro("Erro: a variável '" + nome + "' já foi declarada na linha " + to_string( ts.back()[nome].linha ) + ".");
    } else {
        erro("Erro: a variável '" + nome + "' não foi declarada.");
    }
}

void erro( string msg ) {
    cout << msg << endl;
    exit( 1 );
}
