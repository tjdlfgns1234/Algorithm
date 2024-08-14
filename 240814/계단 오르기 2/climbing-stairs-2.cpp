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
   
    dp[1][1] = arr[1];

    dp[2][0] = arr[2];
    dp[2][2] = arr[1] + arr[2];
    
    for(int i = 3; i <= n; i++) {
        for(int j = 0; j <= 3; j++) {
            if (dp[i - 2][j] != 0)
                dp[i][j] = max(dp[i][j], dp[i - 2][j] + arr[i]);
            if(j && dp[i - 1][j - 1] != 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + arr[i]);
        }
    }
    
    int ans = INT_MIN;
    for (int i = 0; i <= 3; i++)
        ans = max(ans, dp[n][i]);
    cout << ans;
}