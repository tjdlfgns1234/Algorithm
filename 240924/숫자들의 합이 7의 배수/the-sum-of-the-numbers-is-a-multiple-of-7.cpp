#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
void solve();

int main() {
    
    solve();

    return 0;
}
void solve(){
    cin >> n;

    vector<long long> arr(n);

    for(auto&i : arr) cin >>i;

    // 연속하게 고른 숫자들의 합이 7의 배수 (x%7==0)
    // 숫자는 서로 다름

    long long ans = 0;
    long long sum = 0;
    for(ll i = 0; i < n;i++){
        sum=0;
        for(ll j = i; j < n;j++){
            sum += arr[j];
            if(sum%7==0)
                ans = max(ans,j-i+1);
        }
    }

    cout << ans;
}