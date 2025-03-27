#include <bits/stdc++.h>

using namespace std;

int n;
int d[10001];
vector<vector<int>> g(10001);

void solve();
int lcs(int a, int b);
void bfs();

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    // Please write your code here.

    return 0;
}
void solve(){
    cin >> n;

    int s,e;
    for(int i = 0; i < n-1;i++){
        cin >> s >> e;

        g[s].push_back(e);    
        g[e].push_back(s); 
    }

    cin >> s >> e;

    cout << lcs(s,e);
}
void bfs(){
    queue<int> q;
    q.push(1);
    d[1] = 0; // depth는 1

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(auto& i : arr){
            
        }

    }



}

int lcs(int a, int b){




}