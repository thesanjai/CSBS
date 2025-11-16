#include<iostream>
#include<algorithm>
#include<limits.h>
#include<vector>
#include<bits/stdc++.h>

#define maxsize 10

using namespace std;


namespace TravellingSalespersonProblem{
    
    int TSP(int cost[][maxsize],int n,int s){
      
      vector<int> vertex;
    
      for(int i=0;i<n;i++){
        if(i!=s){
          vertex.push_back(i);
        }
      }
      
      int minPath =INT_MAX;
  
     
     
	   while(next_permutation(vertex.begin(),vertex.end())){

	    int currentPathWeight =0;
	    int k=s;
	    
	    //n-1 must
	    for(int i=0;i<n-1;i++){
	      currentPathWeight +=cost[k][vertex[i]];
	    
	      k=vertex[i];

	    }
	    
	    currentPathWeight += cost[k][s];
	    minPath= min(minPath,currentPathWeight);
	    
	  }
	  
	 
	  return minPath;
	
	}
}


int main(){


 int cost[][maxsize]={ {INT_MAX,5,13,8},
                 {6,INT_MAX,INT_MAX,19},
                 {12,INT_MAX,INT_MAX,7},
                 {11,3,4,INT_MAX}
                 };

 int n=sizeof(cost)/sizeof(cost[0]);
 

 
 cout<<"THE MINIMUM COST OF TRAVELLING  "<<TravellingSalespersonProblem::TSP(cost,n,0);

  
}
