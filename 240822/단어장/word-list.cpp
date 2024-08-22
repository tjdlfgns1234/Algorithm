#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    cin >> n;

    map<string, int> mp;

    string s;
    while(n--)
        cin >> s, mp[s]++;


    for(auto i : mp)
        cout << i.first << " " << i.second << '\n';


    return 0;
}