///kon way te gele beshi treasure pauya jabe jkhn jauya jay left e , up e , left konakuni


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define inf 10000000000

ll dp[1000][1000],w[1000][1000];

ll solve(ll x,ll y){
    if(x < 1 || y < 1) return -inf;
    if(x==1 && y==1) return w[x-1][y-1];
    if(dp[x][y]!=-1) return dp[x][y];
    return dp[x][y]=w[x-1][y-1]+max(max(solve(x-1,y),solve(x-1,y-1)),solve(x,y-1));
}

int main(){
    ll num;
    cin >> num;
    memset(dp,-1,sizeof dp);
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++) scanf("%lld",&w[i][j]);
    }
    ll ans=solve(num,num);
    cout << ans << endl;

    return 0;
}