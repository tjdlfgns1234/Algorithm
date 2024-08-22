#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_set<int> mp;

    string s;
    int a;
    while(n--){
        cin >> s >> a;
        if(s == "find")
            if(mp.find(a) != mp.end())
                cout << "true\n";
            else
                cout << "false\n";
        else if(s == "add"){
                if(mp.find(a) == mp.end())
                    mp.insert(a);
        }
        else if(s == "remove")
            mp.erase(a);
    }
    return 0;
}