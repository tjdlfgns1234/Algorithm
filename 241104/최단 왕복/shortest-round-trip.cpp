#include <bits/stdc++.h>
#define SIZE 101
using namespace std;

void solve();

int n,m;
int dist[SIZE][SIZE];
int dist2[SIZE][SIZE];

int main() {
    // 여기에 코드를 작성해주세요.
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    solve();

    return 0;
}
void solve(){
    cin >> n >> m;
    vector<tuple<int, int, int>> edges;

    int a,b,c;
    for(int i = 0; i < m;i++){
        cin >> a >> b >> c;
        edges.push_back({a,b,c});
    }

     for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
            dist[i][j] = (int)1e9;

        dist[i][i] = 0;
    }

    // 그래프를 인접행렬로 표현
    for(int i = 0; i < m; i++) {
        int x, y, z;
        tie(x, y, z) = edges[i];
        dist[x][y] = min(dist[x][y],z);
    }
    
    for(int k = 1; k <= n; k++) // 확실하게 거쳐갈 정점을 1번부터 N번까지 순서대로 정의합니다.
        for(int i = 1; i <= n; i++) // 고정된 k에 대해 모든 쌍 (i, j)를 살펴봅니다.
            for(int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);


    for(int i = 0; i < m; i++) {
        int x, y, z;
        tie(x, y, z) = edges[i];
        dist2[y][x] = min(dist2[y][x],z);
    }
    
    for(int k = 1; k <= n; k++) // 확실하게 거쳐갈 정점을 1번부터 N번까지 순서대로 정의합니다.
        for(int i = 1; i <= n; i++) // 고정된 k에 대해 모든 쌍 (i, j)를 살펴봅니다.
            for(int j = 1; j <= n; j++)
                dist2[i][j] = min(dist2[i][j], dist2[i][k] + dist2[k][j]);

    int ans = 1e9;
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++) 
            ans = min(ans, dist[i][j] + dist2[i][j]);

    cout << ans;
}