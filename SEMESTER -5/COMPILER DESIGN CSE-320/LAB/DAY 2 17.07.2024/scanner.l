
%{
    #include <stdio.h>
%}

%%
"/\*"([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+"/"           printf("%s is comment\n",yytext);
%%

/*** C Code section ***/
int main(void)
{
    yylex();
    return 0;
}

int yywrap(){
    return 1;
}