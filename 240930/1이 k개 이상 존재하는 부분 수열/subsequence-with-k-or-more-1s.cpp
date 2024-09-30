#include <bits/stdc++.h>
using namespace std;

void solve();

int main() {
   
    solve();

    return 0;
}
void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for(auto& i : arr) cin >> i;

    int ans = 987654321, l = 0, cnt = 0;

    for(int i = 0; i < n;i++ ){
        if(arr[i] == 1){
            if(cnt == 0)
                l = i;
            cnt++;

            if(cnt > k){
                l++, cnt--;
                while(arr[l] != 1)
                    l++;
            }

            if(cnt == k)
                ans = min(ans,i - l + 1);
        }
    }
    if(ans == 987654321)
        cout << -1;
    else
        cout << ans;
}