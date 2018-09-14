#include<bits/stdc++.h>
using namespace std;
long long int max_sum ( vector <long long int> &nums)
{
	long long int max_sum = nums[0];
	long long int max_sofar = nums[0];
	for ( int i = 1 ; i < nums.size() ; i++)
	{
		max_sofar = max(nums[i], max_sofar + nums[i]);
		max_sum = max ( max_sum, max_sofar);
	}
	return max_sum;
}
// subtask 1
// o(n*k) approch

int main()
{
	int t;
	cin>>t;
	while ( t--)
	{
		int n , k;
		cin>>n;
		cin>>k;
		vector <long long int> nums;
		for ( int i = 0 ; i < n ; i++)
		{
			int j;
			cin>>j;
			nums.push_back(j);
		}
		for ( int j = 1 ; j < k ; j++)
		{
			for ( int i = 0 ; i < n ; i++)
			{
				nums.push_back(nums[i]);
			}
	    }
		cout<<max_sum (nums)<<endl;
	}
	return 0;
	
}
