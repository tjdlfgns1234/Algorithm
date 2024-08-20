#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    cin >> n;

    unordered_map<string,int> mp;

    int ans = 0;
    string s;

    while(n--){
        cin >> s, mp[s]++;
        ans = max(ans,mp[s]);
    }

    cout << ans;

    return 0;
}