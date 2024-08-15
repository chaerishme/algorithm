#include <bits/stdc++.h>
using namespace std;
int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> v;
    for (int i = 1; i <= n; i++) v.push_back(i);
    vector<int>::iterator iter = v.begin();

    cout << '<';
    while (v.size () != 1) {
        for (int i = 1; i < k; i++) {
            ++iter;
            if (iter == v.end()) iter = v.begin();
        }
        cout << *iter << ", ";
        iter = v.erase(iter);
        if (iter == v.end()) iter = v.begin();
    }
    cout << *iter << ">\n";
}