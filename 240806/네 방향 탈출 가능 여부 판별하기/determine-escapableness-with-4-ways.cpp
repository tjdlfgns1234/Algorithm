#include <bits/stdc++.h>
using namespace std;

void solve();
void bfs();

int vit[100][100] = {0};
int arr[100][100] = {0};
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0, -1, 1}; 
int n, m;



int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL), std::cout.tie(NULL);

    solve();

    return 0;
}
void solve() {
    cin >> n >> m;

    int a,b;
    for(int i = 0; i < n;i++)
        for(int j = 0; j < m;j++)
            cin >> arr[i][j];
    
    bfs();
}
void bfs(){
    queue<pair<int,int>> q;
    q.push({0,0});
    vit[0][0] = 1;
    int ans = 0;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second; 
        q.pop();
   

        if(x == n-1 && y == m-1){
            ans = 1;
            break;
        }
        for(int i = 0; i< 4;i++){
            int nx = x + dx[i], ny = y + dy[i];

            if(nx < 0 || nx>= n || ny < 0 || ny >= n || arr[nx][ny] == 0 || vit[nx][ny] == 1)
                continue;

            q.push({nx,ny});
            vit[nx][ny] = 1;
        }
    }
    cout << ans;
}