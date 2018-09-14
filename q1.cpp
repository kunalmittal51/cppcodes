#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	vector <char>ans ;
	for ( int i = 0 ; i < s.length() ;i++)
	{
		if ( i == 0)
		{
			ans.push_back(s[i]);	
		}	
		else
		{
			if ( ans.size() > 0 && s[i] == ans[ans.size()-1])
			{
				ans.pop_back();
			}
			else
			{
				ans.push_back(s[i]);
			}
		}
	}	
	string res;
	for ( int i = 0 ; i < ans.size() ; i++)
	{
		res = res + ans[i];
	}
	if (ans.size() == 0)
	{
		cout<<"Empty String"<<endl;
	}
	else cout<<res<<endl;
	return 0;
}
