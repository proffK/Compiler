/*!
 * Grammar:
 * GO ::= program;
 * program ::= {statement} 
 * statement ::= while | "{" program "}"
 * while ::= "<?>" (comparation) "{" program "}" | if 
 * if ::= "!?!" (comparation) "{" program "}" | function ";"
 * comporation ::= {expression} [<>=] {expression}
 * function ::= asg_expression | {expression} "->"
 * asg_expression ::= "=" function
 * expression ::= operator
 * operator ::= 2pr_operator
 * 2pr_operator ::= {1pr_operator} ["-" | "+"]
 * 1pr_operator ::= {0pr_operator} ["*" | "/"]
 * 0pr_operator ::= diff_ex | ["sin" | "cos"]  {paren_expression} ["^"]
 * diff_ex ::= ["(d/dx)"] paren_expression
 * paren_expression ::= "(" expression ")" | term
 * term ::= number | variable | stream | string
 * variable ::= [a-z]
 * number ::= [double]
 * stream ::= [IN] | [OUT] | [ERR]
*/

#ifndef PK_SYN
#define PK_SYN
#include <stdio.h>
#include "token.h"
#include "pk_tree.h"
#include "pk_sem.h"
#include "pk_diff.h"

int syntax_analize(token* source, FILE* out_file);

node* get_program(void);

node* get_statement(void);

node* get_while(void);

node* get_if(void);

node* get_comp(void);

node* get_function(void);

node* get_asg(void);

node* get_expression(void);

node* get_paren(void);

node* get_operator(void);

node* get_2pr(void);

node* get_1pr(void);

node* get_0pr(void);

node* get_diff(void);

node* get_term(void);

node* get_var(void);
#endif
