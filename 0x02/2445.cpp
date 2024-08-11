#include <bits/stdc++.h>
using namespace std;
int main (void) {
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) cout << '*';
        for (int k = n - i; k > 0; k--) cout << "  ";
        for (int l = 1; l <= i; l++) cout << '*';
        cout << '\n';
    }
    for (int i = n-1; i >= 0; i--) {
        for (int j = 1; j <= i; j++) cout << '*';
        for (int k = n - i; k > 0; k--) cout << "  ";
        for (int l = 1; l <= i; l++) cout << '*';
        cout << '\n';
    }
}