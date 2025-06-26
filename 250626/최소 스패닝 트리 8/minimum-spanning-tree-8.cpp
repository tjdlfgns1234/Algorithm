#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define MAX 100'001
#define INF 100'000'000

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve();
int g[501][501];
int cost[1001] = { 0 };
bool vit[1001] = { false };

int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL), std::cout.tie(NULL);

	// freopen("input.txt", "r", stdin);

	int t = 1;
	// cin >> t;

	while (t--)
		solve();

	return 0;
}
void solve() {
	int n, m;
	cin >> n >> m;

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;

		// 양방향
		g[a][b] = c;
		g[b][c] = c;
	}

	for (int i = 1; i <= n; i++)
		cost[i] = INF;

	int ans = 0;
	cost[1] = 0;

	for (int i = 1; i <= n; i++) {
	
		int min_idx = -1;
		for (int j = 1; j <= n; j++) {
			if (vit[j]) continue;
		
		
			if (min_idx == -1 || cost[min_idx] > cost[j])
				min_idx = j;
		}

		vit[min_idx] = true;

		ans += cost[min_idx];

		for (int j = 1; j <= n; j++) {
	
			if (g[min_idx][j] == 0)
				continue;

			cost[j] = min(cost[j], g[min_idx][j]);
		}
	}

	cout << ans;
}