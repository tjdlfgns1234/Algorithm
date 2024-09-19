#include <bits/stdc++.h>
using namespace std;

int n, q;
int arr[100001];
int l[100001] = {0};
int r[100001] = {0};

void solve();

int main() {
    cin >> n >> q;

    int a,b;
    for(int i = 0; i < n; i++)
         cin >> arr[i];

    l[0] = arr[0];
    for(int i = 1; i < n; i++)
        l[i] = max(l[i-1], arr[i]);

    r[n-1] = arr[n-1];
    for(int i = n-2; i >= 0; i--)
        r[i] = max(r[i+1],arr[i]);

    solve();

    return 0;
}
void solve(){
    int a,b;
    for(int i = 0; i < q;i++){
        cin >> a >> b;
        --a,--b;

        cout << max(l[a-1], r[b+1]) << '\n'; 
    }
}