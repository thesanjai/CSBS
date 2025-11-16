#include<bits/stdc++.h>
using namespace std;

void TSP(vector<vector<int>> &graph,int start){

    vector<int> vertex;
    for(int i=0;i<graph.size();i++){
        if(i!=start){
            vertex.push_back(i);
        }
    }
    int min_cost=INT_MAX;

    while(next_permutation(vertex.begin(),vertex.end())){
        int k=start;
        int cur_cost=0;

        for(int i=0;i<graph.size()-1;i++){
            cur_cost +=graph[k][vertex[i]];
            k=vertex[i];
        }
        cur_cost +=graph[k][start];
        min_cost= min(min_cost,cur_cost);
    }

    cout<<"cost: "<<min_cost<<endl;
}

int main(int argc,char** argv){

    ifstream ip("tsp_ip.txt");
    int n;
    ip>>n;

    vector<vector<int>> graph(n,vector<int>(n,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ip>>graph[i][j];
            cout<<graph[i][j]<<"\t";
        }
        cout<<endl;
    }
    ip.close();

    TSP(graph,0);
    return 0;
}

/*
5
999 20 30 10 11
15 999 16 4 2
3 5 999 2 4
19 6 18 999 3
16 4 7 16 999
*/