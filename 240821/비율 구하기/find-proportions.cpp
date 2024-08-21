#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, int> mp;

    string s;
    for(int i = 0; i < n;i++)
        cin >> s, mp[s]++;
    

    cout << fixed;
    cout.precision(4);

    for(auto i : mp)
        cout << i.first << ' ' << (double)(i.second/(double)n)*100 << '\n';

    return 0;
}