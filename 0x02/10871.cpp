#include <bits/stdc++.h>
using namespace std;
int main (void) {
    ios::sync_with_stdio(0);
    int n, x, i;
    cin >> n >> x;

    while (n--) {
        cin >> i;
        if (i < x) cout << i << " ";
    }  
}
