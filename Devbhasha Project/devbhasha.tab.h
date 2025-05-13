
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 55 "devbhasha.y"

    int ival;
    float fval;
    char cval;
    char* sval;
    int bval;
    struct ExpressionResult* expr;



/* Line 1676 of yacc.c  */
#line 137 "devbhasha.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


