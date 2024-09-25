#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
ll arr[50001] = {0};
ll pre[50001] = {0};

vector<vector<ll>> chk(7);

void solve();

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL), std::cout.tie(NULL);

    solve();

    return 0;
}
void solve(){
    cin >> n;

    for(int i = 1; i <= n;++i) cin >> arr[i];

    // 연속하게 고른 숫자들의 합
    // 7의 배수 (x%7==0)
    // 숫자는 서로 다름

    int ans = 0,sum = 0;

    for(int i = 1; i <= n;++i) pre[i] =(pre[i-1] + arr[i])%7; // prefix 저장

    for(int i = 0; i <= n;++i)
        chk[pre[i]].push_back(i);

    // 나머지 값이 같은 가장 멀리 떨어진 두 인덱스 차이를 계산
    for (int i = 0; i < 7; i++) {
        if (chk[i].size() >= 2) {
            // 가장 작은 인덱스와 가장 큰 인덱스의 차이 계산
            int b = *max_element(chk[i].begin(),chk[i].end());
            int s = *min_element(chk[i].begin(),chk[i].end());
            ans = max(ans, b-s);
        }
    }

    cout << ans;
}