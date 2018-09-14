#include<bits/stdc++.h>
using namespace std;
long long int add ( vector < int> &nums)
{
	long long int sum = 0;
	for ( int i = 0 ; i < nums.size() ; i++)
	{
		sum += nums[i];
	}
	return sum;
}
long long int kedane  ( vector <int> &nums)
{
	int max_so_far = nums[0];
	int cur_max = nums[0];
	for ( int i = 1 ; i < nums.size() ; i++)
	{
		cur_max = max(nums[i], cur_max + nums[i]);
		max_so_far = max(max_so_far , cur_max);
	}
	return max_so_far;
}
long long int max_sum_circular_subarray (vector <int> &nums,long long int sum)
{
	vector <int> num;
	for ( int i = 0 ; i < nums.size() ; i++)
	{
		num.push_back(-nums[i]);
	}
	long long int negative = kedane ( num );
	if ( sum == -1*negative)
	{
		return kedane(nums);
	}
	else {
		return max(kedane(nums),negative+sum);
	}
}

int main()
{
	int t;
	cin>>t;
	while ( t--)
	{
		int n , k;
		cin>>n;
		cin>>k;
		vector <int> nums;
		for ( int i = 0 ; i < n ; i++)
		{
			int j;
			cin>>j;
			nums.push_back(j);
		}
		long long int sum = add(nums);
    	long long int sum_subarray = kedane(nums);
    	long long int circular_sum_subarray = max_sum_circular_subarray(nums,sum);
    	if ( sum_subarray == circular_sum_subarray)
    	{
			cout<<max(max(circular_sum_subarray,sum*k),sum*(k-1)+circular_sum_subarray)<<endl;
		
		}
		else 
		{
			cout<<max(max(circular_sum_subarray,sum*k),sum*(k-2)+circular_sum_subarray)<<endl;
		}
	}
	return 0;
}

