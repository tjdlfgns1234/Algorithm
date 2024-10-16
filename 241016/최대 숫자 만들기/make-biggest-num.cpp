#include <bits/stdc++.h>
using namespace std;

int n;
string s[50001];

bool cmp(string a, string b) {
    if(a+b > b+a)
        return true;
    else
        return false;
}
void solve();

int main() {
    
    solve();

    return 0;
}
void solve(){
    cin >> n;

    for(int i = 0; i < n;i++) cin >> s[i];

    sort(s,s+n, cmp);

    for(int i = 0; i < n;i++) cout << s[i];
}