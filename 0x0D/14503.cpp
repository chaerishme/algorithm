#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int n, m, cnt = 0;
int board[50][50];
bool vis[50][50];
int r, c, d;
vector<pair<int,int>> cctv;
void dfs() {
    for (int i = 0; i < 4; i++) {
        int next_d = (d + 3 - i) % 4;
        int next_r = r + dx[next_d];
        int next_c = c + dy[next_d];

        if (next_r < 0 || next_r >= n || next_c < 0 || next_c >= m || board[next_r][next_c] == 1) continue;

        if (board[next_r][next_c] == 0 && vis[next_r][next_c] == false)
        {
            vis[next_r][next_c] = true;
            r = next_r;
            c = next_c;
            d = next_d;
            cnt ++;
            dfs();
        }
    }

    int back_idx = d > 1 ? d - 2 : d + 2;
    int back_r = r + dx[back_idx];
    int back_c = c + dy[back_idx];

    if (back_r >= 0 && back_r <= n || back_c >= 0 || back_c <= m)
    {
        if (board[back_r][back_c] == 0){
            r = back_r;
            c = back_c;
            dfs();
        }
        else {
            cout << cnt << '\n';
            exit(0);
        }
    }
}
int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> r >> c >> d;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
        
    memset(vis, false, sizeof(vis));
    
    vis[r][c] = true;
    cnt ++;

    dfs();
}