#include <bits/stdc++.h>
#include <deque>
#include <vector>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
deque<pair<int, int>> dq;
vector<pair<int, char>> dir;
int board[100][100];
bool check[100][100];
int n, k, x, y, l, m;
char c;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> n >> k;

    for(int i = 0; i < k; i++){
        cin >> x >> y;
        board[x - 1][y - 1] = 1;
    }

    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> l >> c;
        dir.push_back(make_pair(l, c));
    }

	int dir_idx = 0;
	int time = 0;
	int cx = 0;
	int cy = 0;
	dq.push_front(make_pair(0, 0));
	check[0][0] = true;
	int idx = 0;
	while(1) {
		time++;
		int nx, ny;
		nx = cx + dx[dir_idx];
		ny = cy + dy[dir_idx];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n || check[nx][ny] == true) {
			break;
		}
		cx = nx;
		cy = ny;
		check[nx][ny] = true;
		dq.push_front(make_pair(nx, ny));
		if (board[nx][ny] == 0) {
			int tx = dq.back().first;
			int ty = dq.back().second;
			check[tx][ty] = false;
			dq.pop_back();
		} else {
			board[nx][ny] = 0;
		}

		if(time == dir[idx].first) {
			if (dir[idx].second == 'D') {
				dir_idx++;
				if (dir_idx > 3)
					dir_idx = 0;
			} else {
				dir_idx--;
				if (dir_idx < 0)
					dir_idx = 3;
			}
			idx++;
		}
	}
	cout << time << '\n';

	return 0;
}