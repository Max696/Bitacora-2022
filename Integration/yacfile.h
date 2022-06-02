%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>
    int yylex();
    int yyerror(char *);
%}

/* YACC Declaintions  */
%token  NUM   
%left  '+'  '-'
%left   '*'  '/'

/* Rules */
%%
start:  expr {
        printf("result: %d\n", $$);
        return 0;
}
    ;
expr: expr'+'expr          { $$=$1+$3;}
    | expr'-'expr          { $$=$1-$3;}
    | expr'*'expr          { $$=$1*$3;}
    | expr'/'expr          { $$=$1/$3;}
    | NUM                  { $$=$1;}
    ;
%%

/* Auxiliary functions */
int main() { 
   while(1) {
       printf(">>> ");
    yyparse();
   }
}