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

bool operator<(const edge& a,const edge& b){
    return a.cost < b.cost;
}

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
        // 단방향 그래프
        v[e].push_back({s, c}); 
    }

    dijkstra();

    cout << *max_element(cost, cost+n);
}
void dijkstra(){
    priority_queue <edge> pq;
    
    for(int i = 1; i <= n;i++) cost[i] = INF;
    
    pq.push({k,0});
    cost[k] = 0;
    while(!pq.empty()){
        int s;
        s = pq.top().e;

        pq.pop();
        
        for(auto i : v[s])
            if(cost[s] + i.cost < cost[i.e])
                cost[i.e] = cost[s] + i.cost, pq.push({i.e,cost[i.e]}); 
    }
}