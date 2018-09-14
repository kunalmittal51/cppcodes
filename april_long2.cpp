#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
bool search (vector<long int>&nums,long int val ,long int start ,long int end )
{
	if ( start > end)
	{
		return false;
	}
	long int mid = start + (end-start)/2;
	if ( 2*nums[mid] == val)
	{
		return true;
	}
	else if ( 2*nums[mid] < val)
	{
		return search(nums,val,mid+1,end);
	}
	else
	{
		return search(nums,val,start,mid-1);
	}
}
long int f (vector<long int>&temp,vector<long int>&m,vector<long int>&v,long int mi)
{
	long int ans = 0;
	for ( long int i = 0 ; i < temp.size() ; i++)
	{
		for (long int j = i+1; j < temp.size() ; j++)
		{
			if ( search( v , temp[i]+temp[j] , 0 , v.size()-1 ) )
			{
				ans = ans + m[temp[i]-mi]*m[temp[j]-mi];
			} 
		}
		if ( m[temp[i]-mi] > 1 )
		{
			ans = ans + m[temp[i]-mi]*(m[temp[i]-mi]-1)/2;
		}
	}
	return ans;
}
	
int main()
{
	long int t;
	cin>>t;
	while(t--)
	{
		long int n;
		cin>>n;
		long int ans = 0;
		vector<long int>nums;
		vector<long int>temp;
		for ( long int i = 0  ; i < n ; i++)
		{
			long int j;
			cin>>j;
			nums.push_back(j);
		}
		long int mi = 0;
		for ( int j = 0 ; j < nums.size() ; j++)
		{
			if ( mi > nums[j])
			{
				mi = nums[j];
			}
		}
		vector<long int>m;
		for ( long int i = 0 ; i < 2010 ; i++)
		{
			m.push_back(0);	
		}
		vector<long int>even;
		vector<long int>odd;
		for ( long int  i = 0 ; i < nums.size() ; i++)
		{
			if(m[nums[i] - mi] == 0)
			{
				temp.push_back(nums[i]);
				if ( nums[i]%2 == 0)
				{
					even.push_back(nums[i]);
				}
				else odd.push_back(nums[i]);
			}
			m[nums[i]-mi]++;
		}
		sort(temp.begin(),temp.end());
		ans = f(even,m,temp,mi)+f(odd,m,temp,mi);
		cout<<ans<<endl;
	}
return 0;	
} 
