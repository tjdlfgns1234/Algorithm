#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b;
    cin >> a >> b;

    unordered_set<int> s;

    int ans = 0;
    int tmp;
    for(int i = 0; i < a; i++) cin >> tmp, s.insert(tmp);
    for(int i = 0; i < b; i++){
        cin >> tmp;
        if(s.find(tmp) != s.end())
            ans++;

    }
    

    cout << a + b - ans*2;
    return 0;
}