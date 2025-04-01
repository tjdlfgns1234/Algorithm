#include <bits/stdc++.h>
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define MAX 100001

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct Edge{
	int e, c;
};

vector<vector<int>> g(MAX);
bool vit[MAX + 1] = { false };
stack<int> rev;
int n, m;

void solve();
void dfs(int x);

int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL), std::cout.tie(NULL);

	// freopen("input.txt", "r", stdin);

	int t = 1;
	//cin >> t;

	while (t--)
		solve();

	return 0;
}
void solve() {
	cin >> n >> m;

	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;

		// 단방향
		g[x].push_back(y);
		// g[y].push_back(x);
	}

	for (int i = 1; i <= n; i++)
		if (!vit[i])
			vit[i] = true, dfs(i);
	
	while (!rev.empty()) {
		cout << rev.top() << " ";
		rev.pop();
	}
}
void dfs(int x) {
	for (auto& i : g[x]) {
		int y = i;

		if (!vit[y]) {
			vit[y] = true;
			dfs(y);
		}
	}

	rev.push(x);
}

