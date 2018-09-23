#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		double sum = 0;
		cin>>n;
		double price , quantity , discount;
		for ( int i = 0 ; i < n ; i++)
		{
			cin>>price;
			cin>>quantity;
			cin>>discount;
			discount = discount*.01;
			sum = sum + -1*quantity*( (1-1*discount)*(price+discount*price) - price );
		}
		printf("%lf\n",sum);
	 
	}
	return 0;
}
