#include<bits/stdc++.h>
using namespace std;
int bfs(vector <int> adj[],vector <vector <bool> > vis,int row,int col,int n)
{
    int row_num[]={-1,0,0,1};
    int col_num[]={0,-1,1,0};
    priority_queue <pair <long long int,pair<int,int> > ,vector <pair <long long int,pair<int,int> > >,greater <pair <long long int,pair<int,int> > > > pq;
    pq.push(make_pair(adj[0][0],make_pair(0,0)));
    while(!pq.empty())
    {
        long long int dis=pq.top().first;
        row=pq.top().second.first;
        col=pq.top().second.second;
        vis[row][col]=true;
        pq.pop();
        if(row==n-1 && col==n-1)
            return dis;
        for(int i=0;i<4;i++)
        {
            int r=row+row_num[i];
            int c=col+col_num[i];
            if(r>=0 && r<n && c>=0 && c<n && vis[r][c]==false)
            {
                pq.push(make_pair(dis+adj[r][c],make_pair(r,c)));
            }
        }
    }
    return -1;
}
int main()
 {
    int t;
    cin>>t;
	while(t--)
	{
	    int n,val,i;
	    vector <int> adj[100];
        cin>>n;
        for(i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>val;
                adj[i].push_back(val);
            }
        }
        vector <vector <bool> > vis(n,(vector <bool>(n,false)));
        cout<<(bfs(adj,vis,0,0,n))<<endl;
	}
	return 0;
}
