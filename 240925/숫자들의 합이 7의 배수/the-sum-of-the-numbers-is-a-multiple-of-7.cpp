#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
ll arr[50001] = {0};
ll dp[50001] = {0};

void solve();

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL), std::cout.tie(NULL);

    solve();

    return 0;
}
void solve(){
    cin >> n;

    for(int i = 0; i < n;++i) cin >> arr[i];

    // 연속하게 고른 숫자들의 합
    // 7의 배수 (x%7==0)
    // 숫자는 서로 다름

    int ans = 0,sum = 0;

    dp[0] = arr[0];
    for(int i = 1; i < n;++i) dp[i] += arr[i]; // prefix 저장

    for(int i = 0; i < n;++i){
        sum=0;
        for(int j = i; j < n;++j){
            sum =(sum + arr[j]) %7;
            if(sum == 0)
                ans = max(ans,j-i+1);
            if(n-j+1 < ans)
                break;
        }
    }

    cout << ans;
}