#include <bits/stdc++.h>
using namespace std;
int N, MAX;
int s[8];   // 내구도
int w[8];   // 무게
int cnt = 0;    // 계란 개수
void solve(int a) {
    if (a == N) {
        MAX = max(MAX, cnt);
        return;
    }
    if (s[a] <= 0 || cnt == N-1) { // 다음 꺼 깨져있거나 모든 계란 깨져있으면 pass 
        solve(a+1);
        return;
    }
    for (int i = 0; i < N; i++) {   // 현재 계란 a, 든 계란 i
        if (i == a || s[i] <= 0) continue; // 자기 자신 또는 깨려는 계란 깨져있으면 pass
        s[a] -= w[i];
        s[i] -= w[a];
        if (s[a] <= 0) cnt++;
        if (s[i] <= 0) cnt++;
        solve(a+1);
        // 과정 끝났으므로 복구
        if (s[a] <= 0) cnt--;
        if (s[i] <= 0) cnt--;
        s[a] += w[i];
        s[i] += w[a];
    }
}
int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> s[i] >> w[i];
    
    solve(0);
    cout << MAX << '\n';
}