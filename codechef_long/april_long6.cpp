#include<iostream>
#include<vector>
using namespace std;
long long int findmin(long long int start , long long int end , vector<long long int>&A)
{
	long long int min = 10000000000;
	for ( int i = start+1 ; i < end ; i++)
	{
		if ( min > A[i])
		{
			min = A[i];
		}
	}
	return min;
}
long long int minimum(long long int i , long long int j)
{
	if (i > j)return j ;
	else return i;
}
void solve (vector<long long int>&B,int start , int end,long long int *ans, vector<long long int>&A)
{
	if ( start > end )
	{
		return ;
	}
	long long int max = 0;
	vector<long long int>pos;
	for (long long  int i = start ; i <= end ; i++)
	{
		if ( max < B[i])
		{
			max = B[i];
		}	
	}
	for ( long long int i = start ; i <= end ; i++)
	{
		if ( max == B[i] )
		{
			pos.push_back(i);
		}
	}
	long long int temp = 0;
	long long int temp1 = 0;
	int j = pos.size();
	for (long long int i = 0 ; i < pos.size() ; i++)
	{
		if ( pos.size() >= 2 && B[pos[i]] != A[pos[i]])
		{
			if ( i == j-1  )
			{	
				temp++;	
				temp1++;
			}
			else
			{
				long long int min;
				min = findmin(pos[i],pos[i+1],A);
				if ( min < B[pos[i]] )
				{
					temp++;
				}
				long long int min1 ;
				min1 = findmin(pos[j-i-2],pos[j-i-1],A);
				if ( min1 < B[pos[i]] )
				{
					temp1++;
				}	
			}
		}
		else if ( pos.size() == 1)
		{
			if ( B[pos[i]] != A[pos[i]])
			{
				temp++;
				temp1++;
			}
		}
	}
	(*ans) = (*ans) + minimum(temp,temp1);
	for ( long long int i = 0 ; i < pos.size() ; i++)
	{
		if ( pos.size() >= 2 )
		{
			if ( i == 0 )
			{
				solve(B,start,pos[i]-1,ans,A);
			}
			else if ( i == pos.size()-1 )
			{
				solve(B,pos[i]+1,end,ans,A) ;
				solve(B,pos[i-1]+1,pos[i]-1,ans,A);
			}
			else 
			{
				solve(B,pos[i-1]+1,pos[i]-1,ans,A);	
			}	
		}
		else
		{
			solve(B,start,pos[i]-1,ans,A);
			solve(B,pos[i]+1,end,ans,A);
		}
	}
	return ;
}

int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		int n;
		cin>>n;
		vector<long long int>A;
		vector<long long  int>B;
		for ( int i = 0 ; i < n ; i++)
		{
			long long int j;
			cin>>j;
			A.push_back(j);
		}
		for ( int i = 0 ; i < n ; i++)
		{
			long long  int j;
			cin>>j;
			B.push_back(j);
		}
		
		long long int ans = 0;
		int flag = 0;
		for ( int i = 0 ; i < n ; i++ )
		{
			if ( A[i] < B[i]) 		
			{
				cout<<"-1"<<endl;
				flag = 1;
				break;
			}
		}
		if ( flag != 1)
		{
			solve(B,0,n-1,&ans,A);
			cout<<ans<<endl;
		}
	}
	return 0;
}
