%{
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

%}

%union {
    int ival;
    float fval;
    char cval;
    char* sval;
    int bval;
    struct ExpressionResult* expr;
}

/* Define token precedence hierarchy (lowest to highest) */
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%right ASSIGN PLUS_ASSIGN MINUS_ASSIGN TIMES_ASSIGN DIVIDE_ASSIGN MOD_ASSIGN
%left OR
%left AND
%left EQ NEQ
%left LT GT LTE GTE
%left PLUS MINUS
%left TIMES DIVIDE MOD
%right NOT
%right INCREMENT DECREMENT

%token PROGRAM END VAR CONST RETURN NEW
%token BOOL INT FLOAT CHAR STRING NULL_TYPE MAP
%token IF ELSE_IF ELSE FOR WHILE DO BREAK CONTINUE
%token FUNCTION CLASS CONSTRUCTOR EXTENDS
%token READ PRINT
%token TRY CATCH FINALLY THROW
%token THIS SUPER

%token PLUS MINUS TIMES DIVIDE MOD
%token INCREMENT DECREMENT
%token EQ NEQ GT LT GTE LTE
%token AND OR NOT
%token ASSIGN PLUS_ASSIGN MINUS_ASSIGN TIMES_ASSIGN DIVIDE_ASSIGN MOD_ASSIGN

%token LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET
%token SEMICOLON COMMA DOT COLON

%token <ival> INT_LITERAL
%token <fval> FLOAT_LITERAL
%token <cval> CHAR_LITERAL
%token <sval> STRING_LITERAL
%token <bval> BOOL_LITERAL
%token <sval> IDENTIFIER

%type <expr> statement statement_list program_body program program_declaration
%type <expr> block_statement expression
%type <expr> variable_declaration assignment_expression
%type <expr> logical_or_expression logical_and_expression
%type <expr> equality_expression relational_expression
%type <expr> additive_expression multiplicative_expression
%type <expr> unary_expression postfix_expression primary_expression
%type <expr> if_statement while_statement for_statement
%type <expr> function_declaration function_call
%type <expr> return_statement print_statement
%type <expr> type basic_type array_type map_type
%type <expr> argument_list parameter_list parameter

%start program_start

%%

program_start:
    program
    ;

program:
    program_body
    {
        /* Complete program */
    }
    ;

program_body:
    program_declaration
    {
        $$ = $1;
    }
    | function_declaration
    {
        $$ = $1;
    }
    | program_body function_declaration
    {
        $$ = $1;
        append_code($$, $2->code);
    }
    ;

program_declaration:
    PROGRAM IDENTIFIER LBRACE statement_list RBRACE END
    {
        $$ = $4;
        printf("// Three-address code for Devbhasha program '%s'\n", $2);
        printf("%s", $4->code);
    }
    ;

statement_list:
    statement
    {
        $$ = $1;
    }
    | statement_list statement
    {
        $$ = $1;
        append_code($$, $2->code);
    }
    ;

statement:
    variable_declaration SEMICOLON
    {
        $$ = $1;
    }
    | assignment_expression SEMICOLON
    {
        $$ = $1;
    }
    | expression SEMICOLON
    {
        $$ = $1;
    }
    | if_statement
    {
        $$ = $1;
    }
    | while_statement
    {
        $$ = $1;
    }
    | for_statement
    {
        $$ = $1;
    }
    | function_call SEMICOLON
    {
        $$ = $1;
    }
    | block_statement
    {
        $$ = $1;
    }
    | return_statement SEMICOLON
    {
        $$ = $1;
    }
    | print_statement SEMICOLON
    {
        $$ = $1;
    }
    | BREAK SEMICOLON
    {
        $$ = create_expr_result();
        append_code($$, "break\n");
    }
    | CONTINUE SEMICOLON
    {
        $$ = create_expr_result();
        append_code($$, "continue\n");
    }
    | SEMICOLON
    {
        $$ = create_expr_result();
    }
    ;

block_statement:
    LBRACE statement_list RBRACE
    {
        $$ = $2;
    }
    | LBRACE RBRACE
    {
        $$ = create_expr_result();
    }
    ;

variable_declaration:
    VAR type IDENTIFIER
    {
        $$ = create_expr_result();
        char code[128];
        sprintf(code, "// Declaration: %s\n", $3);
        append_code($$, code);
    }
    | VAR type IDENTIFIER ASSIGN expression
    {
        $$ = $5;
        char code[128];
        sprintf(code, "%s = %s\n", $3, $5->addr);
        append_code($$, code);
    }
    | CONST type IDENTIFIER ASSIGN expression
    {
        $$ = $5;
        char code[128];
        sprintf(code, "// Constant declaration\n%s = %s\n", $3, $5->addr);
        append_code($$, code);
    }
    ;

type:
    basic_type
    {
        $$ = $1;
    }
    | array_type
    {
        $$ = $1;
    }
    | map_type
    {
        $$ = $1;
    }
    ;

basic_type:
    BOOL 
    { 
        $$ = create_expr_result(); 
    }
    | INT 
    { 
        $$ = create_expr_result(); 
    }
    | FLOAT 
    { 
        $$ = create_expr_result(); 
    }
    | CHAR 
    { 
        $$ = create_expr_result(); 
    }
    | STRING 
    { 
        $$ = create_expr_result(); 
    }
    | NULL_TYPE 
    { 
        $$ = create_expr_result(); 
    }
    ;

array_type:
    basic_type LBRACKET RBRACKET
    {
        $$ = $1;
    }
    ;

map_type:
    MAP LT type COMMA type GT
    { 
        $$ = create_expr_result(); 
    }
    ;

assignment_expression:
    IDENTIFIER ASSIGN expression
    {
        $$ = $3;
        char code[128];
        sprintf(code, "%s = %s\n", $1, $3->addr);
        append_code($$, code);
    }
    | IDENTIFIER PLUS_ASSIGN expression
    {
        $$ = create_expr_result();
        $$->addr = new_temp();
        char code[256];
        sprintf(code, "%s = %s + %s\n%s = %s\n", 
                $$->addr, $1, $3->addr, $1, $$->addr);
        append_code($$, $3->code);
        append_code($$, code);
    }
    | IDENTIFIER MINUS_ASSIGN expression
    {
        $$ = create_expr_result();
        $$->addr = new_temp();
        char code[256];
        sprintf(code, "%s = %s - %s\n%s = %s\n", 
                $$->addr, $1, $3->addr, $1, $$->addr);
        append_code($$, $3->code);
        append_code($$, code);
    }
    | IDENTIFIER TIMES_ASSIGN expression
    {
        $$ = create_expr_result();
        $$->addr = new_temp();
        char code[256];
        sprintf(code, "%s = %s * %s\n%s = %s\n", 
                $$->addr, $1, $3->addr, $1, $$->addr);
        append_code($$, $3->code);
        append_code($$, code);
    }
    | IDENTIFIER DIVIDE_ASSIGN expression
    {
        $$ = create_expr_result();
        $$->addr = new_temp();
        char code[256];
        sprintf(code, "%s = %s / %s\n%s = %s\n", 
                $$->addr, $1, $3->addr, $1, $$->addr);
        append_code($$, $3->code);
        append_code($$, code);
    }
    | IDENTIFIER MOD_ASSIGN expression
    {
        $$ = create_expr_result();
        $$->addr = new_temp();
        char code[256];
        sprintf(code, "%s = %s %% %s\n%s = %s\n", 
                $$->addr, $1, $3->addr, $1, $$->addr);
        append_code($$, $3->code);
        append_code($$, code);
    }
    ;

expression:
    logical_or_expression
    {
        $$ = $1;
    }
    ;

logical_or_expression:
    logical_and_expression
    {
        $$ = $1;
    }
    | logical_or_expression OR logical_and_expression
    {
        $$ = create_expr_result();
        $$->addr = new_temp();
        append_code($$, $1->code);
        append_code($$, $3->code);
        char code[128];
        sprintf(code, "%s = %s || %s\n", $$->addr, $1->addr, $3->addr);
        append_code($$, code);
    }
    ;

logical_and_expression:
    equality_expression
    {
        $$ = $1;
    }
    | logical_and_expression AND equality_expression
    {
        $$ = create_expr_result();
        $$->addr = new_temp();
        append_code($$, $1->code);
        append_code($$, $3->code);
        char code[128];
        sprintf(code, "%s = %s && %s\n", $$->addr, $1->addr, $3->addr);
        append_code($$, code);
    }
    ;

equality_expression:
    relational_expression
    {
        $$ = $1;
    }
    | equality_expression EQ relational_expression
    {
        $$ = create_expr_result();
        $$->addr = new_temp();
        append_code($$, $1->code);
        append_code($$, $3->code);
        char code[128];
        sprintf(code, "%s = %s == %s\n", $$->addr, $1->addr, $3->addr);
        append_code($$, code);
    }
    | equality_expression NEQ relational_expression
    {
        $$ = create_expr_result();
        $$->addr = new_temp();
        append_code($$, $1->code);
        append_code($$, $3->code);
        char code[128];
        sprintf(code, "%s = %s != %s\n", $$->addr, $1->addr, $3->addr);
        append_code($$, code);
    }
    ;

relational_expression:
    additive_expression
    {
        $$ = $1;
    }
    | relational_expression LT additive_expression
    {
        $$ = create_expr_result();
        $$->addr = new_temp();
        append_code($$, $1->code);
        append_code($$, $3->code);
        char code[128];
        sprintf(code, "%s = %s < %s\n", $$->addr, $1->addr, $3->addr);
        append_code($$, code);
    }
    | relational_expression GT additive_expression
    {
        $$ = create_expr_result();
        $$->addr = new_temp();
        append_code($$, $1->code);
        append_code($$, $3->code);
        char code[128];
        sprintf(code, "%s = %s > %s\n", $$->addr, $1->addr, $3->addr);
        append_code($$, code);
    }
    | relational_expression LTE additive_expression
    {
        $$ = create_expr_result();
        $$->addr = new_temp();
        append_code($$, $1->code);
        append_code($$, $3->code);
        char code[128];
        sprintf(code, "%s = %s <= %s\n", $$->addr, $1->addr, $3->addr);
        append_code($$, code);
    }
    | relational_expression GTE additive_expression
    {
        $$ = create_expr_result();
        $$->addr = new_temp();
        append_code($$, $1->code);
        append_code($$, $3->code);
        char code[128];
        sprintf(code, "%s = %s >= %s\n", $$->addr, $1->addr, $3->addr);
        append_code($$, code);
    }
    ;

additive_expression:
    multiplicative_expression
    {
        $$ = $1;
    }
    | additive_expression PLUS multiplicative_expression
    {
        $$ = create_expr_result();
        $$->addr = new_temp();
        append_code($$, $1->code);
        append_code($$, $3->code);
        char code[128];
        sprintf(code, "%s = %s + %s\n", $$->addr, $1->addr, $3->addr);
        append_code($$, code);
    }
    | additive_expression MINUS multiplicative_expression
    {
        $$ = create_expr_result();
        $$->addr = new_temp();
        append_code($$, $1->code);
        append_code($$, $3->code);
        char code[128];
        sprintf(code, "%s = %s - %s\n", $$->addr, $1->addr, $3->addr);
        append_code($$, code);
    }
    | STRING_LITERAL PLUS expression
    {
        $$ = create_expr_result();
        $$->addr = new_temp();
        append_code($$, $3->code);
        char code[256];
        sprintf(code, "%s = concat(%s, %s)\n", $$->addr, $1, $3->addr);
        append_code($$, code);
    }
    | expression PLUS STRING_LITERAL
    {
        $$ = create_expr_result();
        $$->addr = new_temp();
        append_code($$, $1->code);
        char code[256];
        sprintf(code, "%s = concat(%s, %s)\n", $$->addr, $1->addr, $3);
        append_code($$, code);
    }
    ;

multiplicative_expression:
    unary_expression
    {
        $$ = $1;
    }
    | multiplicative_expression TIMES unary_expression
    {
        $$ = create_expr_result();
        $$->addr = new_temp();
        append_code($$, $1->code);
        append_code($$, $3->code);
        char code[128];
        sprintf(code, "%s = %s * %s\n", $$->addr, $1->addr, $3->addr);
        append_code($$, code);
    }
    | multiplicative_expression DIVIDE unary_expression
    {
        $$ = create_expr_result();
        $$->addr = new_temp();
        append_code($$, $1->code);
        append_code($$, $3->code);
        char code[128];
        sprintf(code, "%s = %s / %s\n", $$->addr, $1->addr, $3->addr);
        append_code($$, code);
    }
    | multiplicative_expression MOD unary_expression
    {
        $$ = create_expr_result();
        $$->addr = new_temp();
        append_code($$, $1->code);
        append_code($$, $3->code);
        char code[128];
        sprintf(code, "%s = %s %% %s\n", $$->addr, $1->addr, $3->addr);
        append_code($$, code);
    }
    ;

unary_expression:
    postfix_expression
    {
        $$ = $1;
    }
    | NOT unary_expression
    {
        $$ = create_expr_result();
        $$->addr = new_temp();
        append_code($$, $2->code);
        char code[128];
        sprintf(code, "%s = !%s\n", $$->addr, $2->addr);
        append_code($$, code);
    }
    | MINUS unary_expression
    {
        $$ = create_expr_result();
        $$->addr = new_temp();
        append_code($$, $2->code);
        char code[128];
        sprintf(code, "%s = -%s\n", $$->addr, $2->addr);
        append_code($$, code);
    }
    ;

postfix_expression:
    primary_expression
    {
        $$ = $1;
    }
    | IDENTIFIER INCREMENT
    {
        $$ = create_expr_result();
        $$->addr = new_temp();
        char code[128];
        sprintf(code, "%s = %s\n%s = %s + 1\n", $$->addr, $1, $1, $1);
        append_code($$, code);
    }
    | IDENTIFIER DECREMENT
    {
        $$ = create_expr_result();
        $$->addr = new_temp();
        char code[128];
        sprintf(code, "%s = %s\n%s = %s - 1\n", $$->addr, $1, $1, $1);
        append_code($$, code);
    }
    ;

primary_expression:
    IDENTIFIER
    {
        $$ = create_expr_result();
        $$->addr = strdup($1);
    }
    | INT_LITERAL
    {
        $$ = create_expr_result();
        $$->addr = (char*)malloc(16);
        sprintf($$->addr, "%d", $1);
    }
    | FLOAT_LITERAL
    {
        $$ = create_expr_result();
        $$->addr = (char*)malloc(16);
        sprintf($$->addr, "%f", $1);
    }
    | CHAR_LITERAL
    {
        $$ = create_expr_result();
        $$->addr = (char*)malloc(8);
        sprintf($$->addr, "'%c'", $1);
    }
    | STRING_LITERAL
    {
        $$ = create_expr_result();
        $$->addr = strdup($1);
    }
    | BOOL_LITERAL
    {
        $$ = create_expr_result();
        $$->addr = strdup($1 ? "haan" : "nahi");
    }
    | LPAREN expression RPAREN
    {
        $$ = $2;
    }
    | function_call
    {
        $$ = $1;
    }
    ;

if_statement:
    IF LPAREN expression RPAREN block_statement %prec LOWER_THAN_ELSE
    {
        $$ = create_expr_result();
        char* true_label = new_label();
        char* end_label = new_label();
        
        append_code($$, $3->code);
        
        char code[256];
        sprintf(code, "if %s goto %s\ngoto %s\n%s:\n", 
                $3->addr, true_label, end_label, true_label);
        append_code($$, code);
        
        append_code($$, $5->code);
        
        sprintf(code, "%s:\n", end_label);
        append_code($$, code);
    }
    | IF LPAREN expression RPAREN block_statement ELSE block_statement
    {
        $$ = create_expr_result();
        char* true_label = new_label();
        char* false_label = new_label();
        char* end_label = new_label();
        
        append_code($$, $3->code);
        
        char code[256];
        sprintf(code, "if %s goto %s\ngoto %s\n%s:\n", 
                $3->addr, true_label, false_label, true_label);
        append_code($$, code);
        
        append_code($$, $5->code);
        
        sprintf(code, "goto %s\n%s:\n", end_label, false_label);
        append_code($$, code);
        
        append_code($$, $7->code);
        
        sprintf(code, "%s:\n", end_label);
        append_code($$, code);
    }
    ;

while_statement:
    WHILE LPAREN expression RPAREN block_statement
    {
        $$ = create_expr_result();
        char* begin_label = new_label();
        char* true_label = new_label();
        char* end_label = new_label();
        
        char code[256];
        sprintf(code, "%s:\n", begin_label);
        append_code($$, code);
        
        append_code($$, $3->code);
        
        sprintf(code, "if %s goto %s\ngoto %s\n%s:\n", 
                $3->addr, true_label, end_label, true_label);
        append_code($$, code);
        
        append_code($$, $5->code);
        
        sprintf(code, "goto %s\n%s:\n", begin_label, end_label);
        append_code($$, code);
    }
    | DO block_statement WHILE LPAREN expression RPAREN SEMICOLON
    {
        $$ = create_expr_result();
        char* begin_label = new_label();
        char* continue_label = new_label();
        
        char code[256];
        sprintf(code, "%s:\n", begin_label);
        append_code($$, code);
        
        append_code($$, $2->code);
        
        sprintf(code, "%s:\n", continue_label);
        append_code($$, code);
        
        append_code($$, $5->code);
        
        sprintf(code, "if %s goto %s\n", $5->addr, begin_label);
        append_code($$, code);
    }
    ;

for_statement:
    FOR LPAREN variable_declaration SEMICOLON expression SEMICOLON assignment_expression RPAREN block_statement
    {
        $$ = create_expr_result();
        char* begin_label = new_label();
        char* true_label = new_label();
        char* end_label = new_label();
        
        append_code($$, $3->code);
        
        char code[256];
        sprintf(code, "%s:\n", begin_label);
        append_code($$, code);
        
        append_code($$, $5->code);
        
        sprintf(code, "if %s goto %s\ngoto %s\n%s:\n", 
                $5->addr, true_label, end_label, true_label);
        append_code($$, code);
        
        append_code($$, $9->code);
        append_code($$, $7->code);
        
        sprintf(code, "goto %s\n%s:\n", begin_label, end_label);
        append_code($$, code);
    }
    | FOR LPAREN assignment_expression SEMICOLON expression SEMICOLON assignment_expression RPAREN block_statement
    {
        $$ = create_expr_result();
        char* begin_label = new_label();
        char* true_label = new_label();
        char* end_label = new_label();
        
        append_code($$, $3->code);
        
        char code[256];
        sprintf(code, "%s:\n", begin_label);
        append_code($$, code);
        
        append_code($$, $5->code);
        
        sprintf(code, "if %s goto %s\ngoto %s\n%s:\n", 
                $5->addr, true_label, end_label, true_label);
        append_code($$, code);
        
        append_code($$, $9->code);
        append_code($$, $7->code);
        
        sprintf(code, "goto %s\n%s:\n", begin_label, end_label);
        append_code($$, code);
    }
    | FOR LPAREN SEMICOLON expression SEMICOLON assignment_expression RPAREN block_statement
    {
        $$ = create_expr_result();
        char* begin_label = new_label();
        char* true_label = new_label();
        char* end_label = new_label();
        
        char code[256];
        sprintf(code, "%s:\n", begin_label);
        append_code($$, code);
        
        append_code($$, $4->code);
        
        sprintf(code, "if %s goto %s\ngoto %s\n%s:\n", 
                $4->addr, true_label, end_label, true_label);
        append_code($$, code);
        
        append_code($$, $8->code);
        append_code($$, $6->code);
        
        sprintf(code, "goto %s\n%s:\n", begin_label, end_label);
        append_code($$, code);
    }
    ;

function_declaration:
    FUNCTION type IDENTIFIER LPAREN parameter_list RPAREN block_statement
    {
        $$ = create_expr_result();
        char code[256];
        sprintf(code, "// Function: %s\n", $3);
        append_code($$, code);
        sprintf(code, "func %s:\n", $3);
        append_code($$, code);
        append_code($$, $7->code);
        append_code($$, "return\n");
    }
    | FUNCTION type IDENTIFIER LPAREN RPAREN block_statement
    {
        $$ = create_expr_result();
        char code[256];
        sprintf(code, "// Function: %s\n", $3);
        append_code($$, code);
        sprintf(code, "func %s:\n", $3);
        append_code($$, code);
        append_code($$, $6->code);
        append_code($$, "return\n");
    }
    ;

parameter_list:
    parameter
    {
        $$ = $1;
    }
    | parameter_list COMMA parameter
    {
        $$ = $1;
    }
    ;

parameter:
    type IDENTIFIER
    {
        $$ = create_expr_result();
    }
    ;

function_call:
    IDENTIFIER LPAREN RPAREN
    {
        $$ = create_expr_result();
        char code[128];
        $$->addr = new_temp();
        sprintf(code, "// Function call: %s\n", $1);
        append_code($$, code);
        sprintf(code, "%s = call %s\n", $$->addr, $1);
        append_code($$, code);
    }
    | IDENTIFIER LPAREN argument_list RPAREN
    {
        $$ = create_expr_result();
        char code[128];
        $$->addr = new_temp();
        sprintf(code, "// Function call: %s\n", $1);
        append_code($$, code);
        sprintf(code, "%s = call %s\n", $$->addr, $1);
        append_code($$, code);
    }
    ;

argument_list:
    expression
    {
        $$ = create_expr_result();
        append_code($$, $1->code);
    }
    | argument_list COMMA expression
    {
        $$ = $1;
        append_code($$, $3->code);
    }
    ;

return_statement:
    RETURN expression
    {
        $$ = create_expr_result();
        append_code($$, $2->code);
        char code[128];
        sprintf(code, "return %s\n", $2->addr);
        append_code($$, code);
    }
    | RETURN
    {
        $$ = create_expr_result();
        append_code($$, "return\n");
    }
    ;

print_statement:
    PRINT LPAREN expression RPAREN
    {
        $$ = create_expr_result();
        append_code($$, $3->code);
        char code[128];
        sprintf(code, "print %s\n", $3->addr);
        append_code($$, code);
    }
    ;

%%

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