#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--){
        int k;
        cin >> k;

        set<int> s;

        string op;
        int n;

        for(int i =0 ;i < k;i++){
            cin >> op >> n;

            if(op == "I")
                s.insert(n);
            else if(op == "D"){
                if(s.size() == 0)
                    continue;
                else
                    if(n == 1)
                        s.erase(*s.rbegin());
                    else
                        s.erase(*s.begin());
            }
        }
        if(s.size()>=1)
            cout << *s.rbegin() << ' ' << *s.begin() << '\n';
        else
            cout << "EMPTY\n";
    }




    return 0;
}