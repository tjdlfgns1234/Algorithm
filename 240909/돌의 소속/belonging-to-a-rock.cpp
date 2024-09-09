#include <bits/stdc++.h>
using namespace std;

void solve();

int n,k;
short arr[100001] = {0};
int dp[3][100001] = {0};


int main() {

    ios::sync_with_stdio(NULL);
    cout.tie(NULL), cin.tie(NULL);

    solve();

    return 0;
}
void solve(){
    cin >> n >> k;

    for(int i = 1; i <= n;i++)
        cin >> arr[i];
    
    for(int i = 1; i <= n;i++){
        int stone = arr[i]-1;

        dp[0][i] = dp[0][i-1];
        dp[1][i] = dp[1][i-1];
        dp[2][i] = dp[2][i-1];
        dp[stone][i]++; // 돌 증가
    }

    int a,b;
    for(int i = 0; i < k;i++){
        cin >> a >> b;

        cout << dp[0][b] - dp[0][a-1] << " ";
        cout << dp[1][b] - dp[1][a-1] << " ";
        cout << dp[2][b] - dp[2][a-1] << "\n";
    }
}