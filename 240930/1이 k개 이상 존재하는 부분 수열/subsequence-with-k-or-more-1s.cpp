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

    int ans = 987654321;

    priority_queue <int> q;
    for(int i = 0; i < n;i++ ){
        if(arr[i] == 1){
            q.push(-i);

            if(q.size() > k)
                q.pop();
            if(q.size() == k){
                int t = -q.top();
                ans = min(ans,i-t+1);
            }
     
        }
    }
    cout << ans;
}