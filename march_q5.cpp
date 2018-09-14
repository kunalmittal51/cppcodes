#include<bits/stdc++.h>
#include<cstdint> 
#include<stdint.h>
using namespace std;
void find (vector <long long int> &nums ,int L , int R)
{
	long long int ans = 0;
	int max_digits = 0;
	for ( int i = L ; i <= R ; i++)
	{
		ans = ans^nums[i];
		max_digits = max(max_digits,log10((double)nums[i])/log10(2));
	}
	long long int res;
	vector<int>t ;
	while (max_digits > 0)
	{
		t.push_back(ans%2);
		ans = ans/2;
		max_digits--;
	}
	long long int i = 0;
	for ( int i = 0 ; i < t.size() ; i++ )
	{
		res = res + pow(2,t[i]);
	}
	for ( int j = i ; j < 31 ; j++)
	{
		res = res + pow(2,j);
	}
	int temp = res;
	while(temp)
	{
		cout<<temp%2;
		temp /= 2;
	}
	cout<<res<endl;
	cout<<endl;
	return;
}
int main ()
{
		int N;
		cin>>N;
		int q;
		cin>>q;
		vector<long long int>nums;
		for ( int i = 0 ; i < N ; i++)
		{
			long long int j;
			cin>>j;
			nums.push_back(j);
		}
		while(q--)
		{
			int L;
			int R;
			cin>>L;
			cin>>R;
			find(nums,L,R);
		}
		return 0;
}
