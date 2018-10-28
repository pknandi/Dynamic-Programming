#include<stdio.h>
#include<string>
#include<string.h>
#include<iostream>
using namespace std;

int len;
string a;
long long dp[1001][2][1001];

long long solve(int i,int flag,int sum){
    //printf("%d %d %d\n",i,flag,sum);
    if(sum<0) return 0;
    if(i==len) return (sum==0);
    if(dp[i][flag][sum]!=-1) return dp[i][flag][sum];
    int limit=a[i]-'0',nfl=0;
    if(flag) limit=9;
    long long ans=0;
    for(int d=0;d<=limit;d++){
        nfl=flag;
        if(d<limit) nfl=1;
        ans+=solve(i+1,nfl,sum-d);
    }
    return dp[i][flag][sum]=ans;
}

int main(){
    int sum;
    long long ans=0;
    scanf("%d",&sum);
    memset(dp,-1,sizeof dp);
    cin >> a;
    len=a.size();
    int limit = a[0]-'0';
    for(int i=0;i<=limit;i++){
        ans+=solve(1,(i!=limit),sum-i);
    }
    printf("%lld\n",ans);
}
