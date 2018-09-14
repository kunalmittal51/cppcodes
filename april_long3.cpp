#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long int power (long long int p , long long int b)
{
	if ( p == 0)
	{
		return 1;
	}
	else if ( p%2 == 0) 
	{
		long long int ans = power(p/2,b);
		return (ans*ans)%1000000007;
	}
	else
	{
		long long int ans = power(p/2,b);
		return (b*ans*ans)%1000000007;
	}
}
long long int solve (long long int n ,long long int w)
{ 
	long long int ans = 0;
	if ( w >= 10 || w <= -10 )
	{
		return 0;
	}
	else 
	{
			ans = (w<0)?(10+w):(9-w);
			long long int middle = power(n-2,10);
			ans = (ans*middle)%1000000007;
	}
	return ans;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int n;
		long long int w;
		cin>>n>>w;
		cout<<solve(n,w);
		cout<<endl;
	}
	return 0;
}
