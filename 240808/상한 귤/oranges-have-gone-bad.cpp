#include <bits/stdc++.h>
using namespace std;

void solve();

int n, k;

int dx[4] = {1,-1, 0, 0};
int dy[4] = {0,0, 1,-1};
int arr[100][100]= {0};
int chk[100][100]= {0};
int dist[100][100]= {0};

void bfs();
void print();

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL), std::cout.tie(NULL);

    solve();

    return 0;
}
void solve() {
    cin >> n >> k;

    for(int i = 0; i < n;i++)
        for(int j = 0; j< n;j++)
            cin >> arr[i][j];

    bfs();
    print();
}
void bfs(){

    queue<pair<int,int>> q;
    for(int i = 0; i < n;i++)
        for(int j = 0; j< n;j++)
            if(arr[i][j] == 2)
                q.push({i,j}), chk[i][j] =1;
            
    while(!q.empty()){
        int x = q.front().first,y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            
            if(!chk[nx][ny] && arr[nx][ny] == 1)
                chk[nx][ny] =1, dist[nx][ny] = dist[x][y] +1, q.push({nx,ny});
        }
    }
}
void print(){
    for(int i = 0; i < n;i++){
        for(int j = 0; j< n;j++){
            if(arr[i][j] == 0)
                dist[i][j] = -1;
            if(arr[i][j] == 1 && dist[i][j] == 0)
                dist[i][j] = -2;
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
}