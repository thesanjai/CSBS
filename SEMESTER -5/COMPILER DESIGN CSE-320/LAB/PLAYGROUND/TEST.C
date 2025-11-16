#include <iostream>

using namespace std;

int main(){
   char str[100];
   printf("Enter the string: ");
   scanf("%[abcd]*",str);

   printf("Entered string: %s\n",str);
}