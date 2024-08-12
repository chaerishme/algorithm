#include <bits/stdc++.h>
using namespace std;
int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string n;
    cin >> n;
    int a[9] = {0}, max = 0;

    for (char c : n) {
        if (c == '9') a[6]++;
        else a[c - '0']++;
    }
    
    for (int i : a)
        if (i >= max) max = i;
        
    if (max == a[6]){
        for (int i = 0; i < 9; i++) {
            if (i == 6) continue;
            if (a[i] == max) {
                cout << max << '\n';
                return 0;
            }
        }
        if (max % 2 == 1) cout << max / 2 + 1 << '\n';
        else cout << max / 2 << '\n';
    } else cout << max << '\n';
}