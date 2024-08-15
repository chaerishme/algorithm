#include <bits/stdc++.h>
#include <stack>
using namespace std;
int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    stack<int> s;

    while (t--) {
        string tmp;
        cin >> tmp;
        
        if (tmp == "push") {
            int num;
            cin >> num;

            s.push(num);
        } else if (tmp == "top") {
            if (s.empty()) cout << -1 << '\n';
            else cout << s.top() << '\n';}
        else if (tmp == "size") cout << s.size() << '\n';
        else if (tmp == "pop") { 
            if (s.empty()) cout << -1 << '\n';
            else {
                cout << s.top() << '\n';
                s.pop();
            }
        } else if (tmp == "empty") {
            if (s.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
    }
}