#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int>A;
		vector<int>B;
		int sumA = 0;
		int sumB = 0;
		int maxA = INT_MIN;
		int maxB = INT_MIN;
		for ( int i = 0 ; i < n ; i++)
		{
			int j ;
			cin>>j;
			A.push_back(j);
			if ( j > maxA)
			{
				maxA=j;
			}
		}
		for ( int i = 0 ; i < n ; i++)
		{
			int j ;
			cin>>j;
			B.push_back(j);
			if ( maxB < j)
			{
				maxB = j;
			}
		}
		for ( int i = 0 ; i < n ; i++)
		{
			sumA += A[i];
		}
		for ( int i = 0 ; i < n ; i++)
		{
			sumB += B[i];
		}
		if ( sumA-maxA < sumB-maxB)
		{
			cout<<"Alice"<<endl;
		}
		else if ( sumB-maxB < sumA-maxA)
		{
			cout<<"Bob"<<endl;
		}
		else cout<<"Draw"<<endl;
	}
	return 0;
}
