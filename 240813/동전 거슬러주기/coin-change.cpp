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
    for(int i = 0; i < n;i++)
        for(int j = arr[i]; j<=m;j+= arr[i])
            dp[j]++;

    for(int i = 0; i < n;i++)
        for(int j = 1; j<=m;j++)
            if(j-arr[i] >= 0)
                if(dp[j]==0)
                    dp[j] = dp[j-arr[i]]+1; 

    cout << dp[m];
}