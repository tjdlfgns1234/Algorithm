#include<bits/stdc++.h>
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define k 347
#define k2 31
#define MOD 1000000007
#define MOD2 1234567891
#define MAX 5001
#define INF 987654321
#define ll long long
using namespace std;

string st;
ll arr[MAX] = { 0 };
ll arr2[MAX] = { 0 };
void solve();

int main() {

	ios::sync_with_stdio(false);
	cin.tie(), cout.tie();

	solve();

	return 0;
}
void solve() {
	cin >> st;
	ll ans = 0;
	arr[0] = 1;
	arr2[0] = 1;

	int n = st.size();
	for (int i = 1; i <= MAX; i++)
		arr[i] = (arr[i - 1] * k) % MOD;

	for (int i = 1; i <= MAX; i++)
		arr2[i] = (arr2[i - 1] * k2) % MOD2;

	ll hash = 0, hash2 = 0;

	// 일단 부분 문자열 부터 만들자.
	for(int size = 1; size <= n;size++){
		set<pair<ll,ll>> s;
		hash = 0, hash2 = 0;
		for (int i = 1; i <= size; i++) {
			hash += st[i-1]*arr[size-i];
			hash %= MOD;
			hash2 += st[i-1]*arr2[size-i];
			hash2 %= MOD2;
		}
		s.insert({hash, hash2});

		for (int i = size; i < n; i++) {
			hash = ((hash - st[i-size] * arr[size-1] )% MOD + MOD) % MOD;
			hash = (hash * k) % MOD;
			hash = (hash + st[i]) % MOD;

			hash2 = ((hash2 - st[i-size] * arr2[size-1] )% MOD2 + MOD2) % MOD2;
			hash2 = (hash2 * k2) % MOD2;
			hash2 = (hash2 + st[i]) % MOD2;

			s.insert({hash, hash2});
			// cout << hash << '\n';
		}
		// cout << s.size() << " " << ans << '\n';
		ans += s.size();
	}
	cout << ans;
}