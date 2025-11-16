%{
#include <stdio.h>
%}


%x IN_COMMENT

%%
\#include\ ?\<[a-zA-Z]+(.h)?\>                                {printf("%s is preprocessor directive\n",yytext);}
int|void                                                      {printf("%s is reserved keyword\n",yytext);}
[a-zA-Z_][a-zA-Z0-9_]*\(\)                                    {printf("%s is function\n",yytext);}
\{                                                            {printf("%s block begins\n",yytext);}
\}                                                            {printf("%s block ends\n",yytext);}
[a-zA-Z_][a-zA-Z0-9_]*\(                                      {printf("%s function begins \n",yytext);}
\".+\"                                                        {printf("%s is string\n",yytext);}
");"                                                          {printf("%s is function ends\n",yytext);}
\)|"\;"                                                       {printf("%s is symbol\n",yytext);}
"//"(.)*\n /*ingnore multiline comment*/

"/*" {BEGIN(IN_COMMENT);}
<IN_COMMENT>{
 "*/" {BEGIN(INITIAL);}
 .|\n ;
}                                                            {printf("%s is multi line comment\n",yytext);}
\&[a-zA-Z_]+[a-zA-Z0-9_]*                                    {printf("%s is address of variable \n",yytext);}
[a-zA-Z_]+[a-zA-Z0-9_]*                                      {printf("%s is variable \n",yytext);}
("return"[\ |\t][0-9]*\;)                                    {printf("%s is returning statement/\n",yytext);}
.|\n                                     {}
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