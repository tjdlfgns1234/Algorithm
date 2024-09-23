#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;

int n;
vector<pair<int,int>> p;

void solve();

int main() {
    // 여기에 코드를 작성해주세요.
    
    solve();
    
    return 0;
}
void solve(){
    cin >> n;

    int a,b;
    for(int i = 0; i < n;i++){
        cin >> a >> b;

        p.push_back({a,+1});
        p.push_back({b,-1});
    }

    sort(all(p));

    int curr = 0, ans = 0; // 현재 선분의 값
    for(int i =0; i < 2*n;i++){
        int x,v;
        tie(x,v) = p[i];

        curr += v;

        ans = max(ans,curr);
    }

    cout << ans;
}