#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void sieve(vector<int>&prime,vector<bool>&isprime,int n)
{
	for (int i = 2 ; i <= sqrt(n) ; i++)
	{
		if ( isprime[i] == true)
		{
			for ( int j = 2*i ; j <= n ; j += i)
			{
				isprime[j] = false;
			}
		}
	}
	for ( int i = 0 ; i < isprime.size() ; i++)
	{
		if ( isprime[i] == true)
		{
		   prime.push_back(i);
		}
	}
}
int main()
{
	int n;
	cin>>n;
	vector<int>pn;
	vector<bool>isprime(n+1,true);
	isprime[0] = false;
	isprime[1] = false;
	sieve(pn,isprime,n);
	for (int i = 0 ; i < pn.size() ; i++)
	{
		cout<<pn[i]<<" ";	
	}
	cout<<endl;
	return 0;
}
