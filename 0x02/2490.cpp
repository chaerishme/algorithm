#include <bits/stdc++.h>
using namespace std;
int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a;

    for (int i = 0; i < 3; i++) {
        int cnt = 0;

        for (int j = 0; j < 4; j++) {
            cin >> a;
            if (a == 0) cnt ++;
        }
        if (cnt == 1) cout << 'A';
        else if (cnt == 2) cout << 'B';
        else if (cnt == 3) cout << 'C';
        else if (cnt == 4) cout << 'D';
        else cout << 'E';

        cout << '\n';
    }
}