#include <bits/stdc++.h>
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define K 256
#define MOD 127
#define MAX 100001
#define INF 987654321
#define ll long long
using namespace std;

int n, k;
string a, b;
int f[MAX] = { 0 };


void solve();

int main() {

	ios::sync_with_stdio(false);
	cin.tie(), cout.tie();

	solve();

	return 0;
}
void solve() {
	cin >> a >> b;

	int n = a.size();
	int m = b.size();

	a = "#" + a;
	b = "#" + b;

	f[0] = -1;
	

	for (int i = 1; i <= m; i++) {
		int j = f[i - 1];

		while (j >= 0 && b[j + 1] != b[i])
			j = f[j];
		f[i] = j + 1;
	}

	int cnt = 0, pre =-1;
	int j = 0;
	for (int i = 1; i <= n; i++) {
		while (j >= 0 && b[j + 1] != a[i])
			j = f[j];

		j++;

		if (j == m) {
			// cout << i << '\n';
			if (pre == -1)
				pre = i;
			else if (pre + m -1 >=  i)
				continue;
	
			cnt++;
			j = f[j];
		}
	}
	cout << cnt;
}