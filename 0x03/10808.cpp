#include <bits/stdc++.h>
using namespace std;
int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a[26] = {0};
    string s;

    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        a[s[i] - 'a'] ++;
    }

    for (int i = 0; i < 26; i++) {
        cout << a[i] << ' ';
    }
}