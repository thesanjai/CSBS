#include<stdio.h>

main()   {
    FILE   *in,  *out ;
   // char   c ;
	int t,c=0;
    in  =  fopen ("input.txt", "r") ;
 //   out  =  fopen ("output.dat", "w") ;
    
    while(c<10){
    	fscanf(in," %d ",&t);
		printf("%d\n",t);
		c++;
	}
  /*
    while   ((c = getc (in)) != EOF)
         putc (toupper (c), out);
    */
	fclose (in) ;
    fclose (out) ;
}

