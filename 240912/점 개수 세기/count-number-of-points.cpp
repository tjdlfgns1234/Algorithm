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
        if(q == mp.begin()&& w != mp.end())
            cout << w->second -1 << '\n';
        else if(q == mp.begin()&& w == mp.end())
            cout << n << '\n';
        else if(q != mp.begin()&& w != mp.end())
            cout << w->second - q->second << '\n';
        else
            if(q->first == a)
                cout << n - q->second +1 << '\n';
            else
                cout << n - q->second << '\n';

    }
    return 0;
}