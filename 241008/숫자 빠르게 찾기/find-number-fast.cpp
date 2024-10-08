#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[100001] = {0};

void solve();
int bi_search(int target);

int main() {
    
    solve();

    return 0;
}
void solve(){
    // 배열은 정렬된 상태로 주어짐
    // 숫자는 전부 다름

    cin >> n >> m;
    for(int i = 1; i <= n;i++) cin >> arr[i];
    
    int query;
    for(int i = 0; i < m;i++) cin >> query, cout << bi_search(query)<<'\n';
}
int bi_search(int target){
    int l =1, r = n;

    int mid;
    while(l <= r){
        mid = l + (r-l)/2;

        if(arr[mid] < target)
            l = mid+1;
        else if(arr[mid] > target)
            r = mid-1;
        else
            return mid;
    }
    return -1;
}