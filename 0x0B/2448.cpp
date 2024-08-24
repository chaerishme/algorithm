#include <bits/stdc++.h>
using namespace std;
bool draw[3072][6143];
int N;
void tri(int r, int c, int N)
{
    if (N == 3) {
        draw[r][c] = true;
        draw[r+1][c-1] = draw[r+1][c+1] = true;
        for (int i = -2; i < 3; i++) {
            draw[r+2][c+i] = true;
        }
        return;
    }   // 기본 삼각형

    tri(r, c, N/2);
    tri(r + N/2, c - N/2, N/2);
    tri(r + N/2, c + N/2, N/2);

}
int main(void)
{
    cin >> N;    // n = 3 + 2^k, 0 <= k < 10

    tri(0, N-1, N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2 * N - 1; j++) {
            if (draw[i][j]) cout << '*';
            else cout << ' ';
        }
        cout << '\n';
    }
}