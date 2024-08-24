#include <bits/stdc++.h>
using namespace std;
int N;
int paper[129][129];
int cnt[2];     // 0은 W, 1은 B
bool check(int x, int y, int n) {
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (paper[x][y] != paper[i][j])
                return false;
        }
    }
    cnt[paper[x][y]] ++;
    return true;
}
void solve(int x, int y, int z) {
    if (check(x, y, z)) return;
    int n = z / 2;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            solve(x + i * n, y + j * n, n);
}
int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> paper[i][j];

    solve(0, 0, N);
    for (int i = 0; i < 2; i++) cout << cnt[i] << '\n';
}