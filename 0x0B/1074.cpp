#include <bits/stdc++.h>
using namespace std;
int N, r, c, cnt;
int find (int a, int x, int y) {
    int n = pow(2,a-1);
    int num = n * n;
    if (x < n && y < n){

    } else if (x < n && y >= n) {
        cnt += num;
        y -= n;
    } else if (x >= n && y < n) {
        cnt += num * 2;
        x -= n;
    } else {
        cnt += num * 3;
        x -= n;
        y -= n;
    }
    
    if (a == 1) return cnt;

    return find(a-1, x, y);
}
int main (void) {
    cin >> N >> r >> c;

    int result = find(N, r, c); 
    cout << result << '\n';
}