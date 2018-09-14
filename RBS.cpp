#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		int n;
		int nums;
	    cin>>n;
		cin>>nums;
	    int temp = 1;
	    int cnt = 0;
	    while ( nums%5000 != 0 )
	    {
	    	nums = nums-temp;
	    	temp++;
	    	cout<<nums<<endl;
	    	cnt++;
		}
		cout<<(nums-5000*cnt)/5000<<endl;
	} 
	return 0;
}
