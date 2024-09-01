#include <bits/stdc++.h>
using namespace std;
char board[12][6];
int result = 0;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
bool vis[12][6];
bool bfs(int x, int y, char c) {
    queue<pair<int,int>> q;
    vector<pair<int,int>> v;
    memset(vis, false, sizeof(vis));
    q.push({x,y});
    v.push_back({x,y});
    vis[x][y] = true;

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir ++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || ny < 0 || nx >= 12 || ny >= 6 || vis[ny][nx]) continue;
            if(board[nx][ny] == c && !vis[nx][ny]){
                q.push({nx,ny});
                v.push_back({nx,ny});
                vis[nx][ny] = true;
            }
        }
    }

    if (v.size() >= 4) {
        int vs = v.size();
        for(int i = 0; i< vs; i++){
            board[v[i].first][v[i].second] = '.';
        }
        return true;
    }
    return false;
}
void down(){
    for(int i = 0; i< 6; i++){
        queue<char> q;
        for(int j = 11; j >= 0; j--){
            if(board[j][i] != '.'){
                q.push(board[j][i]);
            }
        }
        int qs = q.size();
        for(int j = 11; j >= 12-qs; j--){
            board[j][i] = q.front(); q.pop();
        }
        for(int j = 11-qs; j >= 0; j--){
            board[j][i] = '.';
        }
    }
    

}
int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 12; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < 6; j++) {
            board[i][j] = tmp[j];
        }
    }

    while(1){ 
        int flag = 0;
        for(int i = 0; i < 12; i++){
            for(int j = 0; j < 6; j++){
                if(board[i][j] != '.'){
                    if(bfs(i,j,board[i][j])){
                        flag++;
                    }
                }
            }
        }

        if(flag == 0) break;
        else{
            result++;
            down();
        }
    }
    if(result) cout << result << '\n';
    else if(result == 0) cout << 0 << '\n';
}