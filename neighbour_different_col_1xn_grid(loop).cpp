#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define red 1
#define green 2
#define blue 3

ll dp[1000][10];

ll solve(ll num,int pcol)
{
    if(num<0) return 0;
    if(num==0 ) return 1;
    if(dp[num][pcol]!=-1 ) return dp[num][pcol];
    int ans=0;
    for(int i=1; i<=3; ++i)
        if(i!=pcol) ans+=solve(num-1,i);
    return dp[num][pcol]=ans;
}

int main()
{
    ll num;
    memset(dp,-1,sizeof dp);
    cin >> num;
    ll ans=solve(num,0);
    cout << ans << endl;

    return 0;
}
