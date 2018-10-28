#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int r[1001],c[1001];
long long dp[1001][1001];
long long solve(int st, int ed){
    if(st==ed) return 0;
    if(dp[st][ed]!=-1) return dp[st][ed];
    long long x = solve(st,st)+solve(st+1,ed)+r[st]*c[st]*c[ed];
    for(int i = st+1;i<ed;i++){
        x=min(x,solve(st,i)+solve(i+1,ed)+r[st]*c[i]*c[ed]);
    }
    return dp[st][ed]=x;
}
int main(){
    int n;
    scanf("%d",&n);
    memset(dp,-1,sizeof dp);
    for(int i=0;i<n;i++) scanf("%d",&r[i]);
    for(int i=0;i<n;i++) scanf("%d",&c[i]);
    long long ans = solve(0,n-1);
    printf("%lld\n",ans);
}
