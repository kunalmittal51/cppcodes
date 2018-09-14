#include<bits/stdc++.h>
using namespace std;
double solve (double n, double tc, vector<double>&V,vector<double>&D,vector<double>&P,vector<double>&C)
{
	double min_time = 0;
	for ( int i = 0 ; i < n ; i++)
	{
		if ( D[i] == 1) // car moving up
		{
			P[i] = P[i] + V[i]*min_time; // update position of car
			if ( P[i] >= 0 ) 
			{
				if (P[i] > C[i])
				{	
					min_time += tc; 
				//cout<<"case1 "<<min_time<<endl;
				}
				else 
				{
					if ( P[i] == C[i] ) //just leaving
					{
						min_time += tc + (10e-6)/V[i];
					}
					else min_time += tc + (C[i]-P[i])/V[i];
				//cout<<"case2 "<<min_time<<endl;
				}
			}	
			else
			{
				if ( abs(P[i]) - V[i]*tc >= 10e-6)
				{
			    	min_time += tc;
				}
				else 
				{
					min_time += tc + abs(P[i]/V[i]) + C[i]/V[i];
				//cout<<"case3 "<<min_time<<endl;
				}	
			} 
		}
		else          // car moving down
		{
			P[i] = P[i] - V[i]*min_time; //update position of car
			if ( P[i] < 0)
			{
				if ( abs(P[i]) > C[i] )
				{
					min_time += tc;
				}
				else 
				{
					if ( P[i] == C[i] ) //just leaving
					{
						min_time += tc + (10e-6)/V[i];
					}
					else min_time += tc + (C[i]+P[i])/V[i];
				//cout<<"case2 "<<min_time<<endl;
				}
			}
			else 
			{
				if ( P[i]-V[i]*tc >= 10e-6 )
				{	
					min_time += tc ;
				}	
				else      //one condition
				{
					min_time += tc + P[i]/V[i] + C[i]/V[i];
				//cout<<"case3 "<<min_time<<endl;
				}	
			}
		}
		//cout<<min_time<<"  "<<i<<endl;
	}
	return min_time;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		double n , s , y;
		vector<double>V;
		vector<double>D;
		vector<double>P;
		vector<double>C;
		cin>>n>>s>>y;
		for ( int i = 0 ; i < n ; i++)
		{
			int j;
			cin>>j;
			V.push_back(j);
		}
		for ( int i = 0 ; i < n ; i++)
		{
			int j;
			cin>>j;
			D.push_back(j);
		}
		for ( int i = 0 ; i < n ; i++)
		{
			long long int j;
			cin>>j;
			P.push_back(j);
		}
		for ( int i = 0 ; i < n ; i++)
		{
			int j;
			cin>>j;
			C.push_back(j);
		}
		double tc = y/s;
		std::cout << std::setprecision(6) << std::fixed;
	    //cout<<tc<<endl;
		double ans = solve(n,tc,V,D,P,C);
		cout<<ans<<endl;
	}
	return 0;
} 	

