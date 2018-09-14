#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int>adj[],int src , int dest)
{
	adj[src].push_back(dest);
	adj[dest].push_back(src);
}
void DFS (vector<int>adj[],int src, vector<bool>&visited)
{
	cout<<src<<endl;
	for ( int i = 0 ; i < adj[src].size() ; i++)
	{
		if ( visited[adj[src][i]] == false)
		{
			visited[adj[src][i]] = true;
			DFS(adj,adj[src][i],visited);
		}
	}
}
int main()
{
	int V;
	cin>>V;
	vector<int>adj[V];
	addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    vector<bool>visited(V,false);
    for ( int i = 0 ; i < V ; i++)
    {
    	if ( visited[i] == false)
    	{
			visited[i] = true;
			DFS(adj,i,visited);
		}
	}
}
