#include <bits/stdc++.h>
using namespace std;
int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a, b, c, arr[10] = {0};
    string result;

    cin >> a >> b >> c;

    result = to_string(a*b*c);

    for (char ch : result)
        arr[ch - '0'] ++;

    for (int cnt : arr) 
        cout << cnt << '\n';
}