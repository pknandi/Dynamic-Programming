//n ta coin use kore kotovabe w banano jay jekhane 1 ta coin 1 bar e use kora jabe

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll coin[100],dp[100000][100],cn;

ll solve(ll w,ll i){
    if(w<0) return 0;
    if(w==0) return 1;
    if(i>cn) return 0;
    if(dp[w][i]!=-1) return dp[w][i];
    return dp[w][i]=solve(w-coin[i],i+1)+solve(w,i+1);
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