#include <bits/stdc++.h>
using namespace std;
int N;
void star(int r, int c, int N)
{
    if ((r / N) % 3 == 1 && (c / N) % 3 == 1) cout << " ";  // 중간 부분이면 빈칸 출력
    else {
        if (N / 3 == 0) cout << '*';
        else star(r, c, N/3);
    }
}
int main(void)
{
    int r,c, n;
    cin >> N;    // n = 3^k, 1 <= k < 8

    for (r = 0; r < N; r++) {
        for (c = 0; c < N; c++){
            star(r, c, N);
        }
        cout << '\n';
    }
}