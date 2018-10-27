/// it is a 0-1 knapsack


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define inf 10000000000000

ll wg[100],p[100],dp[100000][100],cn;

ll solve(ll w,ll i){
    if(w<0) return -inf;
    if(i>cn) return 0;
    if(dp[w][i]!=-1) return dp[w][i];
    ll a=p[i]+solve(w-wg[i],i+1);
    ll b=solve(w,i+1);
    return dp[w][i]=max(a,b);
}

int main(){
    ll amount;
    cin >> cn >> amount;
    memset(dp,-1,sizeof dp);
    for(int i=1;i<=cn;i++){
        scanf("%lld",&wg[i]);
    }
    for(int i=1;i<=cn;i++){
        scanf("%lld",&p[i]);
    }
    ll ans = solve(amount,1);
    cout << ans << endl;

    return 0;
}