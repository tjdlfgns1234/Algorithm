#include <bits/stdc++.h>
using namespace std;

void solve();
void dfs(int cnt,int sum);

int n;
int vit[10] = {0};
int arr[10][10] = {0};
int ans = 0;

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL), std::cout.tie(NULL);

    solve();

    return 0;
}
void solve() {
    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];
    
    dfs(0, 987654321);
    cout << ans;
}
void dfs(int cnt,int sum){
    if(cnt == n){
        ans = max(ans,sum);
        return;
    }

    for(int i = 0; i< n;i++){
        if(!vit[i]){
            vit[i] = true;
            dfs(cnt+1,  min(arr[cnt][i], sum));
            vit[i] = false;
        }
    }

}