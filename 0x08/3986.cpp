#include <bits/stdc++.h>
#include <stack>
using namespace std;
int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, cnt = 0;
    string tmp;
    cin >> n;

    while (n--) {
        stack<char> s;
        cin >> tmp;

        for (char i : tmp) {
            if (s.empty()) {s.push(i);}
            else {
                if (s.top() == i) s.pop();
                else s.push(i);   
            }
        }

        if (s.empty()) cnt ++;
    }

    cout << cnt << '\n';
}