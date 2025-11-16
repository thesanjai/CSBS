#include<bits/stdc++.h>
#define MAXN 15	 //Max input size
#define MAXM 255 //Max no. of nodes 

#define INF 9999
using namespace std;
struct Node
{
	float c, u;
	int Solution[MAXN+1];//values 0 or 1
	int n; //Size of Solution
	int Level;
	float filledCapacity;
	bool Alive;
};

void CopySolution(int s[], int d[],int current)
{
	for(int i=1;i<=current;i++)
		d[i] = s[i];
}
void UpdateCost(Node &s,float w[],float p[],float C,int n)
{
	float p1,p2,w1,w2;
	p1 = 0;
	w1 = C;
	for(int i=1;i<=n;i++)
	{
		if(i<=s.Level && s.Solution[i]==0)
			continue;
		if(w1>=w[i])
		{
			p1 = p1 + p[i];
			w1 = w1 - w[i];
		
		}
		else if(w1!=0)
		{
			p1 = p1 + p[i] * (w1/w[i]);
			w1 = 0;
		}
	}
	s.c = p1;
	p1 = 0;
	w1 = C;
	for(int i=1;i<=n;i++)
	{
		if(i<=s.Level && s.Solution[i]==0)
			continue;
		if(w1>=w[i])
		{
			p1 = p1 + p[i];
			w1 = w1 - w[i];
			s.Solution[i] = 1;
		}
	}

	s.u = p1;
	
}
bool ExtractMin(Node S[], int n, int &minIndex)
{
	/*cout<<"\n";
	for(int i=1;i<=n;i++)
		cout<<" "<<S[i].Alive;*/
	float min = INF;
	minIndex = -1;
	for(int i=1;i<=n;i++)
	{
		if(S[i].Alive && S[i].c<min)
		{
			min = S[i].c;
			minIndex = i;
		}
	}
	return (minIndex==-1)?false:true;
}
void PrintSolution(int s[],int n)
{
	for(int i=1;i<=n;i++)
		cout<<s[i]<<", ";
}
void PrintNode(Node s, int i)
{
	cout<<"\n\nNode:"<<i<<"| Level:"<<s.Level<<"| C:"<<s.c<<"| U:"<<s.u<<"| Filled:"<<s.filledCapacity<<"| Solution: ";
	PrintSolution(s.Solution,s.n);

}
void PrintOptimal(float UB, int s[], int n)
{
	cout<<"\n\t\tOptimal Cost (UB):"<<UB<<"| Optimal Solution: ";
	PrintSolution(s,n);
}
float LCBB_ZOKnapsack(float w[],float p[],float C,int n,int OptimalSolution[])
{
	float UB = INF;
	
	float w1, p1, w2, p2;
	int nindex,left,right;
	Node S[MAXM+1];
	
	for(int i=1;i<=MAXM;i++)
	{
		S[i].filledCapacity = 0;
		for(int j=1;j<=n;j++)
			S[i].Solution[j] = 0;
		S[i].n = n;
	}
	
	//Let start with node 1
	nindex = 1;
	//Calculate Initial Cost & local upper bound - c & u
	S[nindex].Alive = true;
	S[nindex].Level = 0;
	S[nindex].filledCapacity = 0;	
	UpdateCost(S[nindex],w,p,C,n);
	if(S[nindex].u<UB)
	{
		UB = S[nindex].u;
		CopySolution(S[nindex].Solution,OptimalSolution,n);
	}
	
	PrintNode(S[nindex],nindex);
	PrintOptimal(UB, OptimalSolution, n);
	
	int mindex=1,nextItem;
	
	while(ExtractMin(S,nindex,mindex))
	{
		S[mindex].Alive = false;

		nextItem = S[mindex].Level+1;
		
		if(nextItem>n)
			continue;
		
		//Check for left1: can be explored or not
		if((S[mindex].filledCapacity+w[nextItem])<=C)
		{
			left = ++nindex;
			S[left].Alive = true;
			S[left].Level = S[mindex].Level+1;
			CopySolution(S[mindex].Solution,S[left].Solution,nextItem-1);
			S[left].Solution[nextItem] = 1;
			S[left].filledCapacity = S[mindex].filledCapacity + w[nextItem];
			S[left].c = S[mindex].c;
			S[left].u = S[mindex].u;			
			if(S[left].u<UB)
			{
				UB = S[left].u;
				CopySolution(S[left].Solution,OptimalSolution,n);
			}
			PrintNode(S[left],left);
			PrintOptimal(UB, OptimalSolution, n);
		}
		right = ++nindex;
		S[right].Alive = true;	
		S[right].Level = S[mindex].Level+1;		
		CopySolution(S[mindex].Solution,S[right].Solution,nextItem-1);
		S[right].filledCapacity = S[mindex].filledCapacity;		
		S[right].Solution[nextItem] = 0;
		UpdateCost(S[right],w,p,C,n);
		if(S[right].u<UB)
		{
			UB = S[right].u;
			CopySolution(S[right].Solution,OptimalSolution,n);
		}
		PrintNode(S[right],right);
		PrintOptimal(UB, OptimalSolution, n);
		
		//Killing nonpromising nodes
		for(int i=1;i<=nindex;i++)
			if(S[i].c>UB)
				S[i].Alive = false;
		
		
	}
	cout<<"\n\n";
	//PrintSolution(OptimalSolution,n);
	return UB;
}

int main()
{

//Test Case 1
	float p[MAXN+1] = {0, 10, 10, 12, 18, 5};
	float w[MAXN+1] = {0, 2, 4, 6, 9, 3};
	float C = 15; 
	int n = 5;
//Test Case 2	
/*	float p[MAXN+1] = {0, 40, 30, 50, 10};
	float w[MAXN+1] = {0, 2, 5, 10, 5};
	float C = 16; 
	int n = 4;*/
//Test Case 3
/*	float p[MAXN+1] = {0, 10, 18, 32, 14};
	float w[MAXN+1] = {0, 1, 2, 4, 2};
	float C = 6; 
	int n = 4;*/
//Test Case 4
/*	float p[MAXN+1] = {0, 3, 2, 10, 6, 4};
	float w[MAXN+1] = {0, 2, 3, 3, 4, 6};
	float C = 10; 
	int n = 5; */
//Test Case 5
/*	float p[MAXN+1] = {0, 4, 3, 7, 9};
	float w[MAXN+1] = {0, 2, 2, 4, 5};
	float C = 9; 
	int n = 4;*/
		
	float ipw,jpw,t;
	
	//sorting
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++)
	{
		ipw = p[i]/w[i];
		jpw = p[j]/w[j];
		if(jpw>ipw)
		{
			t = p[i]; p[i]=p[j]; p[j]=t;
			t = w[i]; w[i]=w[j]; w[j]=t;
		}
	}
	cout<<"\nList of Items: ";
	for(int i=1;i<=n;i++)
		cout<<"\t("<<p[i]<<", "<<w[i]<<")";
	//Maximization to Minimization
	for(int i=1;i<=n;i++)
		p[i] = -p[i];
	int OptimalSolution[MAXN+1];
	float bestProfit = LCBB_ZOKnapsack(w,p,C,n,OptimalSolution);
	
	//Minimization to Maximization
	for(int i=1;i<=n;i++)
		p[i] = -p[i];
	bestProfit = -bestProfit;
	cout<<"\n\n\tList of Items: ";
	for(int i=1;i<=n;i++)
		cout<<" ("<<p[i]<<", "<<w[i]<<")";
	cout<<"\n\tBag Capacity: "<<C<<" Kg";
	cout<<"\n\n\tMaximum Profit: "<<bestProfit;
		cout<<"\n\tSelected Items(Profit, Weight): ";
	for(int i=1;i<=n;i++)
		if(OptimalSolution[i]==1)
			cout<<" ("<<p[i]<<", "<<w[i]<<")";
	cout<<"\n\n";
}
