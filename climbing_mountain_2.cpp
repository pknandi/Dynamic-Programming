///kon way te gele beshi treasure pauya jabe jkhn jauya jay up e , left konakuni,dan konakuni
///and start kora jay nicher row er jekono cell theke



#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define inf 10000000000

ll dp[1000][1000],w[1000][1000];

ll solve(ll x,ll y){
    if(x < 1 || y < 1) return -inf;
    if(x==1 && y==1) return w[x][y];
    if(dp[x][y]!=-1) return dp[x][y];
    return dp[x][y]=w[x][y]+max(max(solve(x-1,y),solve(x-1,y-1)),solve(x-1,y+1));
}

int main(){
    ll num;
    cin >> num;
    memset(dp,-1,sizeof dp);
    for(int i=1;i<=num;i++){
        for(int j=1;j<=num;j++) scanf("%lld",&w[i][j]);
    }
    ll ans=-10000000000000;
    for(int i=1;i<=num;i++){
        ans=max(ans,solve(num,i));
    }
    cout << ans << endl;

    return 0;
}