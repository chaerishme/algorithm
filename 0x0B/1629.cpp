// 모듈러 거듭제곱 계산, 분할 정복 사용
// 시간 복잡도 O(log b)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll rec(ll a, ll b, ll c) {
    if (b == 1) return a % c;       // base condition
    ll tmp = rec(a, b/2, c);
    tmp = tmp * tmp % c;
    if (b % 2 == 0) return tmp;
    return tmp * a % c;
}
int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll a, b, c;
    cin >> a >> b >> c;
    cout << rec(a,b,c) << '\n';
}
