///minimum koyta coin use kore  w banano jay jekhane 1 ta coin specific koekbar ase


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define inf 10000000000000

ll coin[100],fr[100],dp[100000][100],cn,vis[100000][100];

ll solve(ll w,ll i){
    if(w<0) return inf;
    if(w==0) return 0;
    if(i>cn) return inf;
    if(vis[w][i]!=0) return dp[w][i];
    vis[w][i]=1;
    for(ll j=0;j<=fr[i];j++){
        ll a=j+solve(w-j*coin[i],i+1);
        dp[w][i]=min(dp[w][i],a);
    }
    return dp[w][i];
}

int main(){
    int amount;
    cin >> amount >> cn;
    memset(vis,0,sizeof vis);
    for(int i=0;i<100000;i++){
        for(int j=0;j<100;j++) dp[i][j]=10000000;
    }
    for(int i=1;i<=cn;i++){
        scanf("%lld",&coin[i]);
    }
    for(int i=1;i<=cn;i++){
        scanf("%lld",&fr[i]);
    }
    ll ans = solve(amount,1);
    cout << ans << endl;

    return 0;
}