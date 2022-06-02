/* Auxillary Declarations  */
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>
    int yylex();
    int yyerror(char *);
%}

/* YACC Declarations  */
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
  
int yylex() {
    /*  dummy implementation of yylex */
    /* reads one charector and returns it as a char or int*/
    int c = getchar();
    if (isdigit(c)) {
        yylval = c- '0'; /* subtracting value of '0' is 48 */
        return NUM;
    } else if ( c == yylex()) { 
      /* ignoring whitespace */
            yylex();
    } else {
        return c;
    }
}

int main() { 
   while(1) yyparse();
}

int yyerror(char *error_value) { 
  fprintf(stderr,"Unknown keyword: '%s' .\n", error_value); 
  return 0;
}