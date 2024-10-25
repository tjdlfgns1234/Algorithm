#include <bits/stdc++.h>
using namespace std;

void solve();

int main() {
    
    solve();
    
    return 0;
}
void solve(){
    // 길이가 4인 문자열 0100
    int n;
    cin >> n;

    string a,b;
    cin >> a >> b;

    int ans = 0, f = 0, cnt = 0;
    for(int i = 0; i < n;i++){
        if(a[i] != b[i] && cnt < 4){
            if(cnt == 0)
                ans++;
            cnt++;
        }
        else if(cnt == 4)
            ans++, cnt = 1;
        else{
            cnt = 0;
        }
    }
    cout << ans;
}