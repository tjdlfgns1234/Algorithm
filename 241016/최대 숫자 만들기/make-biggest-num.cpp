#include <bits/stdc++.h>
using namespace std;

int n;
string s[50001];

bool cmp(string a, string b) {
    return a+b > b+a;
}
void solve();

int main() {
    
    solve();

    return 0;
}
void solve(){
    cin >> n;
    // 한 숫자가 다른 숫자의 접두사가 되는 경우 조심
    for(int i = 0; i < n;i++) cin >> s[i];

    sort(s,s+n, cmp);

    for(int i = 0; i < n;i++) cout << s[i];
}