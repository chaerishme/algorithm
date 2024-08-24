#include <bits/stdc++.h>
using namespace std;
int N;
int paper[65][65];
void solve(int x, int y, int n) {
    if (n == 1) {
        cout << paper[x][y];
        return;
    }
    
    bool zero = true, one = true;
    for (int i = x; i < x + n; i++) {     // 종이 너비 3의 배수
        for (int j = y; j < y + n; j++){
            if (paper[i][j]) zero = false;
            else one = false;
        }
    }

    if (zero) {
        cout << 0;
        return;
    } else if (one) {
        cout << 1;
        return;
    } else {
        cout << '(';
        solve(x, y, n / 2);
        solve(x, y + n / 2, n / 2);
        solve(x + n / 2, y, n / 2);
        solve(x + n / 2, y + n / 2, n / 2);
        cout << ')';
    }
    return;
}
int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;

        for (int j = 0; j < N; j++)
            paper[i][j] = tmp[j] - '0';
    }

    solve(0, 0, N);
}