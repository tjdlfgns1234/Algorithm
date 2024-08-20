#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;

    cin >> n >> m;

    unordered_map <int,int> mp;

    int a;
    while(n--)
        cin >> a, mp[a]++;
    
    while(m--)
        cin >> a, cout << mp[a] << ' ';


    return 0;
}