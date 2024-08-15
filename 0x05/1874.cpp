#include <bits/stdc++.h>
#include <stack>
using namespace std;
int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> s;
    vector<char> op;
    
    int n, cnt = 1;
    cin >> n;

    while (n--) {
        int num;
        cin >> num;

        while (cnt <= num) {
            s.push(cnt++);
            op.push_back('+');
        }

        if (s.top() == num) {
            s.pop();
            op.push_back('-');
        } else {
            cout << "NO" << '\n';
            return 0;
        }
    }

    for (int i = 0; i < op.size(); i++)
        cout << op[i] << '\n';
}