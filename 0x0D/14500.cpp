#include <bits/stdc++.h>
#include<algorithm>
#include<cstring>
using namespace std;
void getMaxNum(int x, int y, int cnt, int curScore);
int board[501][501];
bool vis[501][501];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int N, M, ans = 0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(vis, 0, sizeof(vis));
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j=1; j<=M; j++){
            cin >> board[i][j];
        }
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            vis[i][j] = 1;
            getMaxNum(i, j, 1, board[i][j]);
            vis[i][j] = 0;
        }
    }
    
    cout << ans << '\n';
}
void getMaxNum(int x, int y, int cnt, int curScore){
    if(cnt == 4) {
        if(ans < curScore) ans = curScore;
        return;
    }

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 1 || ny < 1 || nx > N || ny > M || vis[nx][ny]) continue;
        vis[nx][ny] = 1;
        getMaxNum(nx, ny, cnt + 1, curScore + board[nx][ny]);
        vis[nx][ny] = 0;
    }

    if(x-1 >= 1 && y-1 >= 1 && x+1 <= N) { //ㅓ
        ans = max(ans, (board[x-1][y] + board[x][y-1] + board[x][y] + board[x+1][y]));
    }
    if(x-1 >= 1 && y+1 <= M && x+1 <= N) { //ㅏ
        ans = max(ans, (board[x-1][y] + board[x][y+1] + board[x][y] + board[x+1][y]));
    }
    if(y-1 >= 1 && y+1 <= M && x+1 <= N) { //ㅗ
        ans = max(ans, (board[x][y] + board[x+1][y] + board[x+1][y-1] + board[x+1][y+1]));
    }
    if(y-1 >= 1 && y+1 <= M && x+1 <= N) { //ㅜ
        ans = max(ans, (board[x][y-1] + board[x][y] + board[x][y+1] + board[x+1][y]));
    }

}