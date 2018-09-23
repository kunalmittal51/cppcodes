#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> L;
		vector<int> G;
		for ( int i = 0 ; i < n ; i++)
		{
			int j;
			cin>>j;
			L.push_back(j);
		}
		for ( int i = 0 ; i < n ; i++)
		{
			int j;
			cin>>j;
			G.push_back(j);
		}
		int temp = 1;
		int temp1 = 1;
		for ( int i = 0 ; i < L.size(); i++)
		{
			if ( L[i] > G[i] )
			{
				temp = 0;
			}
			if ( L[i] > G[n-i-1] )
			{
				temp1 = 0;
			}
		}
		if ( temp == 1 && temp1 == 1)
		{
			cout<<"both"<<endl;
		}
		else if ( temp == 1 && temp1 == 0)
		{
			cout<<"front"<<endl;
		}
		else if ( temp == 0 && temp1 == 1)
		{
			cout<<"back"<<endl;
		}
		else
		{
			cout<<"none"<<endl;
		}
	}
}
