#include <bits/stdc++.h>
using namespace std;

void solve();
void bfs();

int n,m;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0, 1,-1};

int arr[100][100] = {0};
int chk[100][100] = {0};
int ans[100][100] = {0};

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
            cin >> arr[i][j];
        

    bfs();
}
void bfs(){

    queue <pair<int,int>> q;
    q.push({0,0}), chk[0][0] = 1;
    int curr = 0;

    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        for(int i = 0; i< 4;i++){
            int nx = x + dx[i], ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0|| ny >= m)
                 continue;

            if(chk[nx][ny] == 0 && arr[nx][ny] == 1)
                chk[nx][ny] = 1,ans[nx][ny] = ans[x][y] + 1, q.push({nx,ny}); 
        }
        if(chk[n-1][m-1] == 1){
            cout << ans[n-1][m-1] << '\n';
            return;
        }
    }

    cout << -1;
}