#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[1000];

ll solve(ll n){
    if(n<0) return 0;
	if(n==0) return 1;
	//if(n==1) return 1;
	if(dp[n]!=-1) return dp[n];
	return dp[n]=solve(n-1)+solve(n-2)+solve(n-2);
}

int main(){
	ll n;
	cin >> n;
	memset(dp,-1,sizeof dp);
	ll ans=solve(n);
	cout << ans << endl;

	return 0;
}
