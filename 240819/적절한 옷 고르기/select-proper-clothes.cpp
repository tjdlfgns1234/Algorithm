#include <bits/stdc++.h>
using namespace std;

void solve();
void calc();
void init();

struct clothes{
    int s,e,v;
};


int n, m;
clothes arr[201] = {0};
int dp[201][201] = {0};
int info[201][201] = {0};	

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL), std::cout.tie(NULL);

    solve();

    return 0;
}
void init(){
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j++)
            dp[i][j] = 0;
}
void solve() {
    cin >> n >> m;

    for(int i = 1; i <= n;i++)
        cin >> arr[i].s >> arr[i].e >> arr[i].v;   

    calc();
}
void calc(){

    init();
    // 1계단 올라가는 경우는 최대 3번
    for(int i = 2; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
				if(arr[k].s <= i - 1 && i - 1 <= arr[k].e && arr[j].s <= i && i <= arr[j].e)
                    dp[i][j] = max(dp[i][j], dp[i - 1][k] + abs(arr[j].v - arr[k].v));
			}
        }
    }
    
    int ans = INT_MIN;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[m][i]);
    cout << ans;
}