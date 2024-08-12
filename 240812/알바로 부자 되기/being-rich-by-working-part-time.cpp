#include <bits/stdc++.h>
using namespace std;

struct arba{
    int s,e,p;
};

void solve();
void calc();

int n;
arba arr[1000];
int dp[1000];

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL), std::cout.tie(NULL);

    solve();

    return 0;
}
void solve() {
    // 데이터는 정렬되어 들어옴
    cin >> n;
    
    for(int i = 0; i < n;i++)
        cin >> arr[i].s >> arr[i].e >> arr[i].p, dp[i] = arr[i].p;
    
    calc();
}
void calc(){
    // 기간이 겹치지 않고 돈이 최대!

    dp[0] = arr[0].p;
    for(int i = 1; i < n;i++){
        for(int j = 0; j < i;j++)
            if(arr[i].s > arr[j].e)
                dp[i] = max(dp[i],dp[j]+arr[i].p);
    }

    cout << *max_element(dp, dp+n);
}