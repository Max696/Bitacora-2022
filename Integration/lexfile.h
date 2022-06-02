/* Declarations */
%{                          
    #include <stdio.h>           /* imports */   
    #include <stdlib.h>
    #include "y.tab.h"
    int yyerror(char*);       /* function prototype */
%}
     
/* rules */
%%
[0-9]+                           { yylval= atoi(yytext); return NUM; }    
[ \t] ;
[\n]                              return 0;   
.                                 return yytext[0];
%%

/* Auxiliary functions */
int yywrap(void) { 
  return 1;
}

int yyerror(char *error_value) { 
  fprintf(stderr,"error: '%s'\n", error_value); 
  return 0;
}