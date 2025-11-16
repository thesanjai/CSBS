#include<iostream>

#define MAX 20

using namespace std;

enum MyColor {W,B};

struct Edge
{
    int u,v;
    int Cost;
    MyColor Color;
};

struct Vertex
{
    int value;
    int Set;
};

class Graph
{
    Edge *E;
    Vertex *V;
    int nV,nE;

public:
    Graph(int,int,int [][MAX]);
    void Kruskals();
    void SortEdges();
    void ShowSpanningTree();
};

void Graph::SortEdges()
{
    Edge t;
    for(int i=0;i<nE;i++)
    {
        for(int j=i+1;j<nE;j++)
        {
            if(E[j].Cost<E[i].Cost)
            {
                t = E[j];
                E[j] = E[i];
                E[i] = t;
            }
        }
    }
}

Graph::Graph(int e, int v, int w[][MAX])
{
    nE = e;
    nV = v;
    E = new Edge[nE];
    V = new Vertex[nV];

    int k=0;
    for(int i=0;i<nV;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(w[i][j]!=0)
            {
                E[k].u = i;
                E[k].v = j;
                E[k].Cost = w[i][j];
                E[k].Color = W;
                k++;
            }
        }
        V[i].value = i;
        V[i].Set = i;
    }
}

void Graph::ShowSpanningTree()
{
    int mincost=0;
    cout<<"\n\n\tMinimum Spanning Tree Edges:";
    for(int i=0;i<nE;i++)
    {
        if(E[i].Color==B)
        {
            cout<<"\n\t";
            cout<<E[i].u<<"--"<<E[i].v<<" : Cost-"<<E[i].Cost;
            mincost += E[i].Cost;
        }
    }
    cout<<"\n\n\tMinimum Cost: "<<mincost;
}

void Graph::Kruskals()
{
    SortEdges();
    int a,b;
    for(int i=0;i<nE;i++)
    {
        if(V[E[i].u].Set!=V[E[i].v].Set)
        {
            E[i].Color = B;

            a = V[E[i].u].Set;
            b = V[E[i].v].Set;

            for(int j=0;j<nV;j++)
            {
                if(V[j].Set == a)
                    V[j].Set = b;
            }
        }
    }
}

int main()
{
    int nV = 9;
    int nE = 14;

    int b[][MAX]={ {0,4,0,0,0,0,0,8,0},
                   {4,0,8,0,0,0,0,11,0},
                   {0,8,0,7,0,4,0,0,2},
                   {0,0,7,0,9,14,0,0,0},
                   {0,0,0,9,0,10,0,0,0},
                   {0,0,4,14,10,0,2,0,0},
                   {0,0,0,0,0,2,0,1,6},
                   {8,11,0,0,0,0,1,0,7},
                   {0,0,2,0,0,0,6,7,0}};

    Graph g(nE,nV,b);

    g.Kruskals();

    cout<<"\n\tKruskal's Result:";
    g.ShowSpanningTree();
}
