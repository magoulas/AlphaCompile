/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
#line 99 "parserM.y" /* yacc.c:1909  */

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

#line 177 "parser.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
