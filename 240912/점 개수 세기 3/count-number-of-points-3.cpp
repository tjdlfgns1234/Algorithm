#include <bits/stdc++.h>
using namespace std;

int n,q;

unordered_map <int,int> mp;


int main() {
    cin >> n >> q;

    int tmp, idx = 0;
    for(int i = 0; i < n;i++) cin >> tmp, mp[tmp] = idx++;

    idx = 1;
    for(auto i : mp)i.second = idx++;

    int a,b;
    for(int i =0; i < q;i++){
        cin >> a >> b;
        cout << mp[b] - mp[a] +1 << '\n';
    }



    return 0;
}