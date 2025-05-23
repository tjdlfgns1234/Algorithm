#include<bits/stdc++.h>
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define k 347
#define MOD 1000000007
#define MAX 10'001
#define INF 987654321
#define ll long long
using namespace std;

int n, root;
vector<vector<int>> arr(MAX);
int d[MAX] = { 0 };
int p[MAX] = { 0 };
void solve();
void dfs(int cur);
int lca(int x, int y);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(), cout.tie();

	solve();

	return 0;
}
void solve() {
	cin >> n;

	int x, y;
	for (int i = 0; i < n-1; i++) {
		cin >> x >> y;
		p[y] = x;
		arr[x].push_back(y);
		arr[y].push_back(x);
	}

	for (int i = 1; i <= n; i++) if(p[i] == 0) root = i;

    d[root] = 1;
	dfs(root); // 깊이 탐색, root는 depth가 1

	// cin >> m;
	// for(int i = 0; i < m;i++)
	cin >> x >> y, cout << lca(x, y) << '\n';


}
void dfs(int cur) {
    for(auto& i : arr[cur])
        if(!d[i])
            d[i] = d[cur] + 1, dfs(i);
}
int lca(int x, int y) {
	if (d[x] < d[y]) swap(x, y);

	while (d[x] != d[y])x = p[x];
	while (x != y) x = p[x], y = p[y];

	return x;
}