#include <bits/stdc++.h>
using namespace std;

int n,m;
int l = 1, r = 1e8, ans = 1e8;
int p[100001] = {0};
int lane[100001] = {0};
void solve();
bool chk(int mid);

int main() {

    solve();

    return 0;
}
void solve(){
    cin >> n >> m;

    for(int i = 0; i < n;i++) cin >> p[i];

    while(l<=r){
        int mid = l + (r-l)/2;

        if(chk(mid))
            ans = min(ans, mid), r = mid - 1;
        else
            l = mid + 1;
    }
    cout << ans;
}
bool chk(int mid){
    memset(lane,0,sizeof(lane));

    int idx = 0;

    // 모든 사람은 하나의 레인
    // 도착한 순서가 늦으면 먼저 도착한 사람의 레인번호보다 앞 설수 없음.
    for(int i = 0;i < n;i++){
        if(lane[idx] + p[i] <= mid)
            lane[idx] += p[i];
        else if(idx == m-1)
            lane[idx] += p[i];
        else
            idx++, lane[idx] += p[i];
    }

    // cout << mid << ' ';
    // for(int i = 0; i < m;i++)
    //     cout << lane[i] << ' ';
    // cout << '\n';

    if(*max_element(lane, lane+m) <= mid)
        return true;
    else
        return false;
}