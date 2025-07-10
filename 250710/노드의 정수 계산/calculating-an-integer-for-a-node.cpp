#include <bits/stdc++.h>
#define MAX 100'001
using namespace std;

int n;
int a[MAX], t[MAX];

vector<vector<int>> arr(MAX);

void solve();
int dfs(int s);


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
void solve(){
    cin >> n;

    int p;
    for (int i = 2; i <= n; ++i) {
        cin >> t[i] >> a[i] >> p;

        // 양방향 처리
        // arr[i].push_back(p);
        arr[p].push_back(i);

        if(!t[i]) a[i] = -a[i];
    }

    dfs(1);

    cout << a[1];
}
int dfs(int s){
    int ret = a[s];

    for(auto& i : arr[s])
        ret += dfs(i);
  
    // cout << s << " " << ret << '\n';

    if(ret < 0)
        return 0;
    else
        return a[s] = ret;
}