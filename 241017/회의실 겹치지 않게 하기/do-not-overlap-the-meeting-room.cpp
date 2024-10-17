#include <bits/stdc++.h>
using namespace std;

int n;
struct p{
    int s,e;
};

p arr[100001];

bool cmp(p& a, p& b){
    if(a.e > b.e)
        return ((a.e-a.s) < (b.e - b.s));
    return a.e < b.e;
}

void solve();

int main() {

    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    solve();

    return 0;
}
void solve(){
    cin >> n;

    for(int i = 0; i < n;i++) cin >> arr[i].s >> arr[i].e;

    sort(arr, arr+n,cmp);

    int curr = arr[0].e, ans = 0;
    for(int i = 1; i < n;i++){
        // cout << arr[i].s << ' ' << arr[i].e << " " << curr << '\n';

        if(curr <= arr[i].s)
            curr = arr[i].e;
        else
            ans++;
    }

    cout << ans;
}