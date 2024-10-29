#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

struct edge{
    int e,cost;
};

int n, m, k;

vector<vector<edge>> v(1001);
int cost[1001];
int path[1001];

void solve();
void dijkstra();

bool operator<(const edge& a,const edge& b){
    return a.cost > b.cost;
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
        // 양방향 그래프
        v[s].push_back({e, c}); 
        v[e].push_back({s, c}); 
    }

    int a, b;
    cin >> a >> b;
    k = a;

    dijkstra();

    int sx = b;
    cout << cost[b] << '\n';

    stack <int> ss;

    while(sx != a){
        ss.push(sx);
        sx = path[sx];
    }

    cout << a << ' ';
    while(!ss.empty())
        cout << ss.top() << ' ', ss.pop();
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
                cost[i.e] = cost[s] + i.cost, pq.push({i.e,cost[i.e]}), path[i.e] = s; 
    }
}