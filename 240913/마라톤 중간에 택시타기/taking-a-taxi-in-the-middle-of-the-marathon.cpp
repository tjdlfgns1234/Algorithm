#include <bits/stdc++.h>
using namespace std;

struct p{
    int x,y;
};

int n;
p arr[100001];
int l[100001] = {0};
int r[100001] = {0};


int dist(p a,p b);
void solve();

int main() {
    cin >> n;

    int a,b;
    for(int i = 0; i < n; i++)
         cin >> a >> b, arr[i].x = a, arr[i].y = b;

    for(int i = 1; i < n; i++)
        l[i] = dist(arr[i-1], arr[i]);

    for(int i = n-2; i >= 0; i--)
        r[i] = dist(arr[i+1], arr[i]);

    solve();



    return 0;
}
void solve(){
    int ans = 987654321;

    for(int i = 0; i < n-1;i++)
        ans = min(ans, l[i] + r[i+2] + dist(arr[i+2],arr[i]));
    

    cout << ans;

}
int dist(p a,p b){
    return (abs(a.x-b.x)+abs(a.y-b.y));
}