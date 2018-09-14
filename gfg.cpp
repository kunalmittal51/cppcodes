#include <bits/stdc++.h>
using namespace std;
void solve ( vector<int>&nums,vector<int>&res)
{
    int start = 0;
    int end = 0;
    int res_start = 0;
    int res_end = 0;
    int max_sum = 0;
    int cur_sum = 0;
    while ( end < nums.size() )
    {
        if ( nums[end] < 0 )
        {
            if ( max_sum < cur_sum )
            {
                res_start = start;
                res_end = end-1;
                max_sum = max(max_sum, cur_sum);
            }
            else if ( max_sum == cur_sum && cur_sum != 0)
            {
                if ( res_end-res_start > end-start-1)
                {
                    res_start = start;
                    res_end = end-1;
                }
            }
            cur_sum = 0;
            start = end+1;
            end = end+1;
            cout<<max_sum<<"  "<<cur_sum<<"  "<<end<<endl;
        }
        else
        {
            cur_sum += nums[end];
            end++;
        }
    }
    if ( nums[end-1] >= 0)
    {
        if ( max_sum < cur_sum )
            {
                res_start = start;
                res_end = end-1;
                max_sum = max(max_sum, cur_sum);
            }
            else if ( max_sum = cur_sum)
            {
                if ( res_end-res_start > end-start-1)
                {
                    res_start = start;
                    res_end = end-1;
                }
            }
    }
    for ( int i = res_start ; i <= res_end ; i++)
    {
        res.push_back(nums[i]);
    }
}
int main() {
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
	    vector<int>res;
	    solve(nums,res);
	    for ( int i = 0 ; i < res.size() ; i++)
	    {
	        cout<<res[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
	
}
