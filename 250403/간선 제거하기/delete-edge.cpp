#include <bits/stdc++.h>
#define MAX 100001

using namespace std;

struct Edge{
    int s,e,cost;
};

int n, m;
int p[MAX] = {0};
vector<Edge> edges;


void solve();
void init();
int find(int x);
bool _union(int x,int y);

bool compare(const Edge& a, const Edge& b){
    return a.cost < b.cost;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
void solve(){
    cin >> n >> m;

    init();

    int x,y, z;
    while(m--){
        cin >> x >> y >> z; 

        edges.push_back({x,y,z});
    }

    sort(edges.begin(), edges.end(),compare);

    int ans = 0;
    for(int i = 0; i < edges.size();i++){
        if(!_union(edges[i].s, edges[i].e))
            ans += edges[i].cost;
    }

    cout << ans;
}
void init(){
    for(int i = 0; i < MAX;i++) p[i] = i;
}
int find(int x){
    if(x == p[x])
        return x;

    return x = find(p[x]);
}
bool _union(int x,int y){
    x = find(x), y = find(y);

    if(x == y)
        return false;

    if(x < y)
        p[y] = x;
    else
        p[x] = y;

    return true;
}



