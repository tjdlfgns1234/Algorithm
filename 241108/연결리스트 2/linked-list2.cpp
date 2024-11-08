#include <bits/stdc++.h>

#define MAX_N 100005
using namespace std;

// 한 노드를 나타내는 구조체입니다.
struct Node {
    int id;
    Node *prev, *next;

    Node(int id) : id(id), prev(nullptr), next(nullptr) {}
};

Node *nodes[MAX_N] = {};
void solve();
void insertNext(Node *u, Node *singleton);
void insertPrev(Node *u, Node *singleton);
void pop(Node *u);

int n, q, idx = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
void solve(){
    int n, q;
    cin >> n >> q;

    // N 개의 단일 노드를 생성합니다.
    for (int i = 1; i <= n; i++) {
        nodes[i] = new Node(i);
    }

    // Q 개의 연산을 진행합니다.
    for (int t = 0; t < q; t++) {
        int type, i;
        cin >> type >> i;

        if (1 == type) {
            pop(nodes[i]);
        } else if (2 == type) {
            int j;
            cin >> j;
            insertPrev(nodes[i], nodes[j]);
        } else if (3 == type) {
            int j;
            cin >> j;
            insertNext(nodes[i], nodes[j]);
        } else if (4 == type) {
            cout << ((nodes[i]->prev == nullptr) ? 0 : nodes[i]->prev->id) << ' '
                 << ((nodes[i]->next == nullptr) ? 0 : nodes[i]->next->id) << '\n';
        }
    }

    // 연산을 마친 후 1번 부터 N번 노드까지의 다음 노드 번호를 차례대로 한 줄에 출력합니다.
    for (int i = 1; i <= n; i++)
        cout << ((nodes[i]->next == nullptr) ? 0 : nodes[i]->next->id) << ' ';
}
// u 앞에 singleton을 삽입합니다.
void insertPrev(Node *u, Node *singleton) {
    singleton->prev = u->prev;
    singleton->next = u;

    if (nullptr != singleton->prev)
        singleton->prev->next = singleton;
    if (nullptr != singleton->next)
        singleton->next->prev = singleton;
}

// u 뒤에 singleton을 삽입합니다.
void insertNext(Node *u, Node *singleton) {
    singleton->prev = u;
    singleton->next = u->next;

    if (nullptr != singleton->prev)
        singleton->prev->next = singleton;
    if (nullptr != singleton->next)
        singleton->next->prev = singleton;
}

// 노드 u를 제거합니다.
void pop(Node *u) {
    if (u->prev != nullptr)
        u->prev->next = u->next;

    if (u->next != nullptr)
        u->next->prev = u->prev;

    u->prev = u->next = nullptr;
}