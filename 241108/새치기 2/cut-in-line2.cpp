#include <bits/stdc++.h>

using namespace std;

struct Node{
    string name;
    Node* prev = nullptr;
    Node* next = nullptr;
}node[100001];

Node* heads[11] = {nullptr}; // m은 10까지

void insert(int idx, string name);
void insert_prev(string a, string b);
void insert_prev_multi(string a, string b, string c);
void remove(string a);
void print();
void solve();

int n,m,q, cnt = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
void solve(){
    cin >> n >> m >> q;

    string name;
    for(int i = 1; i <= n;i++){
        cin >> name;
        insert(i/(n/m) + (i%(n/m) != 0), name);
    }

    // print();

    while(q--){
        int op;
        cin >> op;

        string a,b,c;
        
        if(op == 1){
            cin >> a >> b;
            insert_prev(a,b);
        }
        else if(op == 2){
            cin >> a;
            remove(a);
        }
        else if(op == 3){
            cin >> a >> b >> c;
            insert_prev_multi(a, b, c);
        }
    }

    print();
}
void insert(int idx, string name){
    if(heads[idx] == nullptr){
        node[cnt].name = name;
        heads[idx] = &node[cnt++];
    }
    else{
        Node* tmp = heads[idx];
        while(tmp->next != nullptr)
            tmp = tmp->next;
        node[cnt].name = name;
        tmp->next = &node[cnt];
        node[cnt++].prev = tmp;
    }
}
void print(){
    Node* tmp;
    for(int i = 1; i <= m;i++){
        if(heads[i] == nullptr){
            cout << "-1" << '\n';
        }
        else{
            tmp = heads[i];
            while(tmp!=nullptr){
                cout << tmp->name << " ";
                tmp = tmp->next;
            }
            cout << '\n';
        }
    }
}
void insert_prev(string a, string b){
    Node* pos_a = nullptr;
    Node* pos_b = nullptr; // a와 b의 위치

    for(int i = 1;i <= m;i++ ){
        if(heads[i] != nullptr){
            if(heads[i]->name == a){ // 헤드가 찾는 것이였다면
                pos_a = heads[i];
                heads[i] = pos_a->next;
                if(heads[i]->prev != nullptr)
                    heads[i]->prev = nullptr;
                break;
            }

            Node* tmp = heads[i];
            while(tmp!=nullptr){
                if(tmp->name == a){
                    pos_a = tmp;
                    break;
                }
                if(tmp->next != nullptr)
                    tmp = tmp->next;
                else
                    break;
            }
            if(pos_a != nullptr)
                break;
        }
    }


    // a를 뺴줌
    if(pos_a->prev != nullptr)
        pos_a->prev->next = pos_a->next;
    if(pos_a->next != nullptr)
        pos_a->next->prev = pos_a->prev;

    // a를 찾고 나면
     for(int i = 1;i <= m;i++ ){
        if(heads[i] != nullptr){
            if(heads[i]->name == b){ // 헤드가 찾는 것이였다면
                pos_b = heads[i];
                heads[i] = pos_a;
                pos_a->prev = nullptr;
                pos_a->next = pos_b;
                pos_b->prev = pos_a;
                return;
            }
            // 헤드가 아닌 다른 값이라면
            Node* tmp = heads[i];
            while(tmp!=nullptr){
                if(tmp->name == b){
                    pos_b = tmp;
                    break;
                }
                if(tmp->next != nullptr)
                    tmp = tmp->next;
                else
                    break;
            }
            if(pos_b != nullptr)
                break;
        }
    }

    if(pos_b->prev != nullptr)
        pos_b->prev->next = pos_a;
    pos_a->prev = pos_b->prev;
    pos_b->prev = pos_a;
    pos_a->next = pos_b;
}
void remove(string a){
    Node* pos_a = nullptr; // a의 위치

    for(int i = 1;i <= m;i++ ){
        if(heads[i] != nullptr){
            if(heads[i]->name == a){ // 헤드가 찾는 것이였다면
                pos_a = heads[i];
                if(heads[i]->next != nullptr)
                    heads[i] = pos_a->next;
                else
                    heads[i] = nullptr;

                return;
            }
            Node* tmp = heads[i];
            while(tmp!=nullptr){
                if(tmp->name == a){
                    pos_a = tmp;
                    break;
                }
                if(tmp->next != nullptr)
                    tmp = tmp->next;
                else
                    break;
            }
            if(pos_a != nullptr)
                break;
        }
    }

    // cout <<a << ' ' <<  (pos_a == nullptr);

    if(pos_a->prev != nullptr)
        pos_a->prev->next = pos_a->next;
    if(pos_a->next != nullptr)
        pos_a->next->prev = pos_a->prev;
}
void insert_prev_multi(string a, string b, string c){
    // a, b, c의 위치
    Node* pos_a = nullptr;
    Node* pos_b = nullptr; 
    Node* pos_c = nullptr; 

    bool isahead = false;
    bool isbhead = false;
    bool ischead = false;
    bool idx = 0, idx2 = 0;

    // a 위치 찾기
    for(int i = 1;i <= m;i++ ){
        if(heads[i] != nullptr){
            if(heads[i]->name == a){ // 헤드가 찾는 것이였다면
                isahead = true;
                pos_a = heads[i];
                idx = i;
                break;
            }

            Node* tmp = heads[i];
            while(tmp!=nullptr){
                if(tmp->name == a){
                    pos_a = tmp;
                    break;
                }
                if(tmp->next != nullptr)
                    tmp = tmp->next;
                else
                    break;
            }
            if(pos_a != nullptr)
                break;
        }
    }

    // b 위치 찾기
    for(int i = 1;i <= m;i++ ){
        if(heads[i] != nullptr){
            if(heads[i]->name == b){ // 헤드가 찾는 것이였다면
                isbhead = true;
                pos_b = heads[i];
                idx = i;
                break;
            }

            Node* tmp = heads[i];
            while(tmp!=nullptr){
                if(tmp->name == b){
                    pos_b = tmp;
                    break;
                }
                if(tmp->next != nullptr)
                    tmp = tmp->next;
                else
                    break;
            }
            if(pos_b != nullptr)
                break;
        }
    }

    if(isahead){ // a가 head라면
        if(pos_b->next != nullptr){
            heads[idx] = pos_b->next;
            pos_b->prev = nullptr;
        }
        else
            heads[idx] = pos_b->next;
    }
    else{
        if(pos_a->prev != nullptr)
            pos_a->prev->next = pos_b->next;
         if(pos_b->next != nullptr)
            pos_b->next->prev = pos_a->prev;
    }

    // c 위치 찾기

     for(int i = 1;i <= m;i++ ){
        if(heads[i] != nullptr){
            if(heads[i]->name == c){ // 헤드가 찾는 것이였다면
                ischead = true;
                pos_c = heads[i];
                idx2 = i;
                break;
            }

            Node* tmp = heads[i];
            while(tmp!=nullptr){
                if(tmp->name == c){
                    pos_c = tmp;
                    break;
                }
                if(tmp->next != nullptr)
                    tmp = tmp->next;
                else
                    break;
            }
            if(pos_c != nullptr)
                break;
        }
    }


    if(ischead){    // c가 헤드였다면
        pos_c->prev = pos_b;
        pos_b->next = pos_c;
        pos_a->prev = nullptr;
        heads[idx2] = pos_a;
    }
    else{
        pos_c->prev->next = pos_a;
        pos_a->prev = pos_c->prev;
        pos_c->prev = pos_b;
        pos_b->next = pos_c;
    }
}