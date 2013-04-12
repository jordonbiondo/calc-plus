/* calc.l --- flex for calc+
 *
 * Filename: calc.l - flex for calc+
 * Author: Jordon Biondo
 * Maintainer: Jordon Biondo
 * Created: Fri Mar 15 00:58:32 2013 (-0400)
 * Version: .1
 * Last-Updated: Fri Mar 15 10:30:49 2013 (-0400)
 *           By: Jordon Biondo
 *     Update #: 9
 */


/* Code: */


%{
#include "y.tab.h"
#include <string.h>
%}

%%

"print"	 {
  return print;
}
"exit" {
  return exit_command;
}

[a-zA-Z]+ {
  yylval.id = strdup(yytext);
  return identifier;

}

[0-9]+ {
  yylval.num = atoi(yytext); return number;
}

[ \t\n] ;

[()\/\*\-+=;] {
  return yytext[0];
}

. {
  ECHO;
  yyerror ("unexpected character");
}

%%

int yywrap (void) {return 1;}


/* calc.l ends here */
