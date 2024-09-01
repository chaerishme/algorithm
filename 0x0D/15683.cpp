// 4진법으로 다시 해보기
#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; // 남 동 북 서
int n, m, result = 64;
int board[8][8];
vector<pair<int,int>> cctv;
int blindspot(){
    int cnt = 0;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
            if (board[i][j] == 0) cnt ++;

    return cnt;
}
void change(queue<pair<int,int>> q, int val) {
    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        board[x][y] = val;
    }
}
void dfs(int idx){
    if (idx == cctv.size()) {
        result = min(result, blindspot());
        return;
    }
    int x = cctv[idx].first;
    int y = cctv[idx].second;
    queue<pair<int,int>> q[4];

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        while (0 <= nx && nx < n && 0 <= ny && ny < m && board[nx][ny] != 6) {
            if (board[nx][ny] == 0) q[i].push({nx,ny});
            nx += dx[i];
            ny += dy[i];
        }
    }

    if (board[x][y] == 1) {
        for (int i = 0; i < 4; i++) {
            change(q[i], -1);
            dfs(idx+1);
            change(q[i], 0);
        }
    } 
    else if (board[x][y] == 2) {
        for (int i = 0; i < 3; i += 2) {
            change(q[i], -1);
            change(q[i+1],-1);
            dfs(idx+1);
            change(q[i], 0);
            change(q[i+1], 0);
        }
    } 
    else if (board[x][y] == 3) {
        for (int i = 0; i < 2; i++) {
            change(q[i], -1);
            for (int j = 2; j < 4; j++){
                change(q[j], -1);
                dfs(idx+1);
                change(q[j], 0);
            }
            change(q[i], 0);
        }
    } 
    else if (board[x][y] == 4) {
        for (int i = 0; i < 4; i++) {
            change(q[i], -1);
            change(q[(i+1)%4], -1);
            change(q[(i+2)%4], -1);
            dfs(idx+1);
            change(q[i], 0);
            change(q[(i+1)%4], 0);
            change(q[(i+2)%4], 0);
        }
    }
    else {
        for (int i = 0; i < 4; i++) 
            change(q[i], -1);
        dfs(idx+1);
        for (int i = 0; i < 4; i++)
            change(q[i],0);
    }
}
int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] != 0 && board[i][j] != 6) 
                cctv.push_back({i,j});
        }
    }
    
    dfs(0);
    cout << result << '\n';
}