#include <bits/stdc++.h>
using namespace std;
int N, M, x, y, K;
int Map[20][20];
int move_order[1000];
int dice[6];

int judge(int d) {
	if (d == 1) {
		if (y == M - 1) return 0;
	}
	else if (d == 2) {
		if (y == 0) return 0;
	}
	else if (d == 3) {
		if (x == 0) return 0; 
	}
	else if (d == 4) {
		if (x == N - 1) return 0;
	}
	return 1;
}
void move(int d) {
	int tmp = dice[0];
	if (d == 1) {
		y++;
		dice[0] = dice[3];
		dice[3] = dice[1];
		dice[1] = dice[2];
		dice[2] = tmp;
	}
	else if (d == 2) {
		y--;
		dice[0] = dice[2];
		dice[2] = dice[1];
		dice[1] = dice[3];
		dice[3] = tmp;
	}
	else if (d == 3) {
		x--;
		dice[0] = dice[4];
		dice[4] = dice[1];
		dice[1] = dice[5];
		dice[5] = tmp;
	}
	else if (d == 4) {
		x++;
		dice[0] = dice[5];
		dice[5] = dice[1];
		dice[1] = dice[4];
		dice[4] = tmp;
	}
}
void Play() {
	for (int i = 0; i < K; i++) {
		if (!judge(move_order[i])) {
			continue;
		}

		move(move_order[i]);
		if (Map[x][y] == 0) {
			Map[x][y] = dice[1];
		}
		else {
			dice[1] = Map[x][y];
			Map[x][y] = 0;
		}
		cout << dice[0] << endl;
	}
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];
		}
	}
	for (int i = 0; i < K; i++) 
		cin >> move_order[i];

	Play();
}