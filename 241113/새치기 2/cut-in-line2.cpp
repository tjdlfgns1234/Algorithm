#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()

using namespace std;

list <string> heads[11];

void insert(int idx, string name);
void insert_prev(string a, string b);
void insert_prev_multi(string a, string b, string c);
void remove(string a);
void print();
void solve();

int n, m, q, cnt = 0;

map<string, int> mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
void solve() {
    cin >> n >> m >> q;

    string name;
    for (int i = 1; i <= n; i++) {
        cin >> name;
        insert(i / (n / m) + (i % (n / m) != 0), name);
    }

    //print();

    while (q--) {
        int op;
        cin >> op;

        string a, b, c;

        if (op == 1) {
            cin >> a >> b;
            insert_prev(a, b);
        }
        else if (op == 2) {
            cin >> a;
            remove(a);
        }
        else if (op == 3) {
            cin >> a >> b >> c;
            insert_prev_multi(a, b, c);
        }
        // cout << '\n';
        // print();
        // cout << '\n';
        // print();
    } 

    print();
}
void insert(int idx, string name) {
    heads[idx].push_back(name);
    mp[name] = idx;
}
void print() {
    for (int i = 1; i <= m; i++) {
        if (!heads[i].empty()) {
            for (auto it = heads[i].begin(); it != heads[i].end(); it++)
                cout << *it << " ";
            cout << '\n';
        }
        else
            cout << -1 << '\n';
    }
    
}
void insert_prev(string a, string b) {
    heads[mp[a]].erase(remove(all(heads[mp[a]]), a));
    mp[a] = mp[b];

    for(auto it = heads[mp[b]].begin(); it != heads[mp[b]].end(); it++)
        if (*it == b) {
            heads[mp[b]].insert(it, a);
            break;
        }
            
}
void remove(string a) {
    for (auto it = heads[mp[a]].begin(); it != heads[mp[a]].end(); it++) 
        if(*it == a){
            heads[mp[a]].erase(it);
            break;
        }
    mp[a] = -1;
}
void insert_prev_multi(string a, string b, string c) {
    // a, b, c의 위치
   
    list <string> tmp;

    bool f = false;
    for (auto it = heads[mp[a]].begin(); it != heads[mp[a]].end(); it++) 
        if (*it == b)
            tmp.push_back(*it), f = false;
        else if (*it == a)
            tmp.push_back(*it), f = true;
        else if (f)
            tmp.push_back(*it);
    
    //print();

    auto tmp_it = tmp.begin();
    for (auto it = heads[mp[a]].begin(); it != heads[mp[a]].end(); it++) 
        if (*it == *tmp_it) 
             mp[*it] = mp[c], it = heads[mp[a]].erase(it) ,tmp_it++, it--;

    //print();
    
    for (auto it = heads[mp[c]].begin(); it != heads[mp[c]].end(); it++)
        if (*it == c)
            heads[mp[c]].insert(it, all(tmp));
       
}