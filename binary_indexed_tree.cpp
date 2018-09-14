#include<bits/stdc++.h>
using namespace std;
vector<int> update ( int index , int val , vector<int> &binaryindexed, int n )
{
	index++;
	cout<<binaryindexed.size()<<endl;
	while ( index <= n)
	{
		binaryindexed[index] += val;
		index += (index&(-index));
	}
	return binaryindexed;
}
int sum ( vector<int> &binaryindexed , int index)
{
	index++;
	int sum = 0;
	while ( index > 0)
	{
		sum += binaryindexed[index];
		index = index - (index&(-index));
	}
	return sum;
}
vector <int> Construct (vector<int> &arr, vector<int> &binaryindexed)
{
	for ( int i = 0 ; i < arr.size() ; i++)
	{
		binaryindexed = update(i,arr[i],binaryindexed,arr.size());
		
	}
	return binaryindexed;
}
int main()
{
	int t;
	cin>>t;
	vector <int> arr;
	for ( int i = 0 ; i < t ; i++)
	{
		int j;
		cin>>j;
		arr.push_back(j);
	}
	vector<int> binaryindexed;
	for ( int i = 0 ; i <= t ; i++)
	{
		binaryindexed.push_back(0);
	}
	binaryindexed = Construct(arr,binaryindexed);
	for ( int i = 0 ; i < binaryindexed.size() ; i++)
	{
		cout<<binaryindexed[i]<<" ";
	}
	cout<<endl<<sum(binaryindexed,4)<<endl;
	return 0;
}
