%{
#include <stdio.h>
%}

%%
\#include\ ?\<[a-zA-Z]+(.h)?\>             { printf("%s is preprocessor directive\n",yytext); }
int|void                                {printf("%s is reserved keyword\n",yytext);}
[a-zA-Z_][a-zA-Z0-9_]*\(\)              {printf("%s is function\n",yytext);}
\{                                      {printf("%s block begins\n",yytext);}
\}                                      {printf("%s block ends\n",yytext);}
[a-zA-Z_][a-zA-Z0-9_]*\(                {printf("%s function begins \n",yytext);}
\".+\"                                  {printf("%s is string\n",yytext);}
(");")                                   {printf("%s function ends\n",yytext);}
\)|\;                                    {printf("%s is symbol\n",yytext);}
[/]{2}|"/*".*|(\n)*"*/"                  {printf("%s is comment\n",yytext);}       
[a-zA-Z_]+[a-zA-Z0-9_]*                   {printf("%s is variable \n",yytext);}
.|\n                                     {} 
%%

int main(void)
{
    yylex();
    return 0;
}

int yywrap()
{
    return 1; // Indicate no more input
}
