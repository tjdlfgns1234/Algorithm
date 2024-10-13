#include <bits/stdc++.h>
using namespace std;

int n,k;
int arr[11] = {0};
void solve();

int main() {
 
    ios::sync_with_stdio(NULL);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
void solve(){
    // 동전의 가치는 항상 바로 전 동전의 가치의 배수
    cin >> n >> k;
    int ans = 0;

    for(int i = 0; i < n;i++) cin>> arr[i];

    for(int i = n-1; i >= 0; i--)
        ans += k/arr[i], k = k%arr[i];
    
    cout << ans;
}