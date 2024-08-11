#include <bits/stdc++.h>
using namespace std;
int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int c;
    cin >> c;
    
    int a[c];
    for (int i = 0; i < c; i++) cin >> a[i];

    int Y = 0, M = 0;
    for (int i = 0; i < c; i++) {
        Y += (a[i] / 30 + 1) * 10;
        M += (a[i] / 60 + 1) * 15;
    }

    if (Y > M) cout << "M " << M << '\n';
    else if (Y == M) cout << "Y M " << M << '\n';
    else cout << "Y " << Y << '\n';
}