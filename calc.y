/* calc.y --- yacc for calc+
 * 
 * Filename: calc.y - yacc for calc+
 * Author: Jordon Biondo
 * Maintainer: Jordon Biondo
 * Created: Fri Mar 15 00:58:33 2013 (-0400)
 * Version: .1
 * Last-Updated: Fri Mar 15 10:33:15 2013 (-0400)
 *           By: Jordon Biondo
 *     Update #: 14
 */


%{
void yyerror (char *s);
#include <stdio.h>     /* C declarations used in actions */
#include <stdlib.h>
#include "hash.h"
hashmap* map;
int symbolVal(char* symbol);

%}

%union {int num; char* id;}         /* Yacc definitions */
%start line
%token print
%token exit_command
%token <num> number
%token <id> identifier
%type <num> line exp term 
%type <id> assignment
%nonassoc '('
%left '+' '-'
%left '*' '/'

%%

//;
line 
: assignment ';'   {;}
| exit_command ';'      {(EXIT_SUCCESS);}
| print exp ';'	        {printf("= %d\n", $2);}
| exp ';'	        {printf("= %d\n", $1);}
| line assignment ';'   {;}
| line print exp ';'    {printf("= %d\n", $3);}
| line exp ';'          {printf("= %d\n", $2);}
| line exit_command ';'	{exit(EXIT_SUCCESS);}
;

assignment 
: identifier '=' exp { hm_put(map, $1, $3);};

exp    	
: term             {$$ = $1;}
| exp '*' exp      {$$ = $1 * $3;}
| exp '/' exp      {$$ = $1 / $3;}
| exp '+' exp      {$$ = $1 + $3;}
| '(' exp ')'      {$$ = $2;}
| exp '-' exp      {$$ = $1 - $3;}
;


term 
: number {$$ = $1;}
| identifier { $$ = symbolVal($1);}
;

%%
/* C code */


//returns the value of a given symbol
int symbolVal(char* symbol) {
  if (hm_find(map, symbol)) {
    return map->sought;
  } else {
    hm_put(map, symbol, 0);
    return 0;
  }
}

int main(void) {
  map = hm_new(DEFAULT_HASHMAP_SIZE);
  return yyparse();
}

void yyerror (char *s) {
  fprintf (stderr, "%s\n", s);
} 

