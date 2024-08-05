#include <bits/stdc++.h>
using namespace std;

void dfs(int cnt);

int n;
int vit[9] = {0};
vector<int> arr;

int main() {
    cin >> n;

    dfs(0);

    return 0;
}
void dfs(int cnt){
    if(cnt == n){
        for(int i = 0; i < n;i++)
            cout << arr[i]<<  " ";
        cout << "\n";

        return;
    }

    for(int i = 1; i <= n; i++){
        if(!vit[i]){
            arr.push_back(i), vit[i] = true;
            dfs(cnt+1);
            arr.pop_back(), vit[i] = false;
        }
    }
}