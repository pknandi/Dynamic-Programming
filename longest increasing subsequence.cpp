#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int a[1001];
int dp[1001];
int solve(int i){
    if(i<0) return 0;
    if(i==0) return 1;
    if(dp[i]!=-1) return dp[i];
    int b = solve(i-1);
    for(int j=0;j<i;j++){
        if(a[j]<a[i]){
            //printf("%d %d\n",i,j);
            b=max(b,solve(j)+1);
        }
    }
    return dp[i]=b;
}
int main(){
    int n;
    scanf("%d",&n);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int ans = solve(n-1);
    printf("%d\n",ans);
}
