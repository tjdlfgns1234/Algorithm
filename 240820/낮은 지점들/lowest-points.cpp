#include <bits/stdc++.h>
#define pad 1000000000

using namespace std;

int n;

int main() {
    cin >> n;


    unordered_map<int,int> mp;

    long long ans = 0ll;

    int a, b;
    for(int i = 0; i < n;i++)
        std::cin >> a >> b,mp[a] = min(mp[a], b-pad);

    

    for(auto& i : mp)ans += (i.second + pad);

    
    std::cout << ans;

    return 0;
}