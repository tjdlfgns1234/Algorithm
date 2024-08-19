#include <bits/stdc++.h>
using namespace std;

void solve();
void calc();
void init();

int n, m;
int dp[1001][101] = {0};
int arr[1001][101] = {0};	

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL), std::cout.tie(NULL);

    solve();

    return 0;
}
void init(){
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j++)
            dp[i][j] = 0;
}
void solve() {
    cin >> n >> m;

    for(int i = 1; i <= n;i++)
        for(int j = 1; j <= m;j++)
            cin >> arr[i][j];

    calc();
}
void calc(){

    init();
    // 1계단 올라가는 경우는 최대 3번

    for(int i =1; i <= m;i++)
        dp[1][i] = arr[1][i];

    for(int i = 2; i <= n; i++) 
        for(int j = 1; j <=m ; j++) 
            for(int k = 1; k <= m ;k++)
                if(j == k) continue;
                else dp[i][j] = max(dp[i-1][k] + arr[i][j], dp[i][j]);
    
    
    int ans = INT_MIN;
    for (int i = 1; i <= m; i++)
        ans = max(ans, dp[n][i]);


    // for (int i = 1; i <= m; i++)
    //     cout <<  dp[n][i] << ' ';
    
    cout << ans;
}