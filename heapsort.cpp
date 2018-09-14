#include<bits/stdc++.h>
using namespace std;
void swap (int *i , int *j)
{
	int temp = *i;
	*i = *j;
	*j = temp;
}
void heapify (vector<int>&nums,int parent,int size)
{
	int lchild = parent*2+1;
	int rchild = parent*2+2;
	int largest = parent;
	if ( lchild < size && nums[parent] < nums[lchild])
	{
		largest = lchild;
	}
	if ( rchild < size && nums[largest] < nums[rchild])
	{
		largest = rchild;
	}
	if ( largest != parent )
	{
		swap(&nums[largest],&nums[parent]);
		heapify(nums,largest,size);
	}
	
}
void heapsort (vector<int>&nums)
{
	int n = nums.size();
	for ( int i = n/2-1 ; i >= 0 ; i--)
	{
		heapify(nums,i,n);
	}
	for ( int i = n-1 ; i >= 0 ; i--)
	{
		swap(&nums[0],&nums[i]);
		heapify(nums,0,i);
	}
	return;
}
int main()
{
	int n;
	cin>>n;
	vector<int>nums;
	for ( int i = 0 ; i < n ; i++)
	{
		int j;
		cin>>j;
		nums.push_back(j);
	}
	heapsort(nums);
	for ( int i = 0 ; i < nums.size() ; i++)
	{
		cout<<nums[i]<<"   ";
	}
	return 0;
}
