#include <bits/stdc++.h>
using namespace std;

int n,s;
int arr[100001] = {0};
void solve();

int main() {
   
    solve();

    return 0;
}
void solve(){
    cin >> n >> s;

    for(int i = 0; i < n;i++)
        cin >> arr[i];

    int sum = 0;
    int ans = n, j = 0;
    for(int i = 0; i < n; i++) {

        int j;
        for(j = i + 1; j < n && sum < s;j++){
            sum+= arr[j];
        }
        ans = min(ans, j - i + 1);

        sum -= arr[i];
    }
    cout << ans;
}