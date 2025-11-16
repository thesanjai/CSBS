#include<iostream>
#define MAXW 20
#define MAXN 20

using namespace std;
void ZeroOneKnapsackDP(int wt[], int p[], int W, int n, int m[][MAXW])
{
	int w,i,x,y;
	for(w=0;w<=W;w++)
		m[0][w]=0;
	for(i=0;i<=n;i++)
		m[i][0]=0;
	for(i=1;i<=n;i++)
	{
		for(w=1;w<=wt[i]-1;w++)
			m[i][w]=m[i-1][w];
		for(w=wt[i];w<=W;w++)
		{
			x=m[i-1][w];
			y=p[i]+m[i-1][w-wt[i]];
			if(x>y)
				m[i][w]=x;
			else
				m[i][w]=y;
		}
	}
}

int main()
{
	int i,j;
	int wt[MAXN]={0,3,4,5,6};
	int p[MAXN]={0,2,3,4,1};
	int W=8;
	int n=4;
	int m[MAXN][MAXW];
	ZeroOneKnapsackDP(wt,p,W,n,m);
	cout<<"\n\nProfit Matrix-m\n";
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=W;j++)
		{
			cout<<"\t"<<m[i][j];
		}
		cout<<"\n";
	}
	cout<<"\n\nMaximum Profit:"<<m[n][W];
}

