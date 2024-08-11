#include <bits/stdc++.h>
using namespace std;
int main (void) {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) cout << ' ';
        for (int k = (n - i) * 2 - 1; k > 0; k--) cout << "*";
        cout << '\n';
    }
    for (int i = n - 1; i > 0; i--) {
        for (int j = 1; j < i; j++) cout << ' ';
        for (int k = (n - i) * 2; k >= 0; k--) cout << "*";
        cout << '\n';
    }
}