#include <bits/stdc++.h>
#include <queue>
using namespace std;
int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    queue<int> q;

    while (t--) {
        string tmp;
        cin >> tmp;
        
        if (tmp == "push") {
            int num;
            cin >> num;
            q.push(num);
        } else if (tmp == "size") cout << q.size() << '\n';
        else if (tmp == "pop") { 
            if (q.empty()) cout << -1 << '\n';
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        } else if (tmp == "empty") {
            if (q.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        } else if (tmp == "front") {
            if (q.empty()) cout << -1 << '\n';
            else {
                cout << q.front() << '\n';
            }
        } else if (tmp == "back") {
            if (q.empty()) cout << -1 << '\n';
            else {
                cout << q.back() << '\n';
            }
        }
    }
}