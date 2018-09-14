#include<bits/stdc++.h>
using namespace std;
bool issafe (int x , int y,vector<vector<int> > &mat)
{
    if ( x >= 0 && y >= 0 && x < mat.size() && y < mat[0].size())
    {
        return true;
    }
    return false;
}
bool solve ( vector<vector<int> > &mat,int src_x , int src_y,vector<vector<int> > &pos,vector<vector<bool> > &visited)
{
    cout<<src_x<<"  "<<src_y<<endl;
	if ( mat[src_x][src_y] == 2)
    {
        return true;
    }
    bool res = false;
    for ( int i = 0 ; i < pos.size() ; i++ )
    {
        src_x += pos[i][0];
        src_y += pos[i][1];
        if ( issafe(src_x,src_y,mat) && mat[src_x][src_y] != 0 && visited[src_x][src_y] == false)
        {
        	visited[src_x][src_y] = true;
            res |= solve(mat,src_x,src_y,pos,visited);
            if ( res == true)
            {
            	break;
			}
        	visited[src_x][src_y] = false;
		}
        src_x -= pos[i][0];
        src_y -= pos[i][1];
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
	    vector<vector<int> >mat;
	    int src_x ; 
	    int src_y ;
        vector<vector<int> > pos;
        vector<int>row;
        row.push_back(1);
        row.push_back(0);
        pos.push_back(row);
        row[0] = -1;
        row[1] = 0 ;
		pos.push_back(row);
        row[0] = 0 ;
        row[1] = 1 ;
        pos.push_back(row);
        row[0] = 0;
        row[1] = -1;
        pos.push_back(row);
        vector<vector<bool> > visited(n,vector<bool>(n,false));
	    for ( int i = 0 ;i  < n ; i++)
	    {
	        vector<int>row;
	        for ( int k = 0 ; k < n ; k++)
	        {
	            int j;
	            cin>>j;
	            row.push_back(j);
	            if ( j == 1)
	            {
	                src_x = i;
	                src_y = k;
	                visited[i][k] = true;
 	            }
	        }
            mat.push_back(row);
	    }
	    cout<<solve(mat,src_x,src_y,pos,visited)<<endl;
	}
	return 0;
}
