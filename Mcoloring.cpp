#include<bits/stdc++.h>
using namespace std;
bool issafecolor(map<int,vector<int > > &graph , int src, vector<int>&color ,int clr)
{
	for ( int i = 0 ; i < graph[src].size() ; i++)
    {
        if ( color[graph[src][i]] == clr )
        {
            return false;
        }
    }
    return true;
}
bool solve(map<int,vector<int> >&graph,int m,int src,int nodes,vector<int>&color)
{
    if ( nodes+1 == src )
    {
        return true;
    }
    bool res = false;
    for ( int i = 1 ; i <= m ; i++)
    {
        if ( issafecolor(graph,src,color,i) )
        {
            color[src] = i;
          //  cout<<src<<"  "<<color[src]<<endl;
            res |= solve(graph,m,src+1,nodes,color);
            if ( res == true ) return res;
            color[src] = 0;
        }
    }
    return res;
}
int main()
 {
	//code
	int t;
	cin>>t;
	while (t--)
	{
	   int n;
	   cin>>n;
	   int m;
	   cin>>m;
	   int e;
	   cin>>e;
	   map<int,vector<int> >graph;
	   for ( int i = 0 ; i < e ; i++)
	   {
	       int a , b;
	       cin>>a;
	       cin>>b;
	       if ( a == b) continue;
	       graph[a].push_back(b);
	       graph[b].push_back(a);
	   }
	   vector<int>color(n+1,0);
	   bool res = false; 
	   res = solve(graph,m,1,n,color);
	   cout<<res<<endl; 
	}
	return 0;
}
