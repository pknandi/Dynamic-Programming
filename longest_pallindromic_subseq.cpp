#include<bits/stdc++.h>
using namespace std;

#define inf 100000000

int dp[1000][1000];
string a,b;

int solve(int x,int y){
    int p=0;
    if(x>y) return 0;
    if(x==y) return 1;
    if(a[x]==a[y]){
        dp[x][y]=solve(x+1,y-1)+2;
    }
    else dp[x][y]=max(solve(x+1,y),solve(x,y-1));
    return dp[x][y];
}

int main(){
    cin >> a;
    memset(dp,-1,sizeof dp);
    int len1=a.size();
    int ans = solve(0,len1-1);
    cout << ans << endl;

    return 0;
}