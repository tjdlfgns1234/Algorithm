#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define INF 1e11
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
ll dp[MAX][MAX][2]; // 찬스 1회 사용, 미사용

void solve();
ll dist(const Pair a, const Pair b);

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

	memset(arr, 0, sizeof(arr));

	for (int i = 1; i <= n; i++) 
		cin >> arr[i].x >> arr[i].y;
	

	sort(arr + 1, arr + n+1);

	// cout << arr[1].x << " " << arr[n].x << '\n';

	for (int i = 1; i < MAX; i++)
		for (int j = 1; j < MAX; j++)
			dp[i][j][0] = INF, dp[i][j][1] = INF;

	dp[1][1][0] = 0;

	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) {
			if (dp[i][j][0] == INF && dp[i][j][1] == INF) continue;
			
			int next = max(i, j) + 1;

			if (next == n + 1)
				continue;

			if (dp[i][j][0] != INF) { // 찬스 사용하지 않는 경우
				// 찬스 사용하지 않고 진행
				dp[next][j][0] = min(dp[next][j][0], dp[i][j][0] + dist(arr[i], arr[next]));
				dp[i][next][0] = min(dp[i][next][0], dp[i][j][0] + dist(arr[j], arr[next]));
			
				// 찬스 사용
				dp[next][j][1] = min(dp[next][j][1], dp[i][j][0]);
				dp[i][next][1] = min(dp[i][next][1], dp[i][j][0]);

			}
			
			// 찬스를 이미 사용한 경우
			if (dp[i][j][1] != INF) {
				dp[next][j][1] = min(dp[next][j][1], dp[i][j][1] + dist(arr[i], arr[next]));
				dp[i][next][1] = min(dp[i][next][1], dp[i][j][1] + dist(arr[j], arr[next]));
			}
		}
	
	ll ans = INF;
	for (int i = 1; i < n; i++) {
		// 
		if (dp[n][i][1] != INF) ans = min(ans, dp[n][i][1] + dist(arr[i], arr[n]));
		if (dp[n][i][0] != INF) ans = min(ans, dp[n][i][0]);
	
		if (dp[i][n][1] != INF) ans = min(ans, dp[i][n][1] + dist(arr[i], arr[n]));
		if (dp[i][n][0] != INF) ans = min(ans, dp[i][n][0]);
	
	}

	cout << ans;
}
ll dist(const Pair a, const Pair b) {
	return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}