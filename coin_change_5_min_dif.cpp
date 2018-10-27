//n ta coin use kore kivabe 2 vag e vag kora jay jeno difference minimum hoy

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll coin[100],dp[100000][100],cn,vis[100000][100];

ll solve(ll w,ll i){
    if(w<0) return 0;
    if(w==0) return 1;
    if(i>cn) return 0;
    if(vis[w][i]!=0) return dp[w][i];
    vis[w][i]=1;
    int a=solve(w-coin[i],i+1);
    int b=solve(w,i+1);
    dp[w][i]=a || b;
    return dp[w][i];
}

int main(){
    int amount,ans;
    cin >> amount >> cn;
    memset(vis,0,sizeof vis);
    for(int i=1;i<=cn;i++){
        scanf("%lld",&coin[i]);
    }
    for(int i=amount/2;i>=0;i--){
        if(solve(i,1)==1){
            ans=i;break;
        }
    }
    cout << ans << endl;

    return 0;
}