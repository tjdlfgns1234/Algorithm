#include <bits/stdc++.h>
using namespace std;

void solve();

int n;

int main() {
    // 여기에 코드를 작성해주세요.

    solve();

    return 0;
}
void solve(){
    cin >> n;


    vector<pair<int,int>> arr;

    int s,e;
    for(int i = 0; i < n;i++){
        cin >> s >> e;

        arr.push_back({s,+1});
        arr.push_back({e+1,-1});
    }

    sort(arr.begin(), arr.end());

    int ans = 0, curr = 0;

    for(int i = 0; i < 2*n;i++)
        curr += arr[i].second, ans = max(ans, curr);
    
    cout << ans;
}