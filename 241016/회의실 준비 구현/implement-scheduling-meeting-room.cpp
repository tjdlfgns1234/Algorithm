#include <bits/stdc++.h>
using namespace std;

int n;
struct p{
    int s, e;
};

p arr[100001];

bool compare(p& a, p&b){
    return a.e < b.e;
}

void solve();

int main() {
  
    solve();

    return 0;
}
void solve(){
    cin >> n;

    for(int i = 0;i < n;i++)
        cin>> arr[i].s >> arr[i].e;

    sort(arr, arr+n, compare); 

    int curr = arr[0].e, ans = 1;
    for(int i = 1; i < n;i++)
        if(arr[i].s >= curr)
            curr = arr[i].e, ans++;

    cout << ans;
}