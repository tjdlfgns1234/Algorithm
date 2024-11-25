#include <bits/stdc++.h>
using namespace std;


// 트리는 어떤 정점을 고르더라도 두 정점 사이를
// 연결하는 경로는 유알하게 결정된다는 특징 


int n;
vector<vector<pair<int,int>>> arr(100001);
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

    int s,e, c;
    for(int i = 1;i <=n;i++){
        cin >> s >> e >> c;

        arr[s].push_back({e, c});
        arr[e].push_back({s, c});
    }

    dfs();
}
void dfs(){
    queue<int> q;

    int s = 0, v =0;
    q.push(1), vit[1] = true, p[1] = 0; 
    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(auto i : arr[x])
            if(!vit[i.first]){
                q.push(i.first), vit[i.first] = true;
                p[i.first] = p[x]+i.second;
                if(v < p[i.first])
                    v = p[i.first], s = i.first;
            }
    }
    memset(p,false,sizeof(p));
    memset(vit,false,sizeof(vit));
    
    q.push(s), vit[s] = true, p[s] = 0; 
    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(auto i : arr[x])
            if(!vit[i.first]){
                q.push(i.first), vit[i.first] = true;
                p[i.first] = p[x]+i.second;
                if(v < p[i.first])
                    v = p[i.first];
            }
    }

    cout << v;

    //for(int i = 1; i <= n; i++)
    //    cout << p[i] << '\n';
}