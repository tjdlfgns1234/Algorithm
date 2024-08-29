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

        if(*s.begin() <= tmp)
            if(s.lower_bound(tmp) == s.begin())
                cout << *s.begin() << '\n', s.erase(*s.begin());
            else if(*s.lower_bound(tmp) == tmp)
                cout << *s.lower_bound(tmp) << '\n', s.erase(*s.lower_bound(tmp));
            else 
                cout << *(--s.lower_bound(tmp))  << '\n', s.erase(*(--s.lower_bound(tmp)));
        else
            cout << -1 << '\n';
    }




    return 0;
}