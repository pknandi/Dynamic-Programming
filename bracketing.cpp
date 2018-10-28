#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<string.h>
#include<limits.h>
using namespace std;
string a;
long long dp[1001][1001];
long long solve(int st,int en){
    if(st>en) return 0;
    if(dp[st][en]!=-1) return dp[st][en];
    long long z,x = INT_MAX;
    for(int i = st+1;i<=en;i++){
        z=solve(st+1,i-1)+solve(i+1,en);
        if(a[st]==')') z++;
        if(a[i]=='(') z++;
        x=min(z,x);
    }
    return dp[st][en]=x;
}
int main(){
    cin >> a;
    memset(dp,-1,sizeof dp);
    int len = a.size()-1;
    long long ans = solve(0,len);
    printf("%lld\n",ans);
}
