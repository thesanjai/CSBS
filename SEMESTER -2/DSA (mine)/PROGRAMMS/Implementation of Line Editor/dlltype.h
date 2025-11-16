#ifndef DLLTYPE_H
#define DLLTYPE_H
typedef struct 
{
   struct linehead *start;
   int LC;
   int TWC;
   struct linehead *end;
}HEAD;

typedef struct linehead
{
	struct linehead *P;
	int WC;
	struct dllnode *first;
	struct linehead *N;
}LINEHEAD;

typedef struct dllnode
{
  struct dllnode *prev;
  char word[20];
  struct dllnode *next;
}NODE;

HEAD* createHead();
void Append(HEAD *head, char line[]);
void Insert_At_Loc(HEAD *head, int loc, char *line);
void Delete_At_Loc(HEAD *head, int loc);
void Find(HEAD *head, char word[]);
void Display(HEAD *head);
#endif
