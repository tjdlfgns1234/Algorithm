#include <bits/stdc++.h>
using namespace std;

int n,k;
struct p{
    int v,w;
};

p arr[100001];

bool compare(p& a, p&b){
    return ((double)a.v/a.w > (double)b.v/b.w);
}

void solve();

int main() {
    // 여기에 코드를 작성해주세요.
    solve();

    return 0;
}
void solve(){
    cin >> n >> k;

    for(int i = 0; i< n;i++) cin >> arr[i].w >> arr[i].v;

    sort(arr,arr+n,compare);

    double ans = 0, w = 0;
    for(int i = 0; i < n;i++){
        if(arr[i].w <= k)
            ans += arr[i].v, k -=arr[i].w;
        else{
            ans += arr[i].v*(k/(double)arr[i].w);
            break;
        }
    }
        
    cout << fixed;
    cout.precision(3);
    cout << ans;

}