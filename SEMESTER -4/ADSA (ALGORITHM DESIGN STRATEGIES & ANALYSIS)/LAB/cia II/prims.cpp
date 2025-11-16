#include<iostream>
2: #include<iomanip>
3: #include<vector>
4:
5: #define MAX 20
6:
7: //In this program, vector class is used as
linked list for storing adjacent vertices
8: //Two built-in functions of vector class - used
in program
9: //push_back() - to insert at end
10: //size() - to optain the size of list
11:
12: using namespace std;
13: //W - Not Visited, B - Completely visited,
including the adjacent nodes
14: enum MyColor {W,B};
15:
16: struct Vertex
17: {
18: vector<int> AdjList; //To store the indices
of vertex
19: int Value; //For easy understanding, the
index will be stored as vertex value
20: MyColor Color; //Flag used to represent a
vertex is visited or not
21: int Parent; //Index of the parent vertex in
the resultant BFS tree
22: int Key; //Minimum cost from the curent
vertex to the starting vertex
23: };
24:
25: class Graph

26: {
27: Vertex *V;
28: int size;
29:
30: public:
31:
32: //Initialize the size and the vertex'
Indexs
33: Graph(int);
34:
35: //Adding an edge between two vertices.
index of 'from' and 'to' given as input
36: //3rd arg - directed edge (true) or
undirected edge (false)
37: void AddEdge(int,int);
38:
39: //weight matrix and starting vertex
index is input
40: void Prims(int [][MAX],int);
41:
42: bool ExtractMin(int &);
43:
44: void ShowSpanningTree();
45: };
46:
47: Graph::Graph(int n)
48: {
49: size = n;
50: V = new Vertex[n];
51: for(int i=0;i<n;i++)
52: {
53: V[i].Value = i;
54: V[i].Color = W;

55: V[i].Parent = -1;
56: V[i].Key = 9999;
57: }
58:
59: }
60:
61: //A simple brute force method to extract
minimum.
62: bool Graph::ExtractMin(int &u)
63: {
64:
65: int min;
66: min = 9999;
67: for(int i=0;i<size;i++)
68: {
69: if(V[i].Color==W && V[i].Key<min)
70: {
71: min = V[i].Key;
72: u = i;
73: }
74: }
75: if(min==9999)
76: return false;
77: else
78: return true;
79: }
80: void Graph::ShowSpanningTree()
81: {
82: int mincost=0;
83: cout<<"\n\n\tMinimum Spanning Tree Edges:";
84: for(int i=0;i<size;i++)
85: {
86: if(V[i].Parent==-1)

87: continue;
88: cout<<"\n\t";
89: cout<<V[i].Parent<<"--"<<V[i].Value<<"
: Cost-"<<V[i].Key;
90: mincost += V[i].Key;
91: }
92: cout<<"\n\n\tMinimum Cost: "<<mincost;
93: }
94:
95: void Graph::Prims(int w[][MAX],int r)
96: {
97:
98: V[r].Key = 0;
99: V[r].Parent = -1;
100:
101: int u;
102: int c;
103: while(ExtractMin(c))
104: {
105: for(int p=0;p<V[c].AdjList.size();p++)
106: {
107: u = V[c].AdjList[p];
108: if(V[u].Color==W &&
w[c][u]<V[u].Key)
109: {
110: V[u].Parent = c;
111: V[u].Key = w[c][u];
112: }
113: }
114: V[c].Color = B;
115: }
116: }
117:

118: //from and to are the indices of nodes
119: void Graph::AddEdge(int from, int to)
120: {
121:
122: V[from].AdjList.push_back(to);
123:
124: }
125:
126:
127:
128: int main()
129: {
130:
131: int n;
132:
133: //Test Input-1
134: n=9;
135: //Cost Matrix for the input graph
136: int b[][MAX]={ {0,4,0,0,0,0,0,8,0},
137: {4,0,8,0,0,0,0,11,0},
138: {0,8,0,7,0,4,0,0,2},
139: {0,0,7,0,9,14,0,0,0},
140: {0,0,0,9,0,10,0,0,0},
141: {0,0,4,14,10,0,2,0,0},
142: {0,0,0,0,0,2,0,1,6},
143: {8,11,0,0,0,0,1,0,7},
144: {0,0,2,0,0,0,6,7,0}};
145:
146: /*
147: //Test Input-2
148: n=5;
149: //Cost Matrix for the input graph
150: int b[][MAX]={{0,4,1,2,0},

151: {4,0,0,8,6},
152: {1,0,0,7,0},
153: {2,8,7,0,5},
154: {0,6,0,5,0}};
155: */
156: Graph g(n);
157:
158: for(int i=0;i<n;i++)
159: {
160: for(int j=0;j<n;j++)
161: {
162: if(b[i][j]!=0)
163: {
164: g.AddEdge(i,j);
165: }
166: }
167: }
168:
169: g.Prims(b,0);
170:
171: cout<<"\n\tPrim's Result:";
172: g.ShowSpanningTree();
173: }
