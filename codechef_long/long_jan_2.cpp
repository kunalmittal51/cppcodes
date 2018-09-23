#include<bits/stdc++.h>
using namespace std;
long long int cal ( vector < vector <long long int > >& nums)
{
	long long int sum = 0;
	long long int maximum = INT_MIN;
	long long int row_max = INT_MIN;
	
	if ( nums.size() == 0)
	{
		return -1;
	}
	for ( int i = nums.size()-1 ; i >= 0 ; i--)
	{
		if ( i == nums.size()-1)
		{
			for ( int j = 0 ; j < nums[i].size() ; j++)
			{
				if ( maximum < nums[i][j])
				{
					maximum = nums[i][j];
				}
			}
			sum += maximum;	
		}
		else
		{
			row_max = INT_MIN;
			for ( int j = 0 ; j < nums[i].size() ; j++)
			{
				if ( row_max < nums[i][j] && nums[i][j] < maximum)
				{
					row_max = nums[i][j];
				}
			}
			if ( row_max == INT_MIN)
			{
				return -1;
			}
			sum += row_max;
			maximum = row_max;
	    }
	}
	return sum;
}
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		vector <vector<long long int> > nums;
		int n;
		cin>>n;
		for ( int i = 0 ; i < n ; i++)
		{
			vector <long long int> num;
			for ( int j = 0 ; j < n ; j++)
			{
				long long int k;
				cin>>k;
				num.push_back(k);
			}
			nums.push_back(num);
		}
		long long int sum = cal(nums);
		cout<<sum<<endl;
	}
	return 0;
}
