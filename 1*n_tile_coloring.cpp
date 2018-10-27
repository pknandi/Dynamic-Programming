#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[10000];

ll solve(ll num){
    if(num==0) return 1;
    if(dp[num]!=-1) return dp[num];
    return dp[num]=3*solve(num-1);
}

int main(){
    ll num;
    memset(dp,-1,sizeof dp);
    cin >> num;
    ll ans =solve(num);
    cout << ans << endl;

    return 0;
}
