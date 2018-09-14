#include<iostream>
#include<vector>
using namespace std;
int adjust (vector< vector<int> > &matrix )
{
	for ( int i = 1 ; i < matrix.size() ; i++)
	{
		for ( int j = 1 ; j < matrix[i].size() ; j++)
		{	
			if ( matrix[i][j] != -1 ) 
			{
				if ( matrix[i][j] < max(matrix[i-1][j],matrix[i][j-1]))
				{
					return -1;
				}
			}
			else
			{
				matrix[i][j] = max(matrix[i-1][j],matrix[i][j-1]);
			}
		}
	}
	return 0;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n , m;
		cin>>n;
		cin>>m;
		vector<vector<int> >matrix;
		for ( int i = 0 ; i <= n ; i++)
		{
			vector<int>row;
			for ( int j = 0 ; j <= m ; j++)
			{
				if ( i == 0 || j == 0)
				{
					row.push_back(-1000);
				}
				else
				{
					int k;
					cin>>k;
					row.push_back(k);	
				}	
			}
			matrix.push_back(row);
			row.clear();
		}
	
		if ( adjust(matrix) == -1)
		{
			cout<<-1<<endl;
		}
		else
		{
			for ( int i = 1 ; i <= n ; i++)
			{
				for ( int j = 1 ; j <= m ; j++)
				{
					cout<<matrix[i][j]<<" ";			
				}
				cout<<endl;
			}				
		}	
	}
	return 0;
}
