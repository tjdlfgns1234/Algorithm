#include <bits/stdc++.h>
using namespace std;

void solve();
void calc();

int n, m;
int arr[100];
int dp[10001] = {0};

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL), std::cout.tie(NULL);

    solve();

    return 0;
}
void solve() {
    cin >> n >> m;

    for(int i = 0; i < n;i++)
        cin >> arr[i];
    
    calc();
}
void calc(){
    dp[0] = 0;

    for(int i = 1; i <= m;i++)
        dp[i] = INT_MAX;
    
    for(int i = 0; i < n;i++)
        for(int j = m; j>=0;j--)
            if(dp[j-arr[i]] == INT_MAX)
                continue;
            else if(j-arr[i] >= 0)
                dp[j] = min(dp[j-arr[i]]+1, dp[j]); 

    if(dp[m] == INT_MAX)
        cout << -1;
    else        
        cout << dp[m];
}