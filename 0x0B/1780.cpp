#include <bits/stdc++.h>
using namespace std;
int N;
int paper[2190][2190];
int num[3]; // -1 0 1 개수 저장
bool check(int x, int y, int n) {
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (paper[x][y] != paper[i][j])
                return false;
        }
    }
    return true;
}
void solve(int x, int y, int z) {
    if (check(x, y, z)) {
        num[paper[x][y] + 1] += 1;
        return;
    }
    int n = z / 3;      // 종이 사이즈 수정
    for (int i = 0; i < 3; i++)      // 종이 너비 3의 배수
        for (int j = 0; j < 3; j++)
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
    for (int i = 0; i < 3; i++) cout << num[i] << '\n';
}