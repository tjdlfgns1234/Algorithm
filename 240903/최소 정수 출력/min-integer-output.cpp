#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int> pq;

    while(n--){
        int tmp;
        cin >> tmp;

        if(tmp == 0)
            if(pq.empty())
                cout << 0 << '\n';
            else
                cout << -pq.top() << '\n', pq.pop();
        else 
            pq.push(-tmp);
    }


    return 0;
}