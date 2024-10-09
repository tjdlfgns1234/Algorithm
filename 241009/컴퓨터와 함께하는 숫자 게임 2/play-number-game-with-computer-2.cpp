#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll m;
ll a,b;
void solve();
int bi_search(ll target);

int main() {
    
    solve();

    return 0;
}
void solve(){
    cin >> m;
    cin >> a >> b;
    
    ll minv = 1e18 +1, maxv=0;

    for(ll i = a; i <= b;i++){
        ll v = bi_search(i);

        minv = min(v,minv);
        maxv = max(v,maxv);
    }
    cout << minv << ' ' << maxv;
}
int bi_search(ll target){
    int ret = 0;
    ll l = 1, r =m;
    while(l<=r){
        ret++;
        ll mid = l + (r-l)/2;

        if(mid==target)
            break;
        else if(mid < target)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return ret;
}