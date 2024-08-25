#include <bits/stdc++.h>
using namespace std;
int N, S;
int cnt = 0;
int a[21];
void func(int cur, int tot) {
    if (cur == N) {
        if (tot == S) cnt ++;
        return;
    }
    func(cur + 1, tot);             // 현재 숫자 고려 X
    func(cur + 1, tot + a[cur]);    // 현재 숫자 고려 
}
int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;
    
    for (int i = 0; i < N; i++) 
        cin >> a[i];
    
    func(0,0); 
    if (S == 0) cnt--;      // 공집합 처리
    cout << cnt << '\n';
}
