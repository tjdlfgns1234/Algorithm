#include <bits/stdc++.h>
using namespace std;


int n;
int arr[100001] = {0};
int cnt[100001] = {0};

void solve();

int main() {
    // 여기에 코드를 작성해주세요.
    solve();

    return 0;
}
void solve(){
    cin >> n;
    
    for(int i = 0; i < n;i++) cin >> arr[i];
    
    int ans = 0;
    int j = -1;
    for(int i = 0; i < n;i++){

        while(j+1 < n && cnt[arr[j+1]] == 0)
            cnt[arr[j+1]]++, j++;
        
        ans = max(ans, j - i + 1);
        cnt[arr[i]]--;
    }

    cout << ans << '\n';
}