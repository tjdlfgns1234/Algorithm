#include <bits/stdc++.h>
using namespace std;

void solve();
void dfs();

vector <vector<int>> g(1001);
int vit[1001] = { 0 };
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
    for(int i = 0; i < m;i++){
        cin >> a >> b;

        // 양 방향 그래프
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs();
}
void dfs(){
    int s = 1;

    queue<int> q;
    q.push(s);
    int ans = 0;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        vit[x] = true;
        for(auto i : g[x])
            if(!vit[i])
                q.push(i), vit[i] = true, ans++;
    }
    cout << ans;
}