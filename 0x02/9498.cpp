#include <bits/stdc++.h>
using namespace std;
int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int s;
    cin >> s;

    if (s > 89) cout << 'A';
    else if (s > 79) cout << 'B';
    else if (s > 69) cout << 'C';
    else if (s > 59) cout << 'D';
    else cout << 'F';

}