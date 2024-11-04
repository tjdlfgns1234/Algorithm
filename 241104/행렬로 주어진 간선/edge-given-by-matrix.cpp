#include <bits/stdc++.h>
using namespace std;

void solve();

int g[101][101] = {0};

int main() {
    
    solve();

    return 0;
}
void solve(){
    int n;
    cin >> n;

    for(int i = 1; i <= n;i++)
        for(int j = 1; j <= n; j++)
            cin >> g[i][j];
    


    for(int i = 1; i <= n; i++)
        g[i][i] = 1; // 자기 자신은 모두 표시

    for(int k = 1; k <= n; k++) // 확실하게 거쳐갈 정점을 1번부터 N번까지 순서대로 정의합니다.
        for(int i = 1; i <= n; i++) // 고정된 k에 대해 모든 쌍 (i, j)를 살펴봅니다.
            for(int j = 1; j <= n; j++)
                // i -> k, k -> j로 가능 길이 있다면
                // i -> j도 가능하다는 뜻입니다.
                if(g[i][k] && g[k][j])
                    g[i][j] = 1;

    
    for(int i = 1; i <= n;i++){
        for(int j = 1; j <= n; j++)
            cout << g[i][j] << ' ';
        cout << '\n';
    }
}