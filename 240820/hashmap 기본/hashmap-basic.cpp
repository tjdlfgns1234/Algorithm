#include <bits/stdc++.h>
using namespace std;

int main() {

    unordered_map<int,int> mp;

    int n;
    cin >> n;

    while(n--){
        string s;
        cin >> s;

        
        int a,b;
        if(s == "add"){
            cin >> a >> b;

            mp[a] = b;
        }
        else if(s == "find"){
            cin >> a;
            if(mp[a] == 0)
                cout << "None\n";
            else
                cout << mp[a] << '\n';
        }
        else if(s == "remove"){
            cin >> a;
            mp[a] = 0;
        }

    }





    return 0;
}