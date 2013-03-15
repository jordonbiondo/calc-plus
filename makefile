calc: lex.yy.c y.tab.c hash.h linkedvars.h
	gcc -g lex.yy.c y.tab.c -o calc

lex.yy.c: y.tab.c calc.l
	lex calc.l

y.tab.c: calc.y
	yacc -d calc.y

clean: 
	rm -f lex.yy.c y.tab.c y.tab.h calc

