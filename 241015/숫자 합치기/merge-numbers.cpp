#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
void solve();

int main() {
    
    solve();

    return 0;
}
void solve(){
    cin >> n;

    ll tmp;
    priority_queue<ll> q;
    for(int i = 0; i < n; i++) cin >> tmp, q.push(-tmp);

    ll ans = 0;
    while(q.size()>1){
        ll x = -q.top(); q.pop();
        ll y = -q.top(); q.pop();
        ans += x + y;
        q.push(-(x+y));
    }

    cout << ans;
}