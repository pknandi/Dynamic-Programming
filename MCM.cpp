#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int sum[101],a[101];
long long dp[101][101];
long long solve(int st,int en){
   if(st==en) return 0;
   int i,z=0;
   if(dp[st][en]!=-1) return dp[st][en];
   if(st-1>=0) z=sum[st-1];
   long long y,x = solve(st+1,en)+a[st]*((sum[en]-sum[st])%100);
   for(i=st+1;i<en;i++){
       y=solve(st,i)+solve(i+1,en)+((sum[i]-z)%100)*((sum[en]-sum[i])%100);
       x=min(x,y);
   }
   return dp[st][en]=x;
}
int main(){
   int n,i;
   while(scanf("%d",&n)!=EOF){
       memset(dp,-1,sizeof(dp));
       for(i=0;i<n;i++){
           scanf("%d",&a[i]);
       }
       sum[0]=a[0];
       for(i=1;i<n;i++) sum[i]=a[i]+sum[i-1];
       long long ans=solve(0,n-1);
       printf("%lld\n",ans);
   }
}