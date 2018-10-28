#include<stdio.h>
#include<string.h>
long long dp[65537][17];
int n,a[17][17];
bool checkbit(int n,long long bt){
    long long mask=1<<n;
    mask=bt&mask;
    return mask==0;
}
long long setbit(int n,long long bt){
    long long mask=1<<n;
    return mask|bt;
}
long long solve(long long bt,int m){
    if(m<0) return 0;
    int i;
    long long ret=-1,ans;
    if(dp[bt][m]!=-1) return dp[bt][m];
    for(i=0;i<n;i++){
        if(checkbit(i,bt)){
            ans=solve(setbit(i,bt),m-1)+a[i][m];
            //printf("%lld %d %d\n",ans,i,m);
            if(ans>ret) ret=ans;
        }
    }
    return dp[bt][m]=ret;
}
int main(){
    int test,i,j,k;
    long long ans;
    scanf("%d",&test);
    for(i=1;i<=test;i++){
        scanf("%d",&n);
        memset(dp,-1,sizeof(dp));
        for(j=0;j<n;j++){
            for(k=0;k<n;k++){
                scanf("%d",&a[j][k]);
            }
        }
        ans=solve(0,n-1);
        printf("Case %d: %lld\n",i,ans);
    }
}
