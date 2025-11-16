#include<bits/stdc++.h>
using namespace std;

const int INF=9999;

class GRAPH{
    int V,E;
    vector<vector<int>> graph;
    public:
    GRAPH(int a,int b):V(a), E(b),graph(V,vector<int>(V,0)){
      
    }

    void add(int u,int v,int val){
        graph[u][v]=val;
        graph[v][u]=val;
    }

    int minKey(vector<int> key, vector<bool> visited){
        int min=INF;
        int minK=-1;

        for(int i=0;i<V;i++){
            if(!visited[i] and key[i]<min){
                min=key[i];
                minK=i;
            }   
        }

        return minK;
    }

    void mst(int start){
        vector<int> parent(V,-1);
        vector<int> key(V,INF);
        vector<bool> visited(V,false);

        key[start]=0;
        parent[start]=-1;

        for(int i=0;i<V-1;i++){
            int u=minKey(key,visited);

            visited[u]=true;

            for(int v=0;v<V;v++){
                if(!visited[v] and graph[u][v] and graph[u][v]< key[v]){
                    key[v]=graph[u][v];
                    parent[v]=u;
                }
            }
        }
        int sum=0;
        for(int i=1;i<V;i++){
            cout<<parent[i]<<" - "<<i<<"\t->"<<graph[i][parent[i]]<<endl;
            sum +=graph[i][parent[i]];
        }

        cout<<"\n MIN COSt: "<<sum<<endl;
    }
};
int main(int argc, char** argv){

    ifstream ip("ip7.txt");
    int V,E;
    ip>>V>>E;

    GRAPH g(V,E);

    for(int i=0;i<E;i++){
        int u,v,val;
        ip>>u>>v>>val;
        g.add(u,v,val);
    }
    ip.close();

    g.mst(0);
    return 0;
}