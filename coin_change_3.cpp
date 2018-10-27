///minimum koyta coin use kore  w banano jay jekhane 1 ta coin 1 bar use kora jabe


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define inf 10000000000000

ll coin[100],dp[100000][100],cn;

ll solve(ll w,ll i){
    if(w<0) return inf;
    if(w==0) return 0;
    if(i>cn) return inf;
    if(dp[w][i]!=-1) return dp[w][i];
    int a=1+solve(w-coin[i],i+1);
    int b=solve(w,i+1);
    return dp[w][i]=min(a,b);
}

int main(){
    int amount;
    cin >> amount >> cn;
    memset(dp,-1,sizeof dp);
    for(int i=1;i<=cn;i++){
        scanf("%lld",&coin[i]);
    }
    ll ans = solve(amount,1);
    cout << ans << endl;


    return 0;
}