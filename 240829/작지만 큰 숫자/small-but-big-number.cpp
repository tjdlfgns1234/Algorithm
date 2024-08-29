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

        set<int>::iterator it = s.upper_bound(tmp);
        if(it == s.begin()){
            cout << -1 << '\n';
            continue;
        }
        it--;

        cout << *it <<'\n', s.erase(*it);
    }




    return 0;
}