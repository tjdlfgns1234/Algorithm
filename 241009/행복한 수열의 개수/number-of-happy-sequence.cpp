#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[101][101] = {0};

void solve();

int main() {
    cin >> n >> m;

    for(int i = 0; i < n;i++)
        for(int j = 0; j < n;j++)
            cin >> arr[i][j];

    solve();

    return 0;
}
void solve(){
    // m개 이상의 동일한 원소
    int ans = 0;
    for(int i = 0; i < n;i++){
        int pre = -1, cnt = 0;
        for(int j = 0; j < n;j++){
            if(cnt == 0){
                pre = arr[i][j];
                cnt = 1;
            }
            else if(pre == arr[i][j])
                cnt++;
            else
                cnt = 1, pre = arr[i][j];
            if(cnt == m){
                ans++;
                break;
            }
        }
        pre = -1, cnt = 0;
        for(int j = 0; j < n;j++){
            if(cnt == 0){
               pre = arr[j][i];
               cnt = 1;
            }
            else if(pre == arr[j][i])
                cnt++;
            else
                cnt = 1, pre = arr[j][i];
    
            if(cnt == m){
                ans++;
                break;
            }
        }
    }

    cout << ans;

}