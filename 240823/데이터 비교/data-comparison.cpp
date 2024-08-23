#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    unordered_set<int> a;
    
    int tmp;

    for(int i = 0; i < n;i++) cin >> tmp, a.insert(tmp);
    
    cin >> n;
    for(int i = 0; i < n;i++) {
        cin >> tmp;
        if(a.find(tmp) != a.end())
            cout << 1 << ' ';
        else
            cout << 0 << ' ';
    }

    
    return 0;
}