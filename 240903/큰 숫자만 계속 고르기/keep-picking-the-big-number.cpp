#include <bits/stdc++.h>
using namespace std;

int n,m;


int main() {
    cin >> n >> m;

    priority_queue<int> pq;

    int tmp;
    while(n--){
        cin >> tmp;
        pq.push(tmp);
    }

    while(m--){
        tmp = pq.top();
        pq.pop();
        tmp--;
        pq.push(tmp);
    }

    cout << pq.top();


    return 0;
}