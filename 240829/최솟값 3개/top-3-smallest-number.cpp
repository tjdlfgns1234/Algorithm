#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;

int main() {
    cin >> n;

    priority_queue <int> pq;
    int tmp;
    while(n--){
        cin >> tmp;

        pq.push(-tmp);

        if(pq.size() <=2)
            cout << -1 << '\n';
        else{

            ll sum = 1;
            ll arr[3] = {0};
            for(int i = 0; i < 3;i++)
                sum*=-pq.top(),arr[i] = pq.top(),pq.pop();
            for(int i = 0; i < 3;i++)
                pq.push(arr[i]);
            cout << sum << '\n';

        }



    }





    return 0;
}