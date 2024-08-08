#include <bits/stdc++.h>
using namespace std;

void solve();

int n, k, u, d, ans = 0;
int arr[8][8] = {0};
int chk[8][8] = {0};
int chk2[8][8] = {0};


int dx[4] = {1,-1, 0,0};
int dy[4] = {0,0, 1,-1};

vector<pair<int,int>> p; 

void dfs(int cnt);
int bfs(int sx, int sy);

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL), std::cout.tie(NULL);

    solve();

    return 0;
}
void solve() {
    cin >> n >> k >> u >> d;

    for(int i = 0; i < n;i++)
        for(int j = 0; j < n;j++)
            cin >> arr[i][j];

  
    // 칸 마다 주어지는 높이 정보
    // 높이는 u이상 D이하인 경우에만 가능

    dfs(0);

    cout << ans;
}
void dfs(int cnt){
    if(cnt == k){
        int tmp = 0;
        memset(chk,0,sizeof(chk));
        for(int i = 0; i < p.size();i++)
            tmp += bfs(p[i].first,p[i].second);
        ans = max(tmp+k,ans);
        return;
    }

    for(int i = 0; i < n;i++)
        for(int j = 0; j < n;j++)
            if(!chk2[i][j]){
                chk2[i][j] = 1;
                p.push_back({i,j});
                dfs(cnt+1);
                chk2[i][j] = 0;
                p.pop_back();
            }

}
int bfs(int sx, int sy){
    queue <pair<int,int>> q;
    q.push({sx,sy});
    chk[sx][sy] = 1;
    int ret = 0;

    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();

        for(int  i= 0; i< 4;i++){
            int nx = x + dx[i], ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;

            int diff = abs(arr[x][y] - arr[nx][ny]); 
            if(chk[nx][ny] == 0 && (diff >= u && diff <= d))
                chk[nx][ny] = 1, q.push({nx,ny}),ret++;
        }
    }
    return ret;
}