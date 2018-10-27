#include<bits/stdc++.h>
using namespace std;

#define inf 100000000

int dp[1000][1000];
string a,b;

int solve(int x,int y){
    if(x < 0 || y < 0) return 0;
    if(dp[x][y]!=-1) return dp[x][y];
    if(a[x]==b[y]){
        dp[x][y]=solve(x-1,y-1)+1;
    }
    else return dp[x][y]=max(solve(x-1,y),solve(x,y-1));
    return dp[x][y];
}

int main(){
    cin >> a >> b;
    memset(dp,-1,sizeof dp);
    int len1=a.size();
    int len2=b.size();
    int ans = solve(len1-1,len2-1);
    cout << ans << endl;

    return 0;
}