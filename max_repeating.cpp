#include<bits/stdc++.h>
using namespace std;
int solve ( vector<int>&nums,int k)
{
    for ( int i = 0 ; i < nums.size() ; i++)
    {
      //  cout<<nums[i]<<endl;
        nums[nums[i]] = nums[nums[i]] + k;
    }
    int max_index = -1;
    int max_val  = -1;
    for ( int i = 0 ; i < nums.size() ; i++)
    {
        if ( max_val < nums[i])
        {
            max_val = nums[i];
            max_index = i;
        }
    }
    
    return max_index;
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
	   int k;
	   cin>>k;
	   vector<int>nums;
	   for ( int i = 0 ; i < n ; i++ )
	   {
	       int j;
	       cin>>j;
	       nums.push_back(j);
	   }
	   cout<<solve(nums,k)<<endl;
	}
	return 0;
}
