#include<bits/stdc++.h>
using namespace std;

class GRAPH{
    int V;
    vector<vector<int>> graph;

    public:
    GRAPH(int v):V(v),graph(V,vector<int>(V,0)){}

    void add_edge(int u,int v, int value){
        graph[u][v]=value;
        graph[v][u]=value;
    }

    int minK(vector<bool> visited ,vector<int> key){
           int min=INT_MAX;
            int min_index=-1;
        for(int i=0;i<V;i++){

         
            if(!visited[i] and key[i]<min){
                min=key[i];
                min_index=i;
            }
        }

        return min_index;
    }

   void MST(int start){
        
        vector<bool> visited(V,false);
        vector<int> key(V,INT_MAX);
        vector<int> parent(V,-1);

        key[start] = 0;
        parent[start]=-1;

        for(int i=0;i<V-1;i++){
            int u=minK(visited,key);

            visited[u]=true;

            for(int v=0;v<V;v++){
                if(!visited[v] and graph[u][v] and graph[u][v] <key[v]){
                    key[v]=graph[u][v];
                    parent[v]=u;
                }
            }
        }
        int sum=0;
      cout<<"edge \t cost\n";
      for(int i=1;i<V;i++){
        cout<<parent[i]<<"--"<<i<<"\t"<<graph[i][parent[i]]<<endl;
        sum +=graph[i][parent[i]];
      }
        cout<<"MAXIMUM PROFIT ->"<<sum;
   }

};

int main(int argc,char** argv){
    int V,E;

    ifstream ip("input_prims.txt");

    ip>>V>>E;

    GRAPH g(V);

    for(int i=0;i<E;i++){
        int u,v,value;
        ip>>u>>v>>value;
        g.add_edge(u,v,value);
    }

    ip.close();

    int start_index=0;
    g.MST(start_index);
    return 0;
}