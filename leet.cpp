#include<bits/stdc++.h>
using namespace std;

double calculate(int N , int K , int r , int c , double prob ,int  count , vector<vector<int> &positon )
{
    if ( k == count-1 )
    {
        return *prob;
    }
    count++;
    for ( int i = 0 ; i < 8 ; i++)
    {
        int x_position = r+position[i][0];
        int y_position = c + position[i][1];
        int cnt = 0;
        if ( issafe ( x_position , y_position , N ))
        {
           cnt++;
           calculate ( N, k , x_position, y_position ,count , prob)   ;
        }
	}
	    prob *= (cnt/8);
        return prob;   
}

double knightProbability(int N, int K, int r, int c) 
{	double prob = 1;
	vector <vector<int>> position;
    position = {{2,1},{2,-1},{1,2},{-1,2},{-2,-1},{-2,1},{-1.-2},{1,-2}};
    prob = calculate( N, K,  r,  c,prob,1, position) ;
    return prob;
    }
}
int main ()
{
	int N , k , c ,r  );
	cin>>N>>k>>c>>r;
	cout<<knightProbability(int N, int k , int r , int c );
	return 0;
}
