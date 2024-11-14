%{
#include <stdio.h>
int comment = 0;
%}

identifier [a-zA-Z][a-zA-Z0-9]*

%%

#.* {printf("\n%s is preprocessor directives ",yytext);}
"/*" {comment = 1;printf("\n%s",yytext);}
"*/" {comment = 0;printf("\n%s",yytext);}

printf |
void |
main |
int {if(!comment) printf("\n%s is keyword",yytext);}

{identifier}\(.* {if(!comment) printf("%s is function",yytext);}
{identifier} {if(!comment) printf("\n%s is identifier",yytext);}
\".*\" {if(!comment) printf("\n%s is string",yytext);}
= {if(!comment) printf("\n%s is assignment",yytext);}
[0-9]+ {if(!comment) printf("\n%s is number",yytext);}
%%

void main(){
    FILE *file;
    file = fopen("var.c","r");
    if(!file){
        printf("error");
    }
    yyin = file;
    yylex();
}

int yywrap(){
    return(1);
}