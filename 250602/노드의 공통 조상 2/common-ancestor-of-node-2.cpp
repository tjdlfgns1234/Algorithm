#include<bits/stdc++.h>
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define k 347
#define MOD 1000000007
#define MAX 50'001
#define INF 987654321
#define ll long long
using namespace std;

// dfs로 구현해야 depth를 알기가 쉬움

int n, m, root;
vector<vector<int>> arr(MAX);
int d[MAX] = { 0 };
int p[MAX][21] = {0};
void solve();
void init();
void dfs(int cur);
int lca(int x, int y);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(), cout.tie();
	
	int t = 1;
	// cin >> t;

	while(t--)
		init(), solve();

	return 0;
}
void init() {
	memset(d, 0, sizeof(d));
	memset(p, 0, sizeof(p));

	for (auto& i : arr)
		i.clear();

}

void solve() {
	cin >> n;

	int x, y;
	for (int i = 0; i < n - 1; i++) {
		cin >> x >> y;

		arr[x].push_back(y);
		arr[y].push_back(x);
	}

	// root = 1; // 루트노드는 1
	root = 1;
	d[root] = 1;
	dfs(root); // 깊이 탐색, root는 depth가 1

	int div = n, h = 0;
	// h = log(div)
	while (div > 1) {
		div /= 2;
		h++;
	}
	
	for (int i = 1; i <= h; i++)
		for (int j = 2; j <= n; j++) // 1은 루트 이므로 제외
			if (p[j][i - 1])
				p[j][i] = p[p[j][i - 1]][i - 1];
	
	cin >> m;
	// cout << m << '\n';
	
	for (int i = 0; i < m; i++)
		cin >> x >> y, cout << lca(x, y) << '\n';


}
void dfs(int cur) {
	for (auto& i : arr[cur])
		if (!d[i]){
			d[i] = d[cur] + 1;
			p[i][0] = cur, dfs(i);
		}
}
int lca(int x, int y) {
	if (d[x] < d[y]) swap(x, y);

	int diff = d[x] - d[y];

	for (int i = 0; diff > 0; i++) {
		if (diff & 1)
			x = p[x][i];
		diff = diff >> 1; // 2^n로 올려줌
	}

	if (x != y) {
		// x와 y가 같지 않을 경우
		for (int i = 20; i >= 0; i--) {
			if (p[x][i] && p[x][i] != p[y][i])
				x = p[x][i], y = p[y][i];
		}
		x = p[x][0];
	}

	return x;
}