#include <bits/stdc++.h>
#include <stack>
using namespace std;
int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<pair<int, int>> s;
    int num, height;

    cin >> num;

    for (int i = 1; i <= num; i++) {
        cin >> height;
    
        while (!s.empty()) {
            if(s.top().second > height) {
                cout << s.top().first << ' ';
                break;
            }
            s.pop();
        }

        if (s.empty()) cout << 0 << ' ';
        s.push(make_pair(i, height));
    }
}