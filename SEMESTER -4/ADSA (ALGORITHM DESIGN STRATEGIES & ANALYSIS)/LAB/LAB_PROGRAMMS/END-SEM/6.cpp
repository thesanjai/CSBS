#include<bits/stdc++.h>
using namespace std;

class graph{
    int V;

    public:
    vector<vector<int>> adj;
    graph (int a):V(a),adj(a){}



    void TOPO(int start){

      
        vector<bool> visited(V,false);
        stack<int> s;

        vector<int> st(V,-1);
        vector<int> ft(V,-1);
        int time=1;

      

        visited[start]=true;
        s.push(start);

        st[start] = time++;

        while(!s.empty()){
            int u=s.top();

            bool allVisited=true;

            for(auto v:adj[u]){
                if(!visited[v]){
                    visited[v]=true;
                    s.push(v);
                    st[v]=time++;
                    allVisited=false;
                    break;
                }
            }

            if(allVisited){
                cout<<u<<"  ";
                ft[u]=time++;
                s.pop();
                
            }
        }
        cout<<"vertex\tst\tft\n";
        for(int i=0;i<V;i++){
              cout<<i<<"\t"<<st[i]<<"\t"<<ft[i]<<endl;
        }
    }
};

int main(int argc, char** argv){
    ifstream ip("ip6.txt");

    int V,E;
    ip>>V>>E;

    graph g(V);

    for(int i=0;i<E;i++){
        int u,v;
        ip>>u>>v;

        g.adj[u].push_back(v);
    }
    ip.close();

    g.TOPO(0);

    return 0;
}