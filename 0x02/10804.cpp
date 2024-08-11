#include <bits/stdc++.h>
using namespace std;
int main (void) {
    int a[21] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int b, c, n = 10;

    while (n--) {
        cin >> b >> c;
        reverse(a + b, a + c + 1);
    }

    for (int i = 1; i < 21; i++) {
        cout << a[i] << ' ';
    }
}