#include <bits/stdc++.h>

using namespace std;

// 한 노드를 나타내는 구조체입니다.
struct Node {
    // 문자열을 값으로 가집니다.
    string data;
    Node *prev, *next;

    Node(string data) : data(data), prev(nullptr), next(nullptr) {};
};

void solve();
void connect(Node *s, Node *e);
void insertNext(Node *target, Node *s);
void insertPrev(Node *target, Node *s);
void printNode(Node *target);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
void solve(){
string s;
    cin >> s;

    // 시작 값
    Node *cur = new Node(s);

    int n;
    cin >> n;

    while (n--) {
        int op;
        cin >> op;

        if (op == 1) { // 앞에 삽입
            string data;
            cin >> data;
            Node *target = new Node(data);
            insertPrev(cur, target);
        }

        if (op == 2) { // 뒤에 삽입
            string data;
            cin >> data;
            Node *target = new Node(data);

            insertNext(cur, target);
        }

        if (op == 3) { // 한칸 앞으로
            if (cur->prev != nullptr) cur = cur->prev;
        }

        if (op == 4) { // 한칸 뒤로
            if (cur->next != nullptr) cur = cur->next;
        }

        // 매 연산이 진행될 때마다 cur의 값을 출력합니다.
        printNode(cur);
    }
}
void connect(Node *s, Node *e) {
    // 연결
    if (nullptr != s) s->next = e;
    if (nullptr != e) e->prev = s;
}
void insertNext(Node *target, Node *s) {
    // 특정 노드의 다음에 삽입
    connect(s, target->next);
    connect(target, s);
}

void insertPrev(Node *target, Node *s) {
    // 특정 노드의 이전에 삽입
    connect(target->prev, s);
    connect(s, target);
}

void printNode(Node *target) {
    string n = "(Null)";

    // 이전 노드가 존재하지 않는다면, Null을 출력합니다.
    // 아니라면, 이전 노드의 값을 출력합니다.
    if (target->prev == nullptr) cout << n << " ";
    else cout << target->prev->data << " ";

    // target의 값을 출력합니다.
    cout << target->data << " ";

    // 다음 노드가 존재하지 않는다면, Null을 출력합니다.
    if (target->next == nullptr) cout << n << "\n";
    else cout << target->next->data << "\n";
}