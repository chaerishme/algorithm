// 너무 어렵다....
#include <bits/stdc++.h>
using namespace std;
bool vis[5][5];
char board[5][5];
int dx[4] = {1, 0 ,-1, 0};
int dy[4] = {0, 1, 0, -1};
int result, cnt;
vector<pair<int, int>> selected;    // 선택한 자리 
bool check(vector<pair<int, int>>& selected) {
    memset(vis, 0, sizeof(vis));
    queue<pair<int, int>> Q;
    Q.push(selected[0]);
    vis[selected[0].first][selected[0].second] = true;

    cnt = 1;

    while (!Q.empty()) {
        auto [x, y] = Q.front(); Q.pop();
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
            
            // 선택된 학생 중 방문하지 않은 학생이 있으면 큐에 추가
            if (!vis[nx][ny] && find(selected.begin(), selected.end(), make_pair(nx, ny)) != selected.end()) {
                vis[nx][ny] = true;
                Q.push({nx, ny});
                cnt++;
            }
        }
    }
    return cnt == 7;
}
void func(int idx, int S_cnt) {
    if (selected.size() == 7) {
        if (S_cnt >= 4 && check(selected)) {
            result++;
        }
        return;
    }
    for (int i = idx; i < 25; i++) {    // 1차원으로 2차원 배열 나타낼 수 있음
        int x = i / 5;
        int y = i % 5;

        selected.push_back({x,y});
        func(i + 1, S_cnt + (board[x][y] == 'S' ? 1 : 0));
        selected.pop_back();
    }
}
int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++) {
        string tmp;
        cin >> tmp;

        for (int j = 0; j < 5; j++) 
            board[i][j] = tmp[j];
    }

    func(0, 0);
    cout << result << '\n';

}