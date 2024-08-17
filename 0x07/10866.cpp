#include <bits/stdc++.h>
#include <deque>
using namespace std;
int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    deque<int> dq;

    while (t--) {
        string tmp;
        cin >> tmp;
        
        if (tmp == "push_front") {
            int num;
            cin >> num;
            dq.push_front(num);
        } else if (tmp == "push_back") {
            int num;
            cin >> num;
            dq.push_back(num);
        } else if (tmp == "size") cout << dq.size() << '\n';
        else if (tmp == "pop_front") { 
            if (dq.empty()) cout << -1 << '\n';
            else {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        } else if (tmp == "pop_back") { 
            if (dq.empty()) cout << -1 << '\n';
            else {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
        else if (tmp == "empty") {
            if (dq.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        } else if (tmp == "front") {
            if (dq.empty()) cout << -1 << '\n';
            else {
                cout << dq.front() << '\n';
            }
        } else if (tmp == "back") {
            if (dq.empty()) cout << -1 << '\n';
            else {
                cout << dq.back() << '\n';
            }
        }
    }
}