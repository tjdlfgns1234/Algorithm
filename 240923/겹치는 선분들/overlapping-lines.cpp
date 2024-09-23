#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;

int n,k;
vector<pair<int,int>> p;

void solve();
int sign(string s);

int main() {
    solve();

    return 0;
}
void solve(){
    cin >> n >> k;

    int a, curr=0;
    string s;
    for(int i = 0; i < n;i++){
        cin >> a >> s;

        // 시작점은 0
        // K개 이상 겹치는 곳의 길이 합
        p.push_back({curr, sign(s)});
        p.push_back({curr + a*sign(s), -sign(s)});
        curr = curr + a*sign(s);
    }

    sort(all(p));

    int sum = 0, ans = 0, pre = INT_MAX;
    for(int i = 0; i < 2*n;i++){
        int x,v;
        tie(x,v) = p[i];

        if(sum >= k && pre != INT_MAX)
            ans += abs(x - pre);
        
        // cout << "## " << x << " " << pre << '\n';

        sum+= v;
        pre = x;
    }

    cout << ans;
}
int sign(string s){
    if(s[0] == 'R')
        return 1;
    else
        return -1;
}