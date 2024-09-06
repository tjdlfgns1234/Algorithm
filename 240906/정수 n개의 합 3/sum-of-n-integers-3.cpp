#include <bits/stdc++.h>
using namespace std;

int n,k;
int arr[501][501];
int dp[501][501];

int main() {
    cin >> n >> k;

    for(int i = 1; i <=n;i++)
        for(int j = 1; j <= n; j++)
            cin >> arr[i][j];

    for(int i = 1; i <=n;i++)
        for(int j = 1; j <= n; j++)
            dp[i][j] = dp[i-1][j] +
                      dp[i][j-1] -
                      dp[i-1][j-1] +
                      arr[i][j];
    int ans = 0;

    for(int i = 1; i <= n;i++)
        for(int j = 1; j <= n; j++)
            if(i-k >=0 && j - k>= 0)
                ans = max(ans, dp[i][j] - dp[i-k][j] - dp[i][j-k] + dp[i-k][j-k]);

    cout << ans;

    return 0;
}