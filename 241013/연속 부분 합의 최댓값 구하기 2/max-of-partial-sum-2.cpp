#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100001] = {0};
void solve();

int main() {
    
    solve();

    return 0;
}
void solve(){
    cin >> n;

    for(int i = 0; i < n;i++) cin >> arr[i];

    int j =0, sum = 0, ans = INT_MIN;
    for(int i = 0; i < n;i++){
        if(sum + arr[i] >= 0)
            sum += arr[i];
        else
            sum = arr[i];
        ans = max(ans, sum);
    }
    
    cout << ans;
}