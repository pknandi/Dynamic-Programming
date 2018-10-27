#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define red 1
#define green 2
#define blue 3

ll dp[1000][4][4];

ll solve(ll num,int pcol,int fcol)
{
    if(num<0) return 0;
    if(num==0) return pcol!=fcol;
    if(dp[num][pcol][fcol]!=-1 ) return dp[num][pcol][fcol];
    int ans=0;
    for(int i=1; i<=3; ++i)
        if(i!=pcol) ans+=solve(num-1,i,fcol);
    return dp[num][pcol][fcol]=ans;
}

int main()
{
    ll num;
    memset(dp,-1,sizeof dp);
    cin >> num;
    ll ans=0;
    for(int i=1;i<=3;i++) ans+=solve(num-1,i,i);
    cout << ans << endl;

    return 0;
}
