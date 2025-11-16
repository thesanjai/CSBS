#include<stdio.h>


struct student{
	int rno;
	char name[20];
	float cgpa;
};

main()   {
    FILE   *in,  *out ;
    struct student s1,s2;
    
 	out =   fopen ("file2.txt", "w") ;  
	printf("\n Enter your name : ");
	scanf("%[^\n]s",s1.name);
	printf("\n Enter your rno and cgpa : ");
	scanf("%d%f",&s1.rno, &s1.cgpa);
	fprintf(out,"%d %s %f",s1.rno,s1.name,s1.cgpa);
	fclose(out);
	
 	in  =  fopen ("file2.txt", "r") ;
 	fscanf(in,"%d %[^\n]s %f",&s2.rno, s2.name, &s2.cgpa);
	printf("\n Rno : %d",s2.rno);
	printf("\n Name : %s",s2.name);
	printf("\n CGPA : %f",s2.cgpa);
	
	fclose (in) ;
}

