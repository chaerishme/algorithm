#include <bits/stdc++.h>
using namespace std;
int main (void) {
    int a[9], tmp, idx, max = 0;

    for (int i = 1; i < 10; i++) {
        cin >> tmp;
        if (tmp > max) {
            max = tmp;
            idx = i;
        }
    }

    cout << max << '\n' << idx;
}