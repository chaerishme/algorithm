#include <bits/stdc++.h>
using namespace std;
int n, m;
int num[8];
int arr[8];
bool isused[8];
void func(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++)
            cout << num[arr[i]] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        arr[k] = i;
        func(k+1);
    }
}
int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) 
        cin >> num[i];
    
    sort(num, num+n);
    func(0);
}