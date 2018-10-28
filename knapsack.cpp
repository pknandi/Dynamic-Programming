#include<stdio.h>
#include<algorithm>
#include<limits.h>
#include<string.h>
using namespace std;

long long dp[31][1001];
int w[1001],p[1001];
bool vis[101][1001];

long long solve(int n,int i)
{
    //printf("%d %d\n",n,i);
    if(n<0) return -INT_MAX;
    if(i<0) return 0;
    if(vis[n][i]) return dp[n][i];
    if(n==0) return 0;
    vis[n][i]=1;
    long long ans=0;
    long long x = solve(n-w[i],i-1)+p[i];
    long long y = solve(n,i-1);
    return dp[n][i] = max(x,y);
}
int main()
{
    int i,n,m,c,q,test;
    scanf("%d",&test);
    while(test--)
    {
        long long ans,rans=0;
        memset(dp,0,sizeof(dp));
        memset(vis,0,sizeof(vis));
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            scanf("%d %d",&p[i],&w[i]);
        }
        scanf("%d",&q);
        for(i=0; i<q; i++)
        {
            scanf("%d",&c);
            ans=solve(c,n-1);
            //printf("-> %lld\n",ans);
            if(ans>0) rans+=ans;
        }
        printf("%lld\n",rans);
    }

}
