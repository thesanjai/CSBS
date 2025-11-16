#include<bits/stdc++.h>

using namespace std;

const int INF=numeric_limits<int>::max();

struct Edge{
    int s,d,w;
};

void bellman(vector<Edge> &edges,int n,int s) {
    vector<int> distance(n,INF);

    distance[s]=0;

    for(int i=0;i<n-1;i++){
        for(auto &edge:edges){
            if(distance[edge.s]!=INF and distance[edge.s]+edge.w < distance[edge.d]){
                distance[edge.d]=distance[edge.s]+edge.w;
            }
        }
    }
        for(auto &edge:edges){
            if(distance[edge.s]!=INF and distance[edge.s]+edge.w < distance[edge.d]){
                cout<<"negative edge cycle found\n";
                return;
            }
        }
    
    for(int i=0;i<n;i++){
        cout<<"vertex: "<<i<<"\t->"<<distance[i]<<endl;
    }

}
int main(){

    vector<Edge> edges={
        {0,1,10},
        {0,2,5},
        {1,2,2},
        {1,3,1},
        {2,1,3},
        {2,4,2},
        {2,3,9},
        {3,4,4},
        {4,3,6},
        {4,0,7}
    };
    int n=5;
    
    bellman(edges,n,0);
    return 0;
}