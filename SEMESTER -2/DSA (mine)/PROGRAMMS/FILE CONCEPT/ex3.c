#include<stdio.h>


struct student{
	int rno;
	char name[20];
	float cgpa;
};

main()   {
    FILE   *in,  *out ;
    int n=3,i;
    struct student s1[10],s2[10];
    
 	out =   fopen ("file3.txt", "w") ;
	for(i=0;i<n;i++){
		printf("\n Enter your name : ");
		scanf("%s",s1[i].name);
		printf("\n Enter your rno and cgpa : ");
		scanf("%d%f",&s1[i].rno, &s1[i].cgpa);
		fprintf(out,"%d %s %f\n",s1[i].rno,s1[i].name,s1[i].cgpa);
		getchar();
	}  
	fclose(out);
	in  =  fopen ("file3.txt", "r") ;
 
	for(i=0;i<n;i++){
	 	fscanf(in,"%d %s %f",&s2[i].rno, s2[i].name, &s2[i].cgpa);

		printf("\n Rno : %d",s2[i].rno);
		printf("\n Name : %s",s2[i].name);
		printf("\n CGPA : %f",s2[i].cgpa);
	}
	
	fclose (in) ;
}

