#include <bits/stdc++.h>
using namespace std;
void solve();

int dp[46] = {0};

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

    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= n;i++)
        dp[i] = dp[i-1] + dp[i-2];
    
    cout << dp[n];
}