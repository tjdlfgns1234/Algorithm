#include <bits/stdc++.h>
using namespace std;

void solve();
void calc();
void init();

string a,b;
int dp[1001][101] = {0};
int arr[1001][101] = {0};	

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL), std::cout.tie(NULL);

    solve();

    return 0;
}
void init(){
    for(int i = 1; i <= a.size(); i ++)
        for(int j = 1; j <= b.size(); j++)
            dp[i][j] = 0;
}
void solve() {
    cin >> a >> b;

    calc();
}
void calc(){

    init();
    // 1계단 올라가는 경우는 최대 3번
    int size = a.size();
    for(int i =1; i <= a.size();i++)
        dp[1][i] = 1;

    for(int i = 1; i <= a.size(); i++) 
        for(int j = 1; j <=b.size() ; j++) 
            if(a[i-1]== b[j-1])
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);


    // for (int i = 1; i <= size; i++)
    //     cout <<  dp[size][i] << ' ';
    
   cout << dp[a.size()][b.size()];
}