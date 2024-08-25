#include <bits/stdc++.h>
using namespace std;
int n, m;
int num[8];
int arr[8];
bool isused[8];
void func(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    int tmp = 0;
    for (int i = 0; i < n; i++) {
        if (!isused[i] && tmp != num[i]) {
            arr[k] = num[i];
            isused[i] = 1;
            tmp = arr[k];
            func(k+1);
            isused[i] = 0;
        }
    }
}
int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) 
        cin >> num[i];
    
    // 벡터로 중복 제거해보려 했는데 제대로 동작하지 않음...
    sort(num, num+n);
    func(0);
}