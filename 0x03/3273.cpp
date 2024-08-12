#include <bits/stdc++.h>
using namespace std;
int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a[1000001] = {0};
    bool check[2000001] = {0};

    int n, x, cnt = 0;

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> x;

    for (int i = 0; i < n; i++) {
        if (x - a[i] > 0 && check[x-a[i]]) cnt++; // x-a[i]가 존재하는지 확인해주어야 함!!
        check[a[i]] =  true;
    }

    cout << cnt << '\n';
}