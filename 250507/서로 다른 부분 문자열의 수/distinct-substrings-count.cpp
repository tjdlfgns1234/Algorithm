#include<bits/stdc++.h>
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define k 31
#define MOD 1000000007
#define MAX 5001
#define INF 987654321
#define ll long long
using namespace std;

string st;
ll arr[MAX] = { 0 };
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
	ll key = 0;

	arr[0] = 1;

	int n = st.size();
	for (int i = 1; i <= MAX; i++)
		arr[i] = (arr[i - 1] * k) % MOD;

	ll hash = 0;

	// 일단 부분 문자열 부터 만들자.
	for(int size = 1; size <= n;size++){
		set<ll> s;
		hash = 0;
		for (int i = 1; i <= size; i++) {
			hash += st[i-1]*arr[size-i];
			hash %= MOD;
		}
		s.insert(hash);

		for (int i = size; i < n; i++) {
			hash = ((hash - st[i-size] * arr[size-1] )% MOD + MOD) % MOD;
			hash = (hash * k) % MOD;
			hash = (hash + st[i]) % MOD;
			s.insert(hash);
			// cout << hash << '\n';
		}
		// cout << s.size() << " " << ans << '\n';
		ans += s.size();
	}
	cout << ans;
}