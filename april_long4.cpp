#include<bits/stdc++.h>
using namespace std;
long long int count (long long int ta ,long long int tb ,vector<vector<int> > &prefix,string s ,long long int times)
{
	long long int n = s.length();
	long long int ans = 0;
	for ( long long int i = 0 ; i < n ; i++)
	{
		if ( ta == tb)
		{
			if ( prefix[i][0] > prefix[i][1] )
			{
				ans = ans + times;			
			}	
		}
		else if ( ta > tb)
		{
			if (prefix[i][0] > prefix[i][1] )
			{
				ans = ans + times;
			}
			else 
			{
				long long int diff = prefix[i][1]-prefix[i][0];
				long long int iter = diff/(ta-tb) + 1;
				if ( times - iter > 0)
				{
					ans = ans + times - iter;
				}
			}
		}
		else
		{
			if ( prefix[i][0] > prefix[i][1])
			{
				long long int diff = prefix[i][0]-prefix[i][1];
				long long int iter ;
				if ( diff%(tb-ta) == 0)
				{
					iter = diff/(tb-ta);
				}
				else
				{
					iter = diff/(tb-ta) +1;
				}
				if ( iter <= times)
				{
					ans = ans + iter;		
				}
				else
				{
					ans = ans + times;
				}
			
			}
		}	
	}
	return ans;
}
long long int solve(string s , long long int n)
{
	vector< vector<int> > prefix;
	vector<int>temp;
	for  ( int j = 0 ; j < 2 ; j++)
	{
		temp.push_back(0);
	}
	for ( int i = 0 ; i < s.length() ; i++)
	{
		prefix.push_back(temp);
	}
	long long int ta = 0;
	long long int tb = 0;
	for ( int i = 0 ; i < s.length() ; i++)
	{
		if ( s[i] == 'a')
		{
			ta++;
			prefix[i][0] = ta;
			prefix[i][1] = tb;
		}
		else
		{
			tb++;
			prefix[i][1] = tb;
			prefix[i][0] = ta;
		}
	}
	return count(ta,tb,prefix,s,n);	
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		long int n;
		cin>>s;
		cin>>n;
		cout<<solve(s,n);
		cout<<endl;
	}
	return 0;
}
