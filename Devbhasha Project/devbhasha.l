%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "devbhasha.tab.h"  /* Use the correct header filename */

extern void yyerror(const char *);
int line_num = 1;
%}

%%

[ \t]+                  /* ignore whitespace */
"//".*                  /* ignore single line comments */
"/*"([^*]|"*"[^/])*"*/" /* ignore multi-line comments */
\n                      { line_num++; }

"dharma"                { return PROGRAM; }
"samapti"               { return END; }
"prakruti"              { return VAR; }
"nitya"                 { return CONST; }
"lautana"               { return RETURN; }
"nava"                  { return NEW; }

"satya"                 { return BOOL; }
"sankhya"               { return INT; }
"dashamika"             { return FLOAT; }
"akshara"               { return CHAR; }
"shabda"                { return STRING; }
"shunya"                { return NULL_TYPE; }
"kosha"                 { return MAP; }

"haan"                  { yylval.bval = 1; return BOOL_LITERAL; }
"nahi"                  { yylval.bval = 0; return BOOL_LITERAL; }

"yadi"                  { return IF; }
"athava"                { return ELSE_IF; }
"anyatha"               { return ELSE; }
"chakra"                { return FOR; }
"yavat"                 { return WHILE; }
"kuru"                  { return DO; }
"virama"                { return BREAK; }
"agre"                  { return CONTINUE; }

"karma"                 { return FUNCTION; }
"varga"                 { return CLASS; }
"nirmata"               { return CONSTRUCTOR; }
"prachina"              { return EXTENDS; }

"pathana"               { return READ; }
"lekha"                 { return PRINT; }

"prayatna"              { return TRY; }
"dosha"                 { return CATCH; }
"antima"                { return FINALLY; }

"throw"                 { return THROW; }

"swayam"                { return THIS; }
"param"                 { return SUPER; }

[0-9]+                  { yylval.ival = atoi(yytext); return INT_LITERAL; }
[0-9]+"."[0-9]+         { yylval.fval = atof(yytext); return FLOAT_LITERAL; }
\"([^\\\"]|\\.)*\"      { 
                          yylval.sval = strdup(yytext); 
                          return STRING_LITERAL; 
                        }
\'([^\\\']|\\.)?\'      { 
                          yylval.cval = yytext[1]; 
                          return CHAR_LITERAL; 
                        }

"+"                     { return PLUS; }
"-"                     { return MINUS; }
"*"                     { return TIMES; }
"/"                     { return DIVIDE; }
"%"                     { return MOD; }
"++"                    { return INCREMENT; }
"--"                    { return DECREMENT; }

"=="                    { return EQ; }
"!="                    { return NEQ; }
">"                     { return GT; }
"<"                     { return LT; }
">="                    { return GTE; }
"<="                    { return LTE; }

"&&"                    { return AND; }
"||"                    { return OR; }
"!"                     { return NOT; }

"="                     { return ASSIGN; }
"+="                    { return PLUS_ASSIGN; }
"-="                    { return MINUS_ASSIGN; }
"*="                    { return TIMES_ASSIGN; }
"/="                    { return DIVIDE_ASSIGN; }
"%="                    { return MOD_ASSIGN; }

"("                     { return LPAREN; }
")"                     { return RPAREN; }
"{"                     { return LBRACE; }
"}"                     { return RBRACE; }
"["                     { return LBRACKET; }
"]"                     { return RBRACKET; }
":"                     { return COLON; }
";"                     { return SEMICOLON; }
","                     { return COMMA; }
"."                     { return DOT; }

[a-zA-Z_][a-zA-Z0-9_]*  { 
                          yylval.sval = strdup(yytext); 
                          return IDENTIFIER; 
                        }

.                       { yyerror("Invalid character"); }

%%

int yywrap(void) {
    return 1;
}