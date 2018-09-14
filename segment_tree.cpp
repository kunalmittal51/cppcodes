#include<bits/stdc++.h>
using namespace std;
void construct (vector<int>&in,vector<int>&seg,int low, int high,int pos)
{
	if ( low == high)   //leaf node
	{
		seg[pos] = in[low];
		return;
		
	}
	int mid = low + (high-low)/2;
	construct(in,seg,low,mid,2*pos+1); 					 //recur for left subtree (left child)
	construct(in,seg,mid+1,high,2*pos+2);				 //recur for right subtree (right child)
	seg[pos] = min(seg[2*pos+1],seg[2*pos+2]);  		 //put value for current pos
	return;	
}
int rangemin(vector<int>&seg,int qlow , int qhigh, int low , int high , int pos)
{
	if ( qlow <= low && qhigh >= high)			 //complete overlap (return value)
	{
		return seg[pos];
	}
	if (qlow > high || qhigh < low)				 //no overlap			(no use so return very large value)
	{
		return INT_MAX;
	}
	int mid = low + (high-low)/2;
	return min(rangemin(seg,qlow,qhigh,low,mid,pos*2+1),rangemin(seg,qlow,qhigh,mid+1,high,2*pos+2));  //partial overlap (check in both left and right child)
}
int main()
{
	int n;
	cin>>n;
	vector<int>in;
	for ( int i = 0 ; i < n ; i++)
	{
		int j;
		cin>>j;
		in.push_back(j);
	}
	int max_pos;
	vector<int>segment(4*n,INT_MAX);
	construct(in,segment,0,n-1,0,&max_pos);
	int qlow ,qhigh;
	cin>>qlow>>qhigh;
	cout<<rangemin(segment,qlow,qhigh,0,n-1,0);
	return 0;
}
