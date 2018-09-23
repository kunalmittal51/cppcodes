#include<iostream>
#include<vector>
using namespace std;
int min (int i , int j)
{
	if ( i < j)
	{
		return i;
	}
	else return j;
}
int main()
{
	int n;
	cin>>n;
	vector<int>c;
	vector<int>t;
	for ( int i = 0 ; i < n ; i++)
	{
		int j ;
		cin>>j;
		c.push_back(j);
	}
	for ( int i = 0 ; i < n ; i++)
	{
		int j ;
		cin>>j;
		t.push_back(j);
	}
	int min1 = 10000000;
	int min2 = 10000000;
	int min3 = 10000000;
	for ( int i = 0 ; i < n ; i++)
	{
		if ( t[i] == 1 && min1 > c[i])
		{
			min1 = c[i];
		}
		else if ( t[i] == 2 && min2 > c[i])
		{
			min2 = c[i];
		}
		else if ( t[i] == 3 && min3 > c[i])
		{
			min3 = c[i];
		}
	}
	int ans = min(min1+min2,min3);
	cout<<ans<<endl;
	return 0;
}
