	#include<bits/stdc++.h>
	using namespace std;
	void  z_algo(string &str,vector<int>&z)
	{
		z.push_back(0);
		int left = 0;
		int right = 0;
		for ( int i = 1 ; i < str.length() ; i++)
		{
			if ( right < i) //outside box
			{
				right = i;
				left = i;
				while ( right < str.length() && str[right] == str[right-left])
				{
					right++;
				}
				z.push_back(right-left);
				right--;
			}
			else 
			{
				int j = i - left;
				if ( z[j] < right - i + 1)
				{
					z.push_back(z[j]);
				}
				else
				{
					left = i;
					while ( right < str.length() && str[right] == str[right-left])
					{
						right++;
					}
					z.push_back(right-left);
					right--;
				}
			}
		}
		return ;
	}
	int main()
	{
			int n;
			while (cin>>n)
			{
				getchar();	
				string pat;
				string str;
				getline(cin,pat);
				getline(cin,str);
				string s = pat + '$' + str;
				vector<int>res;
				z_algo(s,res);
				vector<int>ans;
				for ( int i = pat.size()+1 ; i < s.size() ; i++)
				{
					if ( res[i] == pat.size())
					{
						ans.push_back(i - pat.size() - 1);
					}
				}
				cout<<ans.size()<<endl;
				for (int i = 0 ; i < ans.size() ; i++)
				{
					if ( ans.size() == 0)
					{
						cout<<endl;
						break;
					}
					cout<<ans[i]<<endl;
				}
			}		
			return 0;
	}
