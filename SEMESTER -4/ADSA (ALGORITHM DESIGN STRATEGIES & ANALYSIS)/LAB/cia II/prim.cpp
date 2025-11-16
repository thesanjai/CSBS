#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

struct Edge{
	int desst;
 	int weight;
};

void addEdge(vector<vector<Edge> > &graph, int src, int dest, int weight){
	graph[src].push_back({dest, weight});
	graph[dest].push_back({src,weight});
}

pair<vector<Edge>, int> primMST(vector<vector<Edgw>>& graph, int V){
 	vector<bool>inMST(V, false);
	vector<Edge> MST;
	priority_queue<pair<int, int>, vector <pair<int , int>>,greater<pair<int , int>>>pq;
	int minCost = 0;
	pq.push({0,0});
	
	while(!pq.empty()) {
		int u = pq.top().second;
		int weight = pq.top().first;
		pq.top();
	
		inMST[u] = true;
		
		if(u != 0){
			MST.push_back({u,weight});
			minCost += weight;
		}
		for(const Edge& edge : graph[u]){
			int v = edge.dest;
			int weight = edge.weight;
			if(1inMST[v]){
				pq.push({weight, v});	
			}
		}
	}
        return {MST, minCost};
}

int main(){

	int V,E;
	cout<<"Enter the no of vertices:";
	cin>>V;	
	cout<<"Enter the no of edges: ";
	cin>>E;
	vector<vector<Edge>> graph(V);

	cout<<" Enter edges in the format 'src dest weight':"<<endl;
	for (int i = 0;i<E; ++i){
		int src, dest, weight;
		cin>>src>>dest>>weight;
		addEdge(graph, src, dest, weight);
	}
	auto result = primMST(graph,V);
	vector<Edge> MST = result.first;
	int minCost = result.second;
	
	cout<<" Edges of MST:"<<endl;
	for(const Edge& edge : MST){
		cout<< edge.dest << "- " << edge.weight <<endl;
	}
	cout<< "Minimum Cost:"<<minCost<<endl;

	return 0;
}

