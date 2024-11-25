#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> arr(100001);
int p[100001] = {0};
bool vit[100001] = {0};

void solve();
void dfs();

int main() {
    // 여기에 코드를 작성해주세요.
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    solve();


    return 0;
}
void solve(){
    cin >> n;

    int s,e;
    for(int i = 1;i <=n;i++){
        cin >> s >> e;

        arr[s].push_back(e);
        arr[e].push_back(s);
    }

    dfs();
}
void dfs(){
    queue<int> q;

    q.push(1), vit[1] = true; 
    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(auto i : arr[x])
            if(!vit[i])
                q.push(i), vit[i] = true, p[i] = x;
    }
    
    for(int i = 2; i <= n; i++)
        cout << p[i] << '\n';
}