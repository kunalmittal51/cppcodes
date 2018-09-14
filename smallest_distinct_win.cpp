#include<bits/stdc++.h>
using namespace std;
int solve(string s)
{
    int dc = 0;
    int start = 0;
    int end = 0;
    int total = 0;
    map<char,int>m,m1;
    while ( end < s.length() )
    {
        if ( m[s[end]] == 0 )
        {
            total++;
            end++;
        }
        m[s[end]]++;
    }
    end = 0;
    int ans = 0;
    while ( end < s.length())
    {
        if ( dc == total ) 
        {
            ans = min(ans,end-start);
        }
        if ( m1[end] == 0)
        {
            dc++;
            m1[s[end]]++;
            end++;
        }
        else 
        {
            m1[s[end]]++;
            while ( start < end && m1[s[start]] >= 2)
            {	
                m1[s[start]]--;
                start++;
            }
            end++;
        }
    }
    ans = min(ans,end-start);
    return ans;
}
int main()
 {
	//code
	int t;
	cin>>t;
	while (t--)
	{
	    string s;
	    cin>>s;
	    cout<<solve(s)<<endl;
	}
	return 0;
}
