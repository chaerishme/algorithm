#include <bits/stdc++.h>
using namespace std;
vector<int> v;
vector<int> result;
int k;
void tmp(int start, int cnt) {
    if (cnt == 6) {
        for (int i = 0; i < 6; i++)
            cout << result[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = start; i < k; i++) {
        result[cnt] = v[i];
        tmp(i+1, cnt+1);
    }
}
int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        cin >> k;
        if (k == 0) break;

        v.clear();
        result.resize(6,0);

        for (int i = 0; i < k; i++) {
            int tmp;
            cin >> tmp;
            v.push_back(tmp);
        }

        tmp(0,0);
        cout << '\n';
    }
}