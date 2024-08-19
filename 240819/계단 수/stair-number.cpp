#include <bits/stdc++.h>
#define mod ((int)(1e9+7))
using namespace std;

void solve();
int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL), std::cout.tie(NULL);

    solve();

    return 0;
}
void solve() {
    int n;
    cin >> n;

    vector<vector<int>> dp(1001,vector<int>(10));

    // 초기값 세팅
    for (int i = 1; i < 10; i++)
        dp[1][i] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][1];
        dp[i][9] = dp[i - 1][8];
        for (int k = 1; k < 9; k++) 
            dp[i][k] = (dp[i - 1][k - 1] + dp[i - 1][k + 1]) % mod;
        
    }

    long long ans = 0;
    for (int i = 0; i < 10; i++) 
        ans =(ans + dp[n][i]) % mod;
    
    cout << ans;

}