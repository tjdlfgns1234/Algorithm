#include <bits/stdc++.h>
using namespace std;

set<int> s;

void solve();

int main() {
    solve();

    return 0;
}

void solve(){
    int n;
    cin >> n;

    int x;
    while(n--){
        string op;
        cin >> op;

        if(op == "add"){
            cin >> x;

            s.insert(x);
        }
        else if(op == "remove"){
            cin >> x;

            s.erase(x);
        }
        else if(op == "find"){
            cin >> x;

            if(s.find(x) != s.end())
                cout << "true" << '\n';
            else
                cout << "false" << '\n';
        }
        else if(op == "lower_bound"){
            cin >> x;

            if(s.lower_bound(x) != s.end())
                cout << *s.lower_bound(x) << '\n';
            else
                cout << "None" << '\n';
        }
        else if(op == "upper_bound"){
            cin >> x;

            if(s.upper_bound(x) != s.end())
                cout << *s.upper_bound(x) << '\n';
            else
                cout << "None" << '\n';
        }
        else if(op == "largest"){
            if(s.size() == 0)
                cout << "None" << '\n';
            else
                cout << *s.rbegin() << '\n';
        }
        else if(op == "smallest"){
            if(s.size() == 0)
                cout << "None" << '\n';
            else
                cout << *s.begin() << '\n';
        }
    }
}