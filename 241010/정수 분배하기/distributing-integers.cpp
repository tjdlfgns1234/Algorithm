#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[100001] = {0};
void solve();
bool chk(int mid);

int main() {
    
    solve();

    return 0;
}
void solve(){
    cin >> n >> m;

    for(int i =0; i < n;i++) cin >> arr[i];

    int l = 1, r = 1e5, ans = 0;
    while(l<=r){
        int mid = l + (r-l)/2;

        if(chk(mid)) // 최댓값 찾는 문제
            ans = max(ans,mid), l = mid + 1;
        else
            r = mid - 1;
    }
    cout << ans;

}
bool chk(int mid){
    int cnt = 0;

    for(int i =0; i < n;i++)
        cnt += arr[i]/mid;
    
    if(cnt >= m)
        return true;
    else
        return false;
}