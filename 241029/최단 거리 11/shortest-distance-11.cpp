#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

struct edge{
    int e,cost;
};

int n, m, k;

vector<vector<edge>> v(1001);
int g[1001][1001];
int cost[1001];

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
        g[s][e] = c;
        g[e][s] = c;
    }

    int a, b;
    cin >> a >> b;
    k = b;

    dijkstra();

    int sx = b;
    cout << cost[a] << '\n';

    int x = a;

    cout << x << ' ';

    while(x != b) {
        for(int i = 1; i <= 5; i++) {
            // 간선이 존재하지 않는 경우에는 넘어갑니다.
            if(g[i][x] == 0)
                continue;
            
            // 만약 b -> ... -> i -> x ... -> a로 
            // 실제 최단거리가 나올 수 있는 상황이었다면
            // i를 작은 번호부터 보고 있으므로
            // 바로 선택해줍니다.
            // cout << cost[i] << " " << g[i][x] << ' ' << cost[x] << '\n';
            if(cost[i] + g[i][x] == cost[x]) {
                x = i;
                break;
            }
        }
        cout << x << ' ';
    }

 

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
            if(cost[s] + i.cost < cost[i.e]){
                cost[i.e] = cost[s] + i.cost, pq.push({i.e,cost[i.e]}); 
            }
    }
}