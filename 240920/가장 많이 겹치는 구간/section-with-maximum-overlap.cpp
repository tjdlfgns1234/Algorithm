#include <bits/stdc++.h>
using namespace std;

int n;
int arr[200001] = {0};
int dp[200001] = {0};
void solve();

int main() {

    solve();

    return 0;
}
void solve(){
    cin >> n;

    int a,b;
    for(int i = 0; i < n;i++){
        cin >> a >> b;

        arr[a]++, arr[b]--;
    }

    for(int i = 1; i < 200001;i++){
        dp[i] = dp[i-1] + arr[i];
    }

    cout << *max_element(dp,dp + 200001);

}