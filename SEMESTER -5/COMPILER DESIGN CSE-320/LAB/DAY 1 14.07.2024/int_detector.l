%{
#include <stdio.h>
%}


%%
int     { printf("Found 'int' keyword\n"); }
hello   { printf("Heloo world\n");};
s       { printf("Sanjai Siavkumar \n");}
%%

int main() {
    yylex();
    return 0;
}
