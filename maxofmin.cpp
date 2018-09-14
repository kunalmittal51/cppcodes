	#include<bits/stdc++.h>
	using namespace std;
	void solve(vector<int>nums,int n)
	{
	    vector< int > pq(n,INT_MIN);
	    vector<vector<int> >dp(n,vector<int>(n,INT_MAX));
	    for ( int len = 1 ; len <= n ; len++)
	    {
	        for ( int i = 0 ; i < n-len+1 ; i++)
	        {
	            int j = i+len-1;
	            if ( i == j)
	            {
	                dp[i][j] = nums[j];
	            }
	            else
	            {
	                dp[i][j] = min(dp[i][j-1],nums[j]);
	            }
	            pq[j-i] = max(pq[j-i],dp[i][j]);
	        }
	    }
	    int ans = INT_MIN;
	    for ( int i = 0 ; i < n ; i++)
	    {
	        cout<<pq[i]<<" ";
	    }
	    cout<<endl;
	    return ;
	}
	int main()
	 {
		//code
		int t;
		cin>>t;
		while (t--)
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
		   solve(nums,n);
		}
		return 0;
	}
