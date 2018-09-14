#include<bits/stdc++.h>
using namespace std;
void find (vector<int>&nums)
{
	map<int,int>m;
	for ( int i = 0 ; i < nums.size() ;i++)
	{
		m[nums[i]]++;
	}
	int ans = 0;
	for (auto &p : m)
	{
		if ( p.second > 1 )
		{
			ans = ans + p.second - 1;
		}
	}
	cout<<ans;
}
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		int n;
		cin>>n;
		vector <int> nums;
		for (int i = 0 ; i < n ; i++)
		{
			int j ;
			cin>>j;
			nums.push_back(j);
		}
		find(nums);
	}
	return 0;
}
