#include <bits/stdc++.h>
using namespace std;

int n,m;

int main() {
    cin >> n >> m;

    set<int> s;

    int tmp;
    for(int i = 0; i < n; i++)
        cin >> tmp, s.insert(tmp);

    for(int i = 0; i < m; i++){
        cin >> tmp;

        set<int>::iterator it = s.lower_bound(tmp);
        if(it == s.end())
            cout << -1 << '\n';
        else
            cout << *it <<'\n';
    }


    return 0;
}