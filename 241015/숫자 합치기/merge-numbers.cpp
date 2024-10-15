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

    int tmp;
    priority_queue<int> q;
    for(int i = 0; i < n; i++) cin >> tmp, q.push(-tmp);

    int ans = 0;
    while(q.size()>1){
        int x = -q.top(); q.pop();
        int y = -q.top(); q.pop();
        ans += x + y;
        q.push(-(x+y));
    }

    cout << ans;
}