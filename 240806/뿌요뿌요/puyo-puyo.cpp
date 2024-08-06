#include <bits/stdc++.h>
using namespace std;

void solve();
void dfs(int x, int y);

int n, ans = 0, ans2 = 0;
int arr[100][100];
int vit[100][100] = {0};

int dx[4] = { 1, -1, 0, 0};
int dy[4] = { 0, 0, 1, -1};

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL), std::cout.tie(NULL);

    solve();

    return 0;
}
void solve() {
   cin >> n;

    for(int i = 0; i < n;i++)
        for(int j = 0; j < n;j++)
            cin >> arr[i][j];

    for(int i = 0; i < n;i++)
        for(int j = 0; j < n;j++)
            if(!vit[i][j])
                dfs(i,j);
    cout << ans2 << ' ' << ans;
}
void dfs(int x, int y){
    int color = arr[x][y], cnt = 0;

    queue <pair<int,int>> q;
    q.push({x,y});

    while(!q.empty()){
        int ax = q.front().first, ay = q.front().second;
        q.pop();

        for(int i = 0; i < 4;i++){
            int nx = ax + dx[i], ny = ay + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n || vit[nx][ny] == 1 || arr[nx][ny] != color)
                continue;

            vit[nx][ny] = 1;
            if(color == arr[nx][ny])
                cnt++;
            q.push({nx,ny});
        }
        
    }
    if(cnt >= 4)
        ans = max(cnt, ans), ans2++;
    else
        ans = max(cnt, ans);
}