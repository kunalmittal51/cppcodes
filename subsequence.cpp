#include<bits/stdc++.h>
using namespace std;
int subsequence(string s , vector<string>words)
{
	int ans = 0;
	for ( int i = 0 ; i < words.size() ; i++)
	{
		string temp = words[i];
		int k = 0;
		for ( int j = 0 ; j < s.length() ; j++)
		{
			if (temp[k] == s[j])
			{
				k++;
			}
			if ( k == temp.size())
			{
				ans++;
				break;
			}
		}
	}
	return ans;
}
int main()
{
	string s;
	cin>>s;
	vector<string>words;
	int n;
	cin>>n;
	for ( int i = 0 ; i < n ; i++)
	{
		string t;
		cin>>t;
		words.push_back(t);
	}
	cout<<subsequence(s,words);
	return 0;
}

