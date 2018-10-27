#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define red 1
#define green 2
#define blue 3

ll dp[1000][4];

ll solve(ll num,int pcol){
    if(num==0) return 1;
	if(dp[num][pcol]!=-1) return dp[num][pcol];
	dp[num][pcol]=0;
	if(pcol!=1) dp[num][pcol]+=solve(num-1,1);
	if(pcol!=2) dp[num][pcol]+=solve(num-1,2);
	if(pcol!=3) dp[num][pcol]+=solve(num-1,3);
	return dp[num][pcol];
}

int main()
{
	ll num;
	memset(dp,-1,sizeof dp);
	cin >> num;
	ll ans=solve(num,0);
	cout << ans << endl;

	return 0;
}
