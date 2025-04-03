#include <bits/stdc++.h>
#define MAX 100001

using namespace std;

int n, m;

int p[MAX] = {0};
int s[MAX] = {0};

void init();
int find(int x);
bool _union(int x,int y);


void solve();

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
void solve(){
    cin >> n;

    init();

    int x,y;
    while(n--){
        cin >> x >> y;
        
        _union(x,y), cout << s[find(x)] << '\n';
    }
}
void init(){
    for(int i = 0; i < MAX;i++) p[i] = i, s[i] = 1;
}
int find(int x){
    if(x == p[x])
        return x;

    return x = find(p[x]);
}
bool _union(int x,int y){
    x = find(x), y = find(y);

    if(x == y)
        return false;

    if(x < y)
        p[y] = x, s[x] += s[y];
    else
        p[x] = y, s[y] += s[x];

    return true;
}



