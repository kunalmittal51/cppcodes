#include<bits/stdc++.h>
using namespace std;
void dijiktra(map<int,vector<pair<int,int> > >graph , int src , int V)
{
	priority_queue< pair<int,int> , vector< pair<int,int> > , greater<pair<int,int> > > pq;
	pair<int,int>p;
	vector<int>dist(V,INT_MAX);
	dist[src] = 0;
	p.first = 0;
	p.second = src;
	pq.push(p);
	while ( !pq.empty() )
	{
		pair<int,int>p  = pq.top();
		int cur = p.second;
		pq.pop();
		for (int i = 0 ;  i < graph[cur].size() ; i++)
		{
			int v = graph[cur][i].first;
			int weight = graph[cur][i].second;
			if ( dist[v] > dist[cur] + weight)
			{
				dist[v] = dist[cur]+weight;
				pair<int,int>p1;
				p1.first = dist[v];
				p1.second = v;
				pq.push(p1);
			}
		}
	}
	for ( int i = 0 ; i < dist.size() ; i++)
	{
		cout<<dist[i]<<" ";
	}
	cout<<endl;
	return;
}
int main()
{
	int V;
	map<int,vector<pair<int,int> > > graph;
	int E;
	cin>>V>>E;
	for ( int i = 0 ; i < E ; i++)
	{
		int src,dest,w;
		cin>>src>>dest>>w;
		pair<int,int>p;
		p.first = dest;
		p.second = w;
		graph[src].push_back(p);
		p.first = src;
		graph[dest].push_back(p);	
	} 
	dijiktra(graph,0,V);
	return 0;
}
