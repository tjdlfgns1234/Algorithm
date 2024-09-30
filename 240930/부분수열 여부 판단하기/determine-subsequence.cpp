#include <bits/stdc++.h>
using namespace std;

int n, m;
void solve();

int main() {

    solve();


    return 0;
}
void solve(){
    cin >> n >> m;

    vector<int> arr(n);
    for(auto&i : arr) cin >> i;

    vector<int> arr2(m);
    for(auto&i : arr2) cin >> i;

    int p = 0;

    for(int i = 0; i < n;i++)
        if(arr[i] == arr2[p]) p++;
        else if(p == m) break;
    

    if(p == m)
        cout << "Yes";
    else
        cout << "No";
}