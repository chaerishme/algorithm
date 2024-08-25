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
    if (k != 0) start = arr[k-1] + 1;
    for (int i = start; i <= n; i++) {
        if (!isused[i]) {
            arr[k] = i;
            isused[i] = 1;
            func(k+1);
            isused[i] = 0;  // func(k+1) 모든 과정 끝났으므로 사용되지 않았음 표시
        }
    }
}
int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    func(0);
}