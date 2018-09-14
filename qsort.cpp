#include<bits/stdc++.h>
using namespace std;
void swap(int *a , int *b)
{
	int temp = *a;
	*b = *a;
	*a = temp;
}
int partition(vector<int>&nums,int start , int end)
{
	int pivot = nums[end];
	int pindex = start;
	for ( int i = start ; i < end ; i++)
	{
		if ( nums[i] <= pivot)
		{
		//	cout<<nums[i]<<"  "<<nums[pindex]<<endl;
			swap(nums[i],nums[pindex]);
		//	cout<<nums[i]<<"  "<<nums[pindex]<<endl;
			pindex++;
		}
	}
	swap(nums[pindex],nums[end]);
	return pindex;
}
void qsort(vector<int>&nums, int start , int end)
{
	if ( start >= end)
	{
		return;
	}
	int index = partition(nums,start,end);
	qsort(nums,start,index-1);
	qsort(nums,index+1,end);
}
int main()
{
	vector<int>nums;
	int n;
	cin>>n;
	for ( int i = 0 ; i < n ; i++)
	{
		int t;
		cin>>t;
		nums.push_back(t);
	}
	qsort(nums,0,nums.size()-1);
	for ( int i = 0 ; i < nums.size() ; i++)
	{
		cout<<nums[i]<<" ";
	}
	cout<<endl;
	return 0;
}
