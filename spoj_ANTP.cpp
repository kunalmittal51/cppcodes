#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	
	while(n--)
	{
		unsigned long long int x , y;
		cin>>x>>y;
		unsigned long long int sum = 0;
		for ( int i = x ; i <= y ; i++ )
		{
			if ( i > 2 )
			{
				sum += (i-1)*(i-2)/2;  // for any i possible ways is C(i-1,2) for 3 boxes //
			}
		}	
		cout<<sum<<endl;
	}
	return 0;
}
