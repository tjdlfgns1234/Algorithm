#include <bits/stdc++.h>
using namespace std;
void solve();

int dp[1001] = {0};

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
    dp[2] = 3;
    dp[3] = 3;

    for(int i = 3; i <= n;i++)
        dp[i] = 2*dp[i-2] + dp[i-1];
    
    cout << dp[n];
}