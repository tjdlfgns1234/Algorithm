#include <bits/stdc++.h>
using namespace std;

void solve();

int pre[100002] = {0};
int pre2[100002] = {0};

int main() {
 
    solve();

    return 0;
}
void solve(){
    string s;
    cin >> s;

    int idx = s.size()-2;
    for(int i = s.size()-1; i > 0 && idx >= 0; i--){
        if(s[idx] == ')'&& s[idx+1] == ')')
            pre[i] = pre[i+1] + 1;
        else
            pre[i]= pre[i+1];
        idx--;
    }
    
    long long ans = 0;
    for(int i = 1; i < s.size();i++)
        if(s[i-1] == s[i] && s[i] == '(')
            ans += pre[i];
    
    // for(int i = 1; i < s.size();i++)
    //     cout << pre[i] << ' ' ;

    cout << ans << '\n';
}