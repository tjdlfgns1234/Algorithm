#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define MOD 1'000'000'007
#define MAX 100'001
#define INF 987'654'321
#define ll long long
using namespace std;

// dfs로 구현해야 depth를 알기가 쉬움

int n, m, root;
vector<vector<int>> arr(MAX);
int d[MAX] = { 0 }, p[MAX][21] = { 0 }, color[MAX];
bool vit[MAX] = { false };
int dp[MAX] = { 0 };
int dp_color[MAX] = { 0 };
void solve();
void get_depth(int& div, int& h);
void init();
void bfs(int start);
int lca(int x, int y);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(), cout.tie();

	freopen("input.txt", "r", stdin);

	int t = 1;
	// cin >> t;

	while (t--)
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

	int x, y,k, q;
	// 정점 입력
	for (int i = 0; i < n - 1; i++) {
		cin >> x >> y;

		arr[x].push_back(y);
		arr[y].push_back(x);
	}

	cin >> k;
	int tmp; // 색깔 기록
	for (int i = 0; i < k; i++) 
		cin >> tmp, color[tmp]++;
	
	// root는 1번
	bfs(1);	
	
	// 높이 구하기
	int div = n, h = 0;
	// h = log(div)
	get_depth(div, h);

	for (int i = 1; i <= h; i++)
		for (int j = 2; j <= n; j++) // 1은 루트 이므로 제외
			p[j][i] = p[p[j][i - 1]][i - 1];

	// 쿼리 파트
	cin >> q;
	int a, b;
	for (int i = 0; i < q; i++) {
		cin >> a >> b;

		cout << dp[a] + dp[b] - 2*dp[lca(a,b)] + color[lca(a,b)] << '\n';
	}
}
void get_depth(int& div, int& h)
{
	while (div > 1) {
		div /= 2;
		h++;
	}
}
void bfs(int start) {
	// 루트는 1번
	queue <int> q;
	vit[start] = true;
	dp[start] = color[start]; //  이미 0임
	// dp_color[start] = color[start]; //  이미 0임
	q.push(start);

	// 깊이 및 부모 기록
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto& i : arr[cur])
			if (!vit[i]) {
				// 트리는 하나의 경로만 가지고 있다
				dp[i] = dp[cur] + color[i];
				// dp_color[i] = dp[cur] + color[i];
				q.push(i), vit[i] = true;
				p[i][0] = cur, d[i] = d[cur] + 1; // 바로 위 조상을 기록
			}
	}
}
int lca(int x, int y) {
	if (d[x] < d[y]) swap(x, y);
	// 더 깊은 것을 선택

	int diff = d[x] - d[y];

	for (int i = 0; diff > 0; i++) { // 깊이를 맞춰줌
		if (diff & 1)
			x = p[x][i];
		diff = diff >> 1; // 2^n번째로 올려줌
	}

	if (x != y) { // x와 y가 같지 않을 경우
		for (int i = 20; i >= 0; i--)
			if (p[x][i] && p[x][i] != p[y][i]) {
				x = p[x][i];
				y = p[y][i];
			}
		x = p[x][0];
	}


	return x;
}