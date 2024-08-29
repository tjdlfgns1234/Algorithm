#include <bits/stdc++.h>
using namespace std;

priority_queue <int> pq;
int n;

int main() {
    cin >> n;

    string s;    
    while(n--){
        cin >> s;

        int tmp;
        if(s == "push")
            cin >> tmp, pq.push(tmp);
        else if(s == "size")
            cout << pq.size() << '\n';
        else if(s == "pop")
            cout << pq.top() << '\n', pq.pop();
        else if(s == "empty")
            cout << pq.empty() << '\n';
        else
            cout << pq.top() << '\n'; 
    }

    return 0;
}