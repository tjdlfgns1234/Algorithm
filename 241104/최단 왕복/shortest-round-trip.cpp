#include <bits/stdc++.h>
#define SIZE 101
using namespace std;

void solve();

int n,m;
int dist[SIZE][SIZE];

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

    for(int i = 0; i < m; i++) {
        int x, y, z;
        tie(x, y, z) = edges[i];
        dist[x][y] = min(dist[x][y],z);
    }
    
    for(int k = 1; k <= n; k++) 
        for(int i = 1; i <= n; i++) 
            for(int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);


    int ans = 1e9;
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++) 
            if(i!=j)
                ans = min(ans, dist[i][j] + dist[j][i]);

    cout << ans;
}