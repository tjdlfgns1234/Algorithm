#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
int arr[50001] = {0};

void solve();

int main() {
    
    solve();

    return 0;
}
void solve(){
    cin >> n;

    for(int i = 0; i < n;i++) cin >> arr[i];

    // 연속하게 고른 숫자들의 합이 7의 배수 (x%7==0)
    // 숫자는 서로 다름

    int ans = 0;
    int sum = 0;
    for(int i = 0; i < n;i++){
        sum=0;
        for(int j = i; j < n;j++){
            sum =(sum + arr[j]) %7;
            if(sum == 0)
                ans = max(ans,j-i+1);
        }
    }

    cout << ans;
}