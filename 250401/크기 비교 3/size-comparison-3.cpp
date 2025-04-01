#include <bits/stdc++.h>
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define MAX 1001

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
int ans[MAX + 1] = {0};
int indeg[MAX + 1] = { 0 };
stack<int> rev;
int n, m, cnt = 1;

void solve();

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
		indeg[y]++;
		// g[y].push_back(x);
	}

	priority_queue<int, vector<int>,greater<>> pq;
	int chk = 0;

	for (int i = 1; i <= n; i++)
		if (indeg[i] == 0)
			pq.push(i), chk++;

	while (!pq.empty()) {
		int cur = pq.top();
		pq.pop();
	
		cout << cur << " ";

		for (auto& next : g[cur]) {
			indeg[next]--;

			if (indeg[next] == 0) {
				pq.push(next);
				chk++;
				// ans[next] = ans[cur] + 1;
			}
		}
	}
	// cout << chk << " " << n << '\n';
	

	//for (int i = 1; i <= n; i++)
	//	cout << ans[i] << " ";
}