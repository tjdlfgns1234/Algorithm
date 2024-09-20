#include <bits/stdc++.h>
using namespace std;


int n;
vector<tuple<int,int,int>> arr;

void solve();

int main() {
    solve();

    return 0;
}
void solve(){
    cin >> n;
    
    int a, b;
    for(int i = 0; i < n;i++){
        cin >> a >> b;

        arr.push_back({a,+1,i});
        arr.push_back({b,-1,i});
    }
    
    sort(arr.begin(), arr.end());

    unordered_set<int> segs;

    int ans =0;

    for(int i = 0; i < 2*n;i++){
        int x,v,idx;
        tie(x,v,idx) = arr[i];

        if(v == +1){
            if((int)segs.size() == 0)
                ans++;

            segs.insert(idx);
        }
        else
            segs.erase(idx);
    }

    cout << ans;


}