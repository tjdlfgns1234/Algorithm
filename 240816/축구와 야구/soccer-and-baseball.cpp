#include <bits/stdc++.h>
using namespace std;

void solve();
void calc();

int n;
int arr[1001] = {0}; // 축구
int arr2[1001] = {0}; // 야구
int dp[1001][12][10] = {0}; // 축구 선수, 야구 선수

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
        cin >> arr[i] >> arr2[i];

    calc();
}
void calc(){
   
    // 농구선수 고르기
    for(int i = 0; i < n; i++) 
        for(int j = 0; j <= 11; j++) 
               for(int k = 0; k <= 9; k++) {
                    dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);

                    if(j != 11) dp[i+1][j+1][k] = max(dp[i + 1][j + 1][k], dp[i][j][k] + arr[i + 1]);
                    if(k != 9) dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1], dp[i][j][k] + arr2[i + 1]);
                }
    
    cout << dp[n][11][9];
}