#include <bits/stdc++.h>
using namespace std;
int main (void) {
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        for (int k = n - i; k > 0; k--) 
            cout << ' ';
        for (int j = 0; j < i; j++)
            cout << "*"; 
        cout << '\n';
    }
}