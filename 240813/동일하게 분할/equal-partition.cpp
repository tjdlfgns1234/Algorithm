#include <bits/stdc++.h>
using namespace std;

void solve();
void calc();

int n;
int arr[100];
int dp[100001] = {0};
int sum = 0;


int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL), std::cout.tie(NULL);

    solve();

    return 0;
}
void solve() {
    cin >> n;

    for(int i = 0; i < n;i++)
        cin >> arr[i], sum+= arr[i];
    
    if(sum&1)
        cout << "No";
    else
        calc();
}
void calc(){
    dp[0] = 1;

   for(int i = 0; i < n;i++){
        for(int j = sum/2;j>=0;j--){
            if(arr[i] > j)continue;
            if(dp[j-arr[i]])
                dp[j] =1;
        }
   }

   if(dp[sum/2])
        cout << "Yes";
    else
        cout << "No";
}