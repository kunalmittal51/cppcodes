#include<bits/stdc++.h>
using namespace std;
int solve (int A[] , int start , int end,vector<vector<int> >&dp)
{
    // cout<<start<<"  igheih   "<<end<<endl;
    if ( dp[start][end] != -1 ) return dp[start][end];
    int ans1 = 0;
    int ans2 = 0;
    if ( start == end)
    {
    //	cout<<start<<"  "<<end<<" differnce 0 "<<endl;
        dp[start][end] = A[start];
        return A[start];
    }
    else if ( start == end-1)
    {
       // cout<<start<<"  "<<end<<"  difference 1 "<<endl;
		dp[start][end] =  max(A[start],A[end]);
        return max(A[start],A[end]);
    }
    else
    {
        if ( A[start+1] > A[end])
        {
            ans1 = (A[start]+solve(A,start+2,end,dp));
          //  cout<<ans1<<"  "<<start<<endl;
        }
        else 
        {
            ans1 = (A[start]+solve(A,start+1,end-1,dp));
        }
        if ( A[start] > A[end-1])
        {
            ans2 = (A[end]+solve(A,start+1,end-1,dp));
        }
        else
        {
            ans2 = (A[end]+solve(A,start,end-2,dp));
        }
        dp[start][end] = max(ans1,ans2);
        return dp[start][end];
    }
}
int maxCoins(int A[],int N)
{
   //Your code 
   int start = 0;
   int end = N-1;
   int ans = 0;
   cout<<start<<" "<<end<<endl;	
   vector<vector<int> >dp;
   for ( int i = 0 ; i <= end ; i++)
   {
   		vector<int>row;
	    for ( int j = 0 ; j <= end ; j++)
	   	{
	   		row.push_back(-1);
	    }
		dp.push_back(row);
   }
   return solve(A,start,end,dp);
}
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for ( int i = 0 ; i < n ; i++)
		{
			int j;
			cin>>j;
			arr[i] = j;
		}
		cout<<maxCoins(arr,n)<<endl;
	}
}
