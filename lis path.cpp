#include<bits/stdc++.h>
using namespace std;

int path[1000][1000],dp[1000][1000],num[1000];

int solve(int i,int pre){
    if(i<0) return 0;
    if(dp[i][pre]!=-1) return dp[i][pre];
    int a=solve(i-1,pre),b=0;
    if(num[i]<num[pre]) b=solve(i-1,i)+1;
    if(b>a)
    path[i][pre]=1;
    return dp[i][pre]=max(b,a);
}

int main(){
    int n;
    cin >> n;
    memset(dp,-1,sizeof dp);
    for(int i=0;i<n;i++) cin >> num[i];
    num[n]=INT_MAX;
    int ans=solve(n-1,n);
    int bla=n-1,pre=n;
    cout <<"size->"<< ans << endl;
    for(int i=n-1;i>=0;i--)
    {
        if(path[i][pre])
        {
            pre=i;
            printf("%d\n",num[i]);
        }
    }

    return 0;
}
