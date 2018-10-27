#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define red 1
#define green 2
#define blue 3

ll dp[1000][4][4];

ll solve(ll num,int pcol,int fcol){
    if(num==0) return pcol!=fcol;
    if(pcol==0) fcol=pcol;
	if(dp[num][pcol][fcol]!=-1) return dp[num][pcol][fcol];
	dp[num][pcol][fcol]=0;
	if(pcol!=1 ) dp[num][pcol][fcol]+=solve(num-1,1,fcol);
	if(pcol!=2) dp[num][pcol][fcol]+=solve(num-1,2,fcol);
	if(pcol!=3) dp[num][pcol][fcol]+=solve(num-1,3,fcol);
	return dp[num][pcol][fcol];
}

int main()
{
	ll num;
	memset(dp,-1,sizeof dp);
	cin >> num;
	ll ans=solve(num-1,1,1)+solve(num-1,2,2)+solve(num-1,3,3);
	cout << ans << endl;

	return 0;
}

