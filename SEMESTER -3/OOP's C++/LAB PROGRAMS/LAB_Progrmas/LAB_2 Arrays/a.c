#include<stdio.h>
const int CITY=2;
const int WEEK=7;

int main()
{
   int temperature[CITY][WEEK];
   int i ,j;

   /*Take input from user*/
   for(i=0;i<CITY;i++)
   {
       for(j=0;j<WEEK;j++)
       {
           printf("City[%d], Day[%d]: ", i+1, j+1);
           scanf("%d", &temperature[i][j] );
       }
       printf("\n");
   }

   /*Display output*/
   printf("Displaying Values:\n\n");

   for(i=0;i<CITY;i++)
   {
       for(j=0;j<WEEK;j++)
       {
           printf("City[%d], Day[%d]=%d\n", i+1, j+1, temperature[i][j]);
       }
       printf("\n");
   }

   return 0;
}
