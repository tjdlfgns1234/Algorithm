#include<bits/stdc++.h>
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define k 347
#define MOD 1000000007
#define INF 987654321
#define ll long long
using namespace std;

string st;
int ans = 0;
ll arr[5'001] = { 0 };
void solve();

int main() {

	ios::sync_with_stdio(false);
	cin.tie(), cout.tie();

	solve();

	return 0;
}
void solve() {
    cin >> st;


    int n = st.size();
    set<string> s;
    for(int i = 0; i < n;i++)
        for(int j = 0; j < n-i;j++){
         
            s.insert(st.substr(j, i + 1));
            //ans += s.size();
            //s.clear();
        }
    ans = s.size();
    cout << ans;
}