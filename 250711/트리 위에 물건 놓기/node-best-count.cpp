#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define MAX 100'001
#define INF 1e9

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve();
void dfs(int cur, int pre);

int n;
vector<vector<int>> arr(MAX);
int dp[MAX][2]; // 0: 미색칠, 1: 색칠
bool vit[MAX] = {false};

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

    int a, b;
    for(int i = 0; i < n;i++){
        cin >> a >> b;
        // 경로가 하나뿐인 트리임이 보장됨
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    vit[1] = true;
    dfs(1,1);
    
    // for(int i = 1; i<= n;i++){
    //     // cout << dp[i][0] << " " << dp[i][1] << '\n';
    //     ans = max(ans,max(dp[i][0],dp[i][1]));
    // }

    cout << min(dp[1][0], dp[1][1]) << '\n';
}
void dfs(int cur, int pre){
    dp[cur][1] = 1;
    
    for(auto& child : arr[cur]) 
        if(!vit[child]) {
            vit[child] = true, dfs(child, cur);
            dp[cur][0] += dp[child][1];
            dp[cur][1] += min(dp[child][0], dp[child][1]);
        }
    
    // cout << cur << " : " << dp[cur][0] << " " << dp[cur][1] << '\n';
}

