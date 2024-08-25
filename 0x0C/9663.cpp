#include <bits/stdc++.h>
using namespace std;
int N;
int cnt = 0;
bool isused1[15];   // 열
bool isused2[29];   // / 대각선
bool isused3[29];   // \ 대각선
void func(int cur) {
    if (cur == N) {
        cnt ++;
        return;
    }
    for (int i = 0; i < N; i++) {
        if (isused1[i] || isused2[i+cur] || isused3[cur-i+N-1]) continue;
        isused1[i] = true;
        isused2[i+cur] = true;
        isused3[cur-i+N-1] = true;
        func(cur+1);
        isused1[i] = false;
        isused2[i+cur] = false;
        isused3[cur-i+N-1] = false;
    }

}
int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    func(0);
    cout << cnt;
}