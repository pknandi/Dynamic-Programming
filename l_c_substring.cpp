#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

string a, b;
int ans = -1, dp[100][100];

int solve(int x, int y) {
    if(x<0 || y<0) return 0;
    if(dp[x][y] != -1) return dp[x][y];
    solve(x-1, y);
    solve(x, y - 1);   
    if(a[x] == b[y]) {
        dp[x][y] = 1 + solve(x-1, y-1);
        ans = max(ans, dp[x][y]);
        return dp[x][y];
    }
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> a >> b;
    solve(a.length() - 1, b.length() - 1);
    cout << ans << endl;
}
