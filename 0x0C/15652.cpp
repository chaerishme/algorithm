#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[8];
bool isused[8];
void func(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    int start = 1;
    if (k != 0) start = arr[k-1] ;
    for (int i = start; i <= n; i++) {
        arr[k] = i;
        func(k+1);
    }
}
int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    func(0);
}