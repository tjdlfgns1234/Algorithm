#include<bits/stdc++.h>
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define k 347
#define MOD 1000000007
#define INF 987654321
#define ll long long
using namespace std;

int ans = 0;
void solve();

int main() {

	ios::sync_with_stdio(false);
	cin.tie(), cout.tie();

	solve();

	return 0;
}
void solve() {
    string s;
    cin >> s;

    // 길이는 1보다 크거나 같아야 함.
    // 부분 문자열!
    // abc
    // a, b, c, ab, bc, abc  6개
    // O(n^2)

    string tmp = "";
    int n = s.size();
    int ans = 0;
    vector<string> arr;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) // 길이 별로 나누어서 넣음 (중복 방지)
            arr.push_back(s.substr(j, i + 1));

        /*
            한꺼번에 정렬할 경우 50만개 X 평균길이 334 =  약 167.167 MB 소비
            따로 정렬할 경우 최대 334*666 byte = 약 22KB 소비 
            set이나 map으로 구현하는 게 느린 이유
            해시 충돌이 많이 나기 때문!
            알파벳은 26개라서 27개의 문자열을 받게되면 중복이 존재할 수 밖에 없다!
        */

        // 정렬
        sort(all(arr));

        // 중복제거
        arr.erase(unique(all(arr)), arr.end());

        // 답에 추가
        ans += arr.size();

        // 사용한 배열을 비움, 이미 정렬 했던 것을 또 쓸 필요가 없음.
        arr.clear(); 
    }

    std::cout << ans;
}