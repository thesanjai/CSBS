#include<iostream>
#include<iomanip>
#include<vector>

#define MAX 20

enum MyColor {W,B};

struct Vertex
{
    std::vector<int> AdjList;
    int Value;
    MyColor Color;
    int Parent;
    int Key;
};

class Graph
{
    Vertex *V;
    int size;

public:
    Graph(int);
    void AddEdge(int,int);
    void Prims(int [][MAX],int);
    bool ExtractMin(int &);
    void ShowSpanningTree();
};

Graph::Graph(int n)
{
    size = n;
    V = new Vertex[n];
    for(int i=0;i<n;i++)
    {
        V[i].Value = i;
        V[i].Color = W;
        V[i].Parent = -1;
        V[i].Key = 9999;
    }
}

bool Graph::ExtractMin(int &u)
{
    int min;
    min = 9999;
    for(int i=0;i<size;i++)
    {
        if(V[i].Color==W && V[i].Key<min)
        {
            min = V[i].Key;
            u = i;
        }
    }
    if(min==9999)
        return false;
    else
        return true;
}

void Graph::ShowSpanningTree()
{
    int mincost=0;
    std::cout<<"\n\n\tMinimum Spanning Tree Edges:";
    for(int i=0;i<size;i++)
    {
        if(V[i].Parent==-1)
            continue;
        std::cout<<"\n\t";
        std::cout<<V[i].Parent<<"--"<<V[i].Value<<": Cost-"<<V[i].Key;
        mincost += V[i].Key;
    }
    std::cout<<"\n\n\tMinimum Cost: "<<mincost;
}

void Graph::Prims(int w[][MAX],int r)
{
    V[r].Key = 0;
    V[r].Parent = -1;

    int u;
    int c;
    while(ExtractMin(c))
    {
        for(int p=0;p<V[c].AdjList.size();p++)
        {
            u = V[c].AdjList[p];
            if(V[u].Color==W && w[c][u]<V[u].Key)
            {
                V[u].Parent = c;
                V[u].Key = w[c][u];
            }
        }
        V[c].Color = B;
    }
}

void Graph::AddEdge(int from, int to)
{
    V[from].AdjList.push_back(to);
}

int main()
{
    int n;

    // Test Input
    n = 9;
    int b[][MAX] = {
        {0,4,0,0,0,0,0,8,0},
        {4,0,8,0,0,0,0,11,0},
        {0,8,0,7,0,4,0,0,2},
        {0,0,7,0,9,14,0,0,0},
        {0,0,0,9,0,10,0,0,0},
        {0,0,4,14,10,0,2,0,0},
        {0,0,0,0,0,2,0,1,6},
        {8,11,0,0,0,0,1,0,7},
        {0,0,2,0,0,0,6,7,0}
    };

    Graph g(n);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(b[i][j]!=0)
            {
                g.AddEdge(i,j);
            }
        }
    }

    g.Prims(b,0);

    std::cout<<"\n\tPrim's Result:";
    g.ShowSpanningTree();
}
