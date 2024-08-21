#include <bits/stdc++.h>
#include <stack>
using namespace std;
int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string tmp;
    cin >> tmp;

    stack<char> s;
    int cnt = 0;

    for (int i = 0; i < tmp.size(); i++) {
        if (tmp[i] == '(' && tmp[i+1] == ')') {
            cnt += s.size();
            i++;
        } else if (tmp[i] == '(') s.push(i);
        else if (tmp[i] == ')') {
            s.pop();
            cnt ++;
        }
    }

    cout << cnt;
}