#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    cin >> n;

    map<int,int> mp;

    string s;
    int a,b;
    while(n--){
        cin >> s;

        if(s == "add")
            cin >> a >> b, mp[a] = b;
        else if(s == "find"){
            cin >> a;
            if(mp[a] != 0)
                cout << mp[a] << "\n";
            else
                cout << "None\n";
        }
        else if(s == "remove")
            cin >> a, mp[a] = 0;
        else if(s == "print_list"){
            int cnt = 0;
            for(auto i : mp)
                if(i.second != 0)
                    cout << i.second << " ", cnt++;
            if(cnt == 0)
                cout << "None";
            cout << '\n';
        }    
    }




    return 0;
}