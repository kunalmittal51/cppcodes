#include<bits/stdc++.h>
using namespace std;
int main()
{
		int t;
		cin>>t;
    	while ( t--)
        {
        	map <int,int> m;
        	for ( int i = 0 ; i < 4 ; i++)
        	{
        		int j;
        		cin>>j;
        		m[j]++;
        	}
        	if ( m.size() == 2 )
        	{
        		for (auto &p : m)
        		{
        			if ( p.second != 2)
        			{
        				cout<<false<<endl;
        			}
        		}
        		return true<<endl;
        	}
        	else cout<<false<<endl;
        }
        return 0;
}
