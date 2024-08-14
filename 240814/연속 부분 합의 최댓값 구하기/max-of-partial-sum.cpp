#include <bits/stdc++.h>
using namespace std;

void solve();
void calc();

int n;
int arr[100001] = {0};
int dp[100001] = {0};

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
    for(int i = 1; i <= n;i++)
        dp[i] = INT_MIN;

    int ans = INT_MIN;
        
    dp[0] = 0;
    dp[1] = arr[1];

    for(int i = 2;i<= n;i++)
        dp[i] = max(dp[i-1]+ arr[i], arr[i] );

    for(int i = 1;i<= n;i++)
        ans = max(ans, dp[i]);

    cout << ans;
}