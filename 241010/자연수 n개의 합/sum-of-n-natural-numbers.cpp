#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll s;
void solve();
int main() {

    solve();

    return 0;
}
void solve(){
    cin >> s;

    ll l= 1, r = 1e9+1e9;

    ll mid, ans = 0;
    while(l<=r){
        mid = l + (r-l)/2ll;

        if((mid*(mid+1ll))/2ll <= s)
            ans = max(ans,mid),l = mid + 1ll;
        else
            r = mid - 1ll;
    }
    cout << ans;
}