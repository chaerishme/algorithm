#include <bits/stdc++.h>
#include <queue>
#include <algorithm>
using namespace std;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int n, m;
int c = 0;
int board[8][8];
int tmp[8][8];
 
void copy(int (*a)[8], int (*b)[8]){
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            a[i][j] = b[i][j];
} 
 
void bfs(){
    int spread[8][8];
    copy(spread, tmp);
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (spread[i][j] == 2)
                q.push(make_pair(i, j));    
 
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(0<=nx && nx<n && 0<=ny && ny<m){
                if(spread[nx][ny] == 0){
                    spread[nx][ny] = 2;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(spread[i][j] == 0)
                cnt += 1;
        }
    }
    c = max(c, cnt);
}
 
void wall(int cnt){
    if(cnt == 3){
        bfs();
        return;
    }
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            if(tmp[i][j]==0){
                tmp[i][j] = 1;
                wall(cnt + 1);
                tmp[i][j] = 0;
            }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
 
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(board[i][j] == 0){
                copy(tmp, board);
                tmp[i][j] = 1;
                wall(1);
                tmp[i][j] = 0;
            }
        }
    }
    cout << c << '\n';
 
}
