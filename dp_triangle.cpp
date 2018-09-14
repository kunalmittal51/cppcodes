#include<bits/stdc++.h>
using namespace std;
int find ( vector <vector<int> > triangle)
{
	vector< vector<int> > dp;
	if ( triangle.size() == 0)
	{
		return 0;
	}
	for ( int i = 0 ; i < triangle.size() ; i++)
	{
		vector <int> row;
		for ( int j = 0 ; j < triangle[i].size() ; j++)
		{
			if ( i == 0 && j == 0)
			{
				row.push_back(triangle[i][j]);
			}
			else if ( j == 0)
			{
				row.push_back(dp[i-1][j]+triangle[i][j]);
			}
			else if ( j == i)
			{
				row.push_back(dp[i-1][j-1] + triangle[i][j]);
			}
			else 
			{
				row.push_back(min(dp[i-1][j],dp[i-1][j-1])+triangle[i][j]);
			}
		}
		dp.push_back(row);
		row.clear();
	}
	int min = INT_MAX;
	for ( int i = 0 ; i < dp[dp.size()-1].size() ; i++)
	{
		if ( min > dp[dp.size()-1][i])
		{
			min = dp[dp.size()-1][i];
		}
	}
	return min;
}
int main ()
{
	vector< vector<int> > triangle;
    int n;
	cin>>n;
	for ( int i = 0 ;  i < n ; i++)
	{
		vector <int> row;
		for ( int j = i ; j <= i ; j++ )
		{
			int t;
			cin>>t;
			row.push_back(t);	
		}	
		triangle.push_back(row);
		row.clear();
	}
	int res;
	res = find(triangle);
	cout<<res;
	return 0;
}
