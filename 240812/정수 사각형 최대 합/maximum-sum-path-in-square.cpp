#include <bits/stdc++.h>
using namespace std;

void solve();
void calc();

int n;
int arr[100][100];
int dp[100][100];

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL), std::cout.tie(NULL);

    solve();

    return 0;
}
void solve() {
    cin >> n;

    for(int i = 0; i < n;i++)
        for(int j = 0; j < n;j++)
            cin >> arr[i][j];

    calc();
}
void calc(){
    dp[0][0] = arr[0][0];
    for(int i = 1; i < n;i++)
        dp[0][i] = dp[0][i-1] + arr[0][i];
    
    for(int i = 1; i < n;i++)
        dp[i][0] = dp[i-1][0] + arr[i][0];


    for(int i = 1; i < n;i++)
        for(int j = 1; j < n;j++)
            dp[i][j] = max(dp[i][j-1] + arr[i][j],dp[i-1][j] + arr[i][j]);

    cout << dp[n-1][n-1];
}