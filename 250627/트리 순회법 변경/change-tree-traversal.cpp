#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define MAX 100'001
#define INF 100'000'000'000'000'001

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve();
void preorder(int l, int r);
struct P {
	int l, r;
}p[10001];

void preorder(int l, int r);
int arr[10001];
int cnt = 0, n;

int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL), std::cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	int t = 1;
	// cin >> t;

	while (t--)
		solve();

	return 0;
}
void solve() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// 전위 순회
	// A가 무조건 루트 노드
	cnt = 1;
	preorder(0, n-1);
}
void preorder(int l, int r) {
	if (l > r) return;
	int root = arr[l];
	int idx = l + 1;
	// 오른쪽 서브트리의 시작점 찾기
	while (idx <= r && arr[idx] < root) idx++;
	preorder(l + 1, idx - 1); // 왼쪽 서브트리
	preorder(idx, r);         // 오른쪽 서브트리
	cout << root << '\n';  // 루트 출력 (후위 순회)

}
