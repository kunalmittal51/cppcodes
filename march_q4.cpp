#include<bits/stdc++.h>
using namespace std;
long long int find(vector<long long int>&nums,long long int h)
{
	
	sort(nums.begin(),nums.end());
	long long int start = 0;
	long long int end = nums[nums.size()-1];
	long long int mid;
	while ( start <= end)
	{
		int hours = 0;
		mid = start + (end-start)/2;
		for ( long long int i = 0 ; i < nums.size() ; i++)
		{
			if ( nums[i] <= mid)
			{
				hours++;
			}
			else
			{
				if ( nums[i]%mid == 0)
				{
					hours = hours+nums[i]/mid;
				}
				else
				{
					hours = hours+(nums[i]/mid)+1;
				}
			}
		}
		if ( start == end )
		{
			return mid;
		}
		else if  ( hours > h)
		{
			start = mid+1;
		}
		else 
		{
			end = mid;
		}	
	}
}
int main()
{
	int n;
	cin>>n;
	while (n--)
	{
		int N;
		cin>>N;
		long long int h;
		cin>>h;
		vector<long long int> nums;
		for ( int i = 0 ; i < N ; i++)
		{
			int j;
			cin>>j;
			nums.push_back(j);
		}
		cout<<find(nums,h)<<endl;
	}
}
