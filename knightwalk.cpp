#include<bits/stdc++.h>
using namespace std;
bool issafe(int x ,int y , int n , int m)
{
    if ( x > 0 && y > 0 && x <= n && y <= m) return true;
    else return false;
}
void solve(vector<vector<bool> >&visited,int n , int m , int sx, int sy , int dx , int dy, int len , vector<vector<int> >pos , int *ans)
{
    if ( sx == dx && sy == dy)
    {
        *ans = min(*ans,len);
        return;
    }
    for ( int i = 0 ; i < pos.size() ; i++)
    {
        if ( issafe(sx+pos[i][0],sy+pos[i][1],n,m) == true && visited[sx+pos[i][0]][sy+pos[i][1]] == false )
        {
            len++;
            visited[sx+pos[i][0]][sy+pos[i][1]] = true;
	        solve(visited,n,m,sx+pos[i][1],sy+pos[i][1],dx,dy,len,pos,ans);
	        len--;
	        visited[sx+pos[i][0]][sy+pos[i][1]] = false;
        }
    }
    return;
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
	   vector<vector<bool> >visited(n+1,vector<bool>(m+1,false));
	   int src_x,src_y,dest_x,dest_y;
	   cin>>src_x>>src_y>>dest_x>>dest_y;
	   visited[src_x][src_y] = true;
	   vector<vector<int> >pos(8,vector<int>(2));
	   pos = {{2,1},{2,-1},{1,2},{1,-2},{-2,1},{-2,-1},{1,-2},{-1,-2}};
	   int ans = INT_MAX;
	   solve(visited,n,m,src_x,src_y,dest_x,dest_y,0,pos,&ans);
	   cout<<ans<<endl;
	}
	return 0;
}
