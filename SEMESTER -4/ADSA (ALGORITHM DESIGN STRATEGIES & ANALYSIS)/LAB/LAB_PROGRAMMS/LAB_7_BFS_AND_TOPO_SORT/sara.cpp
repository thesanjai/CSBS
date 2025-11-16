#include<bits/stdc++.h>
using namespace std;

class GRAPH{
    int V;

    public:

    vector<vector<int>> adj;

    GRAPH(int x): V(x),adj(x){ }

    void DFS(int start){
        vector<bool> visited(V,false);
        stack<int> s;

        vector<int> topo;

        vector<bool> completed(V,false);

        vector<int> st(V,-1);
        vector<int> ft(V,-1);
        int current_time =1;

        begin:

        visited[start]=true;
        s.push(start);
        st[start]=current_time++;

        while(!s.empty()){
            int u =s.top();

            bool all_visited=true;
            for(int v: adj[u]){

                if(!visited[v]){ // visited[v]==false;
                    visited[v]=true;
                    s.push(v);
                    st[v]=current_time++;
                    all_visited=false;

                    break;
                }
            }

            if(all_visited){
                topo.push_back(u);
                ft[u]=current_time++;
                completed[u]=true;
                s.pop();
                
            }

            
        }

        for(int i=0;i<V;i++){
            if(!completed[i]){
                start=i;
                goto begin;
            }
        }
        cout<<"TOPO ORDER :";
        for(auto i:topo){
            cout<<"\t"<<i;
        }
        cout<<endl;

        cout<<"VALUE \t ST \t FT\n";

        for(int i=0;i<V;i++){
            cout<<i<<"\t"<<st[i]<<"\t"<<ft[i]<<endl;
        }

    }
};


int main(){

    int V,E;

    ifstream jai("sara_ip.txt");

    jai>>V>>E; // V=6 ,E=7

    GRAPH g(V);

    for(int i=0;i<E;i++){

        int u,v;
        jai>>u>>v;
        g.adj[u].push_back(v);
    }

    jai.close();

    g.DFS(0);



    return  0;
}