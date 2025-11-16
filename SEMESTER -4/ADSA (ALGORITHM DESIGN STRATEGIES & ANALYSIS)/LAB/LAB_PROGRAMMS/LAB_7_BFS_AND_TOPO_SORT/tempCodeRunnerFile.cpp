#include<bits/stdc++.h>
using namespace std;


class GRAPH{
    int V;
    vector<vector<int>> adj;

    public:
  
    GRAPH(int v): V(v), adj(v){ }

    

    void add_edge(int u,int v){
        adj[u].push_back(v);
       // adj[v].push_back(u);
    }

    void DFS(int start){
        vector<bool> visited(V,false);
        stack<int> s;

        vector<int> st(V,-1);
        vector<int> ft(V,-1);
        int current_time =1;

        vector<bool>completd(V,false);

        begin:

        visited[start] = true;
        s.push(start);

        st[start]=current_time++;

        while(!s.empty()){
            int u=s.top();

            bool allVisited =true;

            for(auto v:adj[u]){
                if(!visited[v]){
                    visited[v]=true;
                    s.push(v);
                    st[v]=current_time++;
                    allVisited = false;
                    break;
                }
            } 
            if(allVisited){
                cout<<u<<" ";
                completd[u]=true;
                s.pop();
                ft[u]=current_time++;
            }
        }

        for(int i=0;i<V;i++){
            if(completd[i]==false){
                start=i;
                goto begin;
            }
        }
        cout<<endl<<endl;
        for (int i=0;i<V;i++){
            cout<<i<<"\t"<<st[i]<<"\t\t"<<ft[i]<<endl;
        }
    }

    
};
int main(int argc, char** argv){

    int V,E;
    ifstream ip("input.txt");
    ip>>V>>E;

    GRAPH g(V);

    for(int i=0;i<E;i++){
        int u,v;
        ip>>u>>v;
        g.add_edge(u,v);
    }
    ip.close();


    int start_vertex=0;

    g.DFS(start_vertex);

   

    return 0;
}