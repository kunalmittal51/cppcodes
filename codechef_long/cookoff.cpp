#include<bits/stdc++.h>
using namespace std;
void beautiful(vector<int> &nums)
{
	map<int,int> m;
	m[0] = 0;
	m[1] = 0;
	m[2] = 0;
	m[3] = 0;
	for ( int i = 0 ; i < nums.size() ; i++)
	{
		m[nums[i]%4]++;
	}
	int res = 0;
	if ( m[1] != m[3] || m[2]%2 != 0)
	{
		cout<<"-1"<<endl;
		return ;
	}
	else
	{
		res = res + m[3] + m[2]/2;
	}
	cout<<res<<endl;
	return ;
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
		while (n--)
		{
			int k;
			cin>>k;
			nums.push_back(k);
		}
		beautiful(nums);
	}
	return 0;
}
