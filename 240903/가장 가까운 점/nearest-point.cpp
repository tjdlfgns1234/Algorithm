#include <bits/stdc++.h>
using namespace std;

int n,m;

struct p{
    int x,y;
};

bool operator <(const p& a,const p& b){
    if((a.x + a.y)==(b.x + b.y))
        return (a.y < b.y);
    else
        return ((a.x + a.y)>(b.x + b.y));
}

int main() {
    cin >> n >> m;

    priority_queue <p> pq;

    p tmp;
    while(n--){
        cin >> tmp.x >> tmp.y;
        pq.push(tmp);
    }

    while(m--){
        tmp = pq.top();
        tmp.x += 2, tmp.y += 2;
        pq.pop();
        pq.push(tmp);
    }

    cout << pq.top().x << ' ' << pq.top().y;

    return 0;
}