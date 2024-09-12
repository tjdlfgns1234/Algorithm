#include <bits/stdc++.h>
using namespace std;

int n,q;

map <int,int> mp;
int dp[100001] = {0};

int main() {
    cin >> n >> q;

    int tmp, idx = 0;
    for(int i = 0; i < n;i++) cin >> tmp, mp[tmp]++;

    idx = 1;
    for(auto &i : mp) i.second = idx++;

    int a,b;
    for(int i =0; i < q;i++){
        cin >> a >> b;

        auto q = mp.lower_bound(a),w = mp.upper_bound(b);
        if(q == mp.end())
            cout << 0 << '\n';
        else if(w == mp.end())
            cout << n - q->second + 1 << '\n';
        else
            cout << w->second - q->second << '\n';
        

    }
    return 0;
}