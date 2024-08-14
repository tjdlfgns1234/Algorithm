#include <bits/stdc++.h>
using namespace std;

void solve();
void calc();

int n;
int arr[1001] = {0};
int dp[1001][4] = {0};

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL), std::cout.tie(NULL);

    solve();

    return 0;
}
void solve() {
    cin >> n;

    for(int i = 1; i <= n;i++)
        cin >> arr[i];

    calc();
}
void calc(){
    for(int i = 0; i <= n;i++)
        for(int j = 0; j <= 3;j++)
            dp[i][j] = INT_MIN;

    dp[0][0] = 0;

    for(int i = 0; i <= n;i++){
        dp[i][0] = dp[i-1][0];
        for(int j = 0; j <= 3;j++){
            if(dp[i][j] == INT_MIN)
                continue;

            if (i + 1 <= n && j + 1 <= 3)
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + arr[i + 1]);

            if (i + 2 <= n)
                dp[i + 2][j] = max(dp[i + 2][j], dp[i][j] + arr[i + 2]);
        }
    }
    
    int ans = INT_MIN;
    for (int i = 0; i <= 3; i++)
        ans = max(ans, dp[n][i]);
    cout << ans;
}