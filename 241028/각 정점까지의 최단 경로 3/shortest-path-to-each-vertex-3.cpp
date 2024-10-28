#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

struct edge{
    int e,cost;
};

int n, m;

vector<vector<edge>> v(101);
int cost[101];

void solve();
void dijkstra();

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    solve();

    return 0;
}
void solve(){
    cin >> n >> m;

    int s,e,c;
    for(int i = 0; i < m;i++){
        cin >> s >> e >> c;
        v[s].push_back({e, c}); // 단방향 그래프
    }

    dijkstra();

    for(int i = 2; i <= n;i++)
        if(cost[i] != 987654321)
            cout << cost[i] << '\n';
        else
            cout << -1 << '\n';
}
void dijkstra(){
    queue <int> q;
    
    for(int i = 1; i <= n;i++) cost[i] = INF;
    
    q.push(1);
    cost[1] = 0;
    while(!q.empty()){
        int s = q.front();
        q.pop();
        
        for(auto i : v[s])
            if(cost[s] + i.cost < cost[i.e])
                cost[i.e] = cost[s] + i.cost, q.push(i.e); 
    }
}