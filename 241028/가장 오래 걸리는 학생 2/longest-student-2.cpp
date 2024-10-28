#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

struct edge{
    int e,cost;
};

int n, m, k;

vector<vector<edge>> v(100001);
int cost[100001];


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

    k = n;

    int s,e,c;
    for(int i = 0; i < m;i++){
        cin >> s >> e >> c;
        // 무방향 그래프
        v[e].push_back({s, c}); 
    }

    dijkstra();

    cout << *max_element(cost, cost+n);
}
void dijkstra(){
    queue <int> q;
    
    for(int i = 1; i <= n;i++) cost[i] = INF;
    
    q.push(k);
    cost[k] = 0;
    while(!q.empty()){
        int s = q.front();
        q.pop();
        
        for(auto i : v[s])
            if(cost[s] + i.cost < cost[i.e])
                cost[i.e] = cost[s] + i.cost, q.push(i.e); 
    }
}