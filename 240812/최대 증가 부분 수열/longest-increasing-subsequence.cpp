#include <bits/stdc++.h>
using namespace std;

void solve();
void calc();

int n;
int arr[1000];
int dp[1000] = {0};

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
        cin >> arr[i];

    calc();
}
void calc(){
    int ans = 0;

    for (int i = 0; i < n; i++){
		if (dp[i] == 0) 
			dp[i]++;
		for (int j = 0; j < n; j++)
			if (arr[i] > arr[j])
				if (dp[i] < dp[j] + 1)
					dp[i] = dp[j] + 1;
	}
    
    int result = 0;
   	for (int i = 0; i < n; i++)
		if (result < dp[i])
			result = dp[i];

    cout << result;
}