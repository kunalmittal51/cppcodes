#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<pair<int,int> > adj[] , int src , int dest , int weight )
{
	adj[src].push_back(make_pair(dest,weight));
	adj[dest].push_back(make_pair(src,weight));
}
void print (int V , vector<pair<int,int> > adj[])
{
	for ( int i = 0 ; i < V ; i++)
	{
		for ( auto it = adj[i].begin() ; it != adj[i].end() ; it++)
		{
			int t = it->first;
			int t1 = it->second;
			cout<<t<<"  "<<t1<<endl;
		}
		cout<<endl;
	}
}
int main()
{
	int V;
	cin>>V;
	vector<pair<int,int>>adj[V];
	addEdge(adj, 0, 1, 10);
    addEdge(adj, 0, 4, 20);
    addEdge(adj, 1, 2, 30);
    addEdge(adj, 1, 3, 40);
    addEdge(adj, 1, 4, 50);
    addEdge(adj, 2, 3, 60);
    addEdge(adj, 3, 4, 70);
	print(V,adj);
	return 0;
}
