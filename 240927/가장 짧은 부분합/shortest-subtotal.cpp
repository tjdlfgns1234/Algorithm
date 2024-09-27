#include <bits/stdc++.h>
using namespace std;

int n,s;
int arr[100001] = {0};
void solve();

int main() {
   
    solve();

    return 0;
}
void solve(){
    cin >> n >> s;

    for(int i = 0; i < n;i++)
        cin >> arr[i];

    int sum = 0;
    int ans = n+1, j = -1;
    for(int i = 0; i < n; i++) {

        while(j+1 < n && sum < s)
            j++, sum+= arr[j];
        
        if(sum >=s)
            ans = min(ans, j - i + 1);

        sum -= arr[i];
    }
    if(ans != n+1)
        cout << ans;
    else
        cout << -1;
}