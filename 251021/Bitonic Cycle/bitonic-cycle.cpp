#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define INF 1e9
#define sum(a) (a*(a+1)/2)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int MAX = 1001;

struct Pair {
	int x, y;

};

int n;
Pair arr[MAX];
int dp[MAX][MAX];


void solve();
int dist(const Pair a, const Pair b);

bool operator<(const Pair a, const Pair b) {
	return a.x < b.x;
}
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
	cin >> n;

	int start = 0, value = INF;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i].x >> arr[i].y;

		// 값은 전부 다름
		if (value > arr[i].x) 
			value = arr[i].x, start = i;
	}

	sort(arr+1, arr + n+1);


	for (int i = 1; i < MAX; i++)
		for (int j = 1; j < MAX; j++)
			dp[i][j] = INF;

	dp[1][1] = 0;

	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) {
			int next = max(i, j) + 1;

			if (next == n + 1)
				continue;

			dp[next][j] = min(dp[next][j], dp[i][j] + dist(arr[i], arr[next]));
			dp[i][next] = min(dp[i][next], dp[i][j] + dist(arr[j], arr[next]));
		}
	
	int ans = INF;
	for (int i = 1; i < n; i++) ans = min(ans, dp[i][n] + dist(arr[i], arr[n]));

	cout << ans;
}
int dist(const Pair a, const Pair b) {
	return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}