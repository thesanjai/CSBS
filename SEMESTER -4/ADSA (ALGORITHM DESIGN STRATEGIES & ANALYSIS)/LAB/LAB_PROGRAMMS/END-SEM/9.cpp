#include<bits/stdc++.h>

using namespace std;

const int INF=numeric_limits<int>::max();

void floyd_warshall( vector<vector<int>> &graph,int n,int s){
        vector<vector<int>> distance(n,vector<int>(n,INF));
        vector<vector<int>> parent(n,vector<int>(n,-1));

        for(int i=0;i<n;i++){
            distance[i][i]=0;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(graph[i][j]!=INF){
                    distance[i][j]=graph[i][j];
                    parent[i][j]=i+1;
                }
            }
        }


        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(distance[i][k] != INF and distance[k][j] !=INF and distance[i][k] +distance[k][j] <distance[i][j] ){
                        distance[i][j]=distance[i][k] +distance[k][j];
                        parent[i][j]=parent[k][j];
                    }
                 }
            }
        }
    cout<<"DISTANCE MATRIX:\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(distance[i][j] !=INF){
                    cout<<"\t"<<distance[i][j];
                }else{
                    cout<<"INF";
                }
            }
            cout<<endl;
        }
        cout<<"\n\nPARENT MATRIX\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<"\t"<<parent[i][j];
            }
            cout<<endl;
        }
}
int main(){
    
    vector<vector<int>> graph={
        {0,3,8,INF,-4},
        {INF,0,INF,1,7},
        {INF,4,0,INF,INF},
        {2,INF,-5,0,INF},
        {INF,INF,INF,6,0}
    };
    int n=5;

    floyd_warshall(graph,n,0);

    return 0;
}