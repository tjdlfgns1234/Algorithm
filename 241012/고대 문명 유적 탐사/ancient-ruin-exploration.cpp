#include <bits/stdc++.h>
using namespace std;

int k,m;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int deg[3] = {90,180,270};
int idx = 0; // 벽면에 써져 있는 유물 인덱스

int arr[5][5] = {0};
int chk[5][5] = {0}; // 회전후 배열 복사
int chk2[5][5] = {0}; // 방문 확인
int treasure[301] = {0};

int ans = 0; // 유물 가치의 합
int ax = 0,ay = 0, v = 0,d = 360; // x,y 좌표 및 값, 각도

void explore(); // 탐사 진행
void rotate_(int x, int y,int degree); // 회전하는 함수
void remove(); // 3조각 이상의 유물을 제거하는 함수
void add_t(); // 벽면에 써져있는 숫자를 추가
int calc(); // 유물을 계산하는 함수
void compare_(int x1,int y2,int v2,int d2);
void solve();

int main() {
  
    ios::sync_with_stdio(NULL);
    cin.tie(NULL),cout.tie(NULL);

    solve();

    return 0;
}
void solve(){
    cin >> k >> m;

    for(int i = 0; i < 5;i++)
        for(int j = 0; j < 5;j++)
            cin >> arr[i][j];

    for(int i = 0; i < m;i++) cin >> treasure[i];
    while(k--)
        explore();
}
void explore(){
    // 선택
    ans = 0, ax = 0,ay = 0, v = 0,d = 360;
    for(int i = 1;i <=3;i++)
        for(int j = 1; j <= 3; j++){
            rotate_(i,j,deg[0]);
            int cost2 = calc();
            compare_(i,j,cost2,deg[0]);

            rotate_(i,j,deg[1]);
            cost2 = calc();
            compare_(i,j,cost2,deg[1]);

            rotate_(i,j,deg[2]);
            cost2 = calc();
            compare_(i,j,cost2,deg[2]);
        }
        
    // 디버그
    //cout << ax << ' ' << ay << ' ' << v << " " << d << '\n';

    rotate_(ax,ay,d); // 앞서 구한 값을 계산
    ans += v;
    for(int i = 0; i<5;i++)
        for(int j = 0; j < 5;j++)
            arr[i][j] = chk[i][j];

    // cout << '\n';
    // for(int i = 0; i<5;i++){
    //     for(int j = 0; j < 5;j++)
    //         cout << chk[i][j] << ' ';
    //     cout << '\n';
    // }
    // cout << calc();
    // cout << '\n';

    remove(); // 값 제거
    add_t(); // 값 채우기

    for(int i = 0; i<5;i++)
        for(int j = 0; j < 5;j++)
            chk[i][j] = arr[i][j];

    int tmp = calc();
    while(tmp!= 0){ // 변화가 있으면
        ans+= tmp;
        remove(); // 값 제거
        add_t();
        for(int i = 0; i<5;i++)
            for(int j = 0; j < 5;j++)
                chk[i][j] = arr[i][j];

        tmp = calc();

    }

    // for(int i = 0; i<5;i++){
    //     for(int j = 0; j < 5;j++)
    //         cout << arr[i][j] << ' ';
    //     cout << '\n';
    // }


    if(ans == 0){
        k = 0;
        return;
    }

    cout << ans << ' ';

}
void rotate_(int x, int y,int degree){ 
    // 중앙점 좌표 및 돌릴 각도
    // 회전하는 함수
    // 회전 후 결과를 chk 배열에 저장
    int tmp[3][3] = {0};
    tmp[1][1] = arr[x][y];

    if(degree == 90){
        tmp[0][0] = arr[x+1][y-1];
        tmp[0][1] = arr[x][y-1];
        tmp[0][2] = arr[x-1][y-1];

        tmp[1][0] = arr[x+1][y];
        tmp[1][2] = arr[x-1][y];

        tmp[2][0] = arr[x+1][y+1];
        tmp[2][1] = arr[x][y+1];
        tmp[2][2] = arr[x-1][y+1];
    }
    else if(degree == 180){
        tmp[0][0] = arr[x+1][y+1];
        tmp[0][1] = arr[x+1][y];
        tmp[0][2] = arr[x+1][y-1];

        tmp[1][0] = arr[x][y+1];
        tmp[1][2] = arr[x][y-1];

        tmp[2][0] = arr[x-1][y+1];
        tmp[2][1] = arr[x-1][y];
        tmp[2][2] = arr[x-1][y-1];
    }
    else if(degree = 270){
        tmp[0][0] = arr[x-1][y+1];
        tmp[0][1] = arr[x][y+1];
        tmp[0][2] = arr[x+1][y+1];

        tmp[1][0] = arr[x-1][y];
        tmp[1][2] = arr[x+1][y];

        tmp[2][0] = arr[x-1][y-1];
        tmp[2][1] = arr[x][y-1];
        tmp[2][2] = arr[x+1][y-1];
    }
    for(int i = 0; i < 5;i++)
        for(int j = 0; j < 5;j++)
            chk[i][j] = arr[i][j];

    for(int i = x-1, q = 0; i <=x+1&& q< 3 ;i++,q++)
        for(int j = y-1, p = 0; j<=y+1 && p < 3;j++,p++)
            chk[i][j] = tmp[q][p];

}
int calc(){
    // 유물의 가치를 확인한다.
    memset(chk2,0,sizeof(chk2));
    queue <pair<int,int>> q; 

    int value = 0, num = -1; // 현재 유물
    for(int i = 0; i < 5;i++)
        for(int j = 0; j < 5;j++){
            int x,y,cnt = 0; // x, y
            if(chk2[i][j] == 0)
                q.push({i,j}), num = chk[i][j], chk2[i][j] = 1, cnt =1;
            else 
                continue;

            while(!q.empty()){
                tie(x,y) = q.front();
                q.pop();

                for(int k = 0; k < 4;k++){
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if(nx >= 5 || nx <0 || ny >=5 || ny < 0 || chk2[nx][ny]!= 0 || chk[nx][ny] != num)
                        continue;
                    cnt++;
                    chk2[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }

            if(cnt >=3){
                // cout << i << ' ' << j << " " << chk[i][j] << '\n';
                value += cnt;
            }
        }

    return value;
}
void remove(){ // 3조각 이상의 유물을 제거하는 함수
    // 빈 공간은 0로 표시
    // 제거 후에도 3개이상 연결가능
    // 이때는 회전 없이 3개 이상을 제거해야함.

    memset(chk2,0,sizeof(chk2));
    queue <pair<int,int>> q,q2; 
    int x,y;
    int value = 0, num = 0; // 현재 유물
    for(int i = 0; i < 5;i++)
        for(int j = 0; j < 5;j++){
            
            if(chk2[i][j] == 0)
                q.push({i,j}), num = arr[i][j], chk2[i][j] = 1;

            int cnt = 1; // x, y
            while(!q.empty()){
                tie(x,y) = q.front();
                q.pop();

                for(int k = 0; k < 4;k++){
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if(nx >= 5 || nx <0 || ny >=5 || ny < 0 || chk2[nx][ny]!= 0 || arr[nx][ny] != num)
                        continue;
                    cnt++;
                    if(cnt == 3) // 3개 일 경우
                        q2.push({nx,ny}); // 3게 이상인 점의 좌표를 저장
                    
                    chk2[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }
        }

        memset(chk2,0,sizeof(chk2));
        while(!q2.empty()){
            q.push(q2.front()), q2.pop();
            tie(x,y) = q.front();
            chk2[x][y] = 1, num = arr[x][y], arr[x][y] = 0;
            while(!q.empty()){
                tie(x,y) = q.front();
                q.pop();

                for(int k = 0; k < 4;k++){
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if(nx >= 5 || nx <0 || ny >=5 || ny < 0 || chk2[nx][ny]!= 0 || arr[nx][ny] != num)
                        continue;

                    arr[nx][ny] = 0; // 비움
                    chk2[nx][ny]= 1; // 방문 표시
                    q.push({nx,ny});
                }
            }
        }
}
void add_t(){ 
    // 벽면에 써져있는 숫자를 추가
    // 열 번호가 같다면 행 번호가 큰순으로 조각이 생김
    // cout << idx << '\n';
    for(int i = 0; i < 5;i++)
        for(int j = 4; j >= 0;j--)
            if(arr[j][i] == 0 && idx < m)
                arr[j][i] = treasure[idx++];
 
}
void compare_(int x2,int y2,int v2,int d2){
    if(v < v2)
            v = v2, ax = x2, ay = y2, d = d2;
    else if(v == v2)
        if(d > d2)
            v = v2, ax = x2, ay = y2, d = d2;
        else if(d == d2)
            if(ax < x2)
                v = v2, ax = x2, ay = y2, d = d2;
            else if(ax == x2)
                if(ay > y2)
                    v = v2, ax = x2, ay = y2, d = d2;
}