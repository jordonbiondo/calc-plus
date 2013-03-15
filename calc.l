%{
#include "y.tab.h"
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

