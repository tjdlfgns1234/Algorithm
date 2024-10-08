#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[100001];

void solve();
int lower_bound(int target);
int upper_bound(int target);


int main() {
   
    solve();

    return 0;
}
void solve(){
    // 오름 차순 정렬
    // 동일한 숫자가 여러 번 주어질 수 있음.
    cin >> n >> m;

    for(int i = 0; i < n;i++) cin >> arr[i];

    int query;
    for(int i = 0; i < m;i++){ 
        cin >> query;
        int a = upper_bound(query), b = lower_bound(query);

        cout << a - b << '\n';
    }
}
int lower_bound(int target){
    int l = 0, r = n-1;
    int min_idx = n;

    while(l<= r){
        int mid = r - (r - l)/2;

        if(arr[mid] >= target)
            r = mid -1, min_idx = min(min_idx,mid);
        else
            l = mid +1;
    }

    return min_idx;
}
int upper_bound(int target){
    int l = 0, r = n-1;
    int min_idx = n;

    while(l<= r){
        int mid = r - (r - l)/2;

        if(arr[mid] > target)
            r = mid -1, min_idx = min(min_idx,mid);
        else
            l = mid +1;
    }

    return min_idx;
}