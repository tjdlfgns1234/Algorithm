#include <bits/stdc++.h>
using namespace std;

void solve();
void bfs(int x, int y);

int arr[20][20];
int n, m;
int ans = -1;

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL), std::cout.tie(NULL);

    solve();

    return 0;
}
void solve() {
    cin >> n >> m;

    for(int i = 0; i < n;i++)
        for(int j = 0; j < m;j++)
            cin>> arr[i][j];

    for(int i = 0; i < n;i++)
        for(int j = 0; j < m;j++)
            bfs(i,j);

    cout << ans;
}
void bfs(int x, int y){
    int ret = -1;

    for(int k = 0; k < n;k++)
        for(int l = 0; l < m;l++){
            bool f = false;
            if(n-k < 0 || m-l < 0)
                continue;
            
            for(int i = x; i <= x + k;i++)
                for(int j = y; j <= y + l;j++){
                    if(arr[i][j] <= 0){
                        f = true;
                        break;
                    }
                }
            if(!f)
                ret = max(ret, ((k+1)*(l+1)));  
        }

                  
    ans = max(ans,ret);    
}