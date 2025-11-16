#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
struct edge
{
int u,v,w;
edge(int a, int b,int c):u(a),v(b),w(c){}
};
void krushkals(vector<edge>& edges,int v)
{
sort(edges.begin(),edges.end(),[](const edge& a,const edge &b){ return a.w<b.w;});
vector<edge> mst;
vector<int> parent(v);
iota(parent.begin(),parent.end(),0);
for(int i = 0;i<edges.size();i++)
{
int pu = edges[i].u;
int pv = edges[i].v;
while(parent[pu] != pu) pu = parent[pu];
while(parent[pv] != pv) pv = parent[pv];
if(pu!=pv)
{
parent[pv] = pu;
mst.push_back(edges[i]);
}
}
for(int i = 0;i<mst.size();i++)
{
cout<<"\t"<<mst[i].u<<"\t"<<mst[i].v<<"\t"<<mst[i].w<<endl;
}
}
int main()
{
int v,e;
cout<<"No of vertices and Edges";
cin>>v>>e;
vector<edge> edges;
for(int i = 0;i<e;i++)
{
int from,to,weight;
cout<<"From/to/weight : ";
cin>>from>>to>>weight;
edges.push_back(edge(from,to,weight));
}
krushkals(edges,v);
}