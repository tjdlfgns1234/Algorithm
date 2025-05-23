#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define SIZE 1000
#define mod 1000000007
#define MAX 4000001

/*
    !! 증명을 반드시 끝내고 제출하기 !!
    => 패널티 없는게 빨리 푸는 것 보다 중요
    배운거 내에서만 쓸 생각을 하자.

    트리에서 어떤 정점을 고르더라도 두 정점 사이를
    연결하는 경로는 유일하게 결정된다는 특징

    실수 문제의 경우 스페셜 저지 유무를 반드시 체크 할 것
    백트래킹 시 for (int i = idx; i < 26; i++) 이와 같이 초기 값이 idx인지 0인지 잘 생각하자

    dp에서 불가능한 경우도 f로 표기할 수 있다고 생각하자! (INF, 혹은 -1)
    value 값이 작으면 Prefix도 꼭 생각하자. (생각보다 쉽게 해결 가능, 삽질 많이함.)
    최대 최소 값 주의하기 (특히 int 최댓값을 넘는지 확인)
    빈 곳의 개수를 세는 것도 그래프를 잘 푸는 방법중 하나!
    /와 %연산은 배열을 나타낼때 유용하게 쓰인다.
    for문을 쓰는 것보다 전체를 한번에 초기화 할 생각을 하자. => 상수 시간 최적화
    함수 호출은 스택 메모리를 사용한다는 것에 유의하자.
    행렬을 배열로도 쓸 생각하자
    음수 연산에 주의하자. (unsigned, signed을 같이 연산은 한번 체크하기)

    BFS 구현시 큐에 다음 방문 점을 넣을 때, 반드시 먼저 확인 시키자.!
    if (!vit[nx][ny])
        q.push({ nx,ny }), vit[nx][ny] = true;

    초기값 설정을 반드시 계산하자! (특히 max, min 값, LCS에서 dp 값 등등)
    존재확인 할때는 반드시 Set을 사용하기 (map을 사용하지 말고
    Set의 키 값에는 Pair 등 다양한 자료형이 가능하다.
    divided by zero에 유의하자. (signal 8)
    값이 10^18이 넘어가면 sqrt 대신 sqrtl을 생각하자.
*/

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve();
int dfs(int s);

int n, m;

vector<vector<int>> g(501);
int vit[501] = { false };


int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL), std::cout.tie(NULL);

    solve();

    return 0;
}
void solve() {
    cin >> n >> m;
    // 연결요소의 개수 구하기 (무방향)

    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) 
        if (!vit[i])
            ans+=dfs(i);

    cout << ans;
}
int dfs(int s) {
    // bfs
    queue <int> q;
    q.push(s);
    vit[s] = true;

    int cntV = 0, cntE = 0;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        cntV++;

        for (auto i : g[x]) {
            cntE++;
            if (!vit[i])
                vit[i] = true, q.push(i);
        }
            
    }

    if (cntE / 2 != cntV - 1)
        return 0;

    return 1;
}