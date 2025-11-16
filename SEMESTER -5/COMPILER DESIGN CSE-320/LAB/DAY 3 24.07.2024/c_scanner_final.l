%{
#include <stdio.h>
int count = 1;
%}




%%
\#include\ ?\<[a-zA-Z]+(.h)?\>                                  {printf("%d\t%s is preprocessor directive\n",count++,yytext);}
int|void|float|char|double|long|string|char\*                   {printf("%d\t%s is reserved keyword\n",count++,yytext);}
[0-1]+                                                          {printf("%d\t%s is digit\n",count++,yytext);}
[a-zA-Z_][a-zA-Z0-9_]*\(\)                                      {printf("%d\t%s is function\n",count++,yytext);}
\{                                                              {printf("%d\t%s block begins\n",count++,yytext);}
\}                                                              {printf("%d\t%s block ends\n",count++,yytext);}
[a-zA-Z_][a-zA-Z0-9_]*\(                                        {printf("%d\t%s function begins \n",count++,yytext);}
\".+\"                                                          {printf("%d\t%s is string\n",count++,yytext);}
");"                                                            {printf("%d\t%s is function ends\n",count++,yytext);}
\)|"\;"                                                         {printf("%d\t%s is symbol\n",count++,yytext);}
"//"(.)*\n /*ingnore multiline comment*/
"/\*"([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+"/"   /*ignore multiline comment*/
\&[a-zA-Z_]+[a-zA-Z0-9_]*                                       {printf("%d\t%s is address of variable \n",count++,yytext);}
[a-zA-Z_]+[a-zA-Z0-9_]*                                         {printf("%d\t%s is variable \n",count++,yytext);}
("return"[\ |\t][0-9]*\;)                                       {printf("%d\t%s is returning statement\n",count++,yytext);}
.|\n                                                            {}
%%

int main(void)
{
    yyin =stdin;
    yylex();
    return 0;
}

int yywrap()
{
    return 1; // Indicate no more input
}