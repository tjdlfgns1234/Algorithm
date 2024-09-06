#include <iostream>
using namespace std;

int arr[100001];
int ans = 0;

int main() {
    
    int n,k;
    cin >> n >> k;

    for(int i = 0; i < n;i++) cin >> arr[i];

    int sum = 0;
    for(int i = 0; i < k;i++) sum += arr[i];

    ans = sum;

    for(int i = 1; i < n - k;i++)
        sum =sum - arr[i-1] + arr[k-1+i], ans = max(ans,sum);
    
    cout << ans;

    return 0;
}