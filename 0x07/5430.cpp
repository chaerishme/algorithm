#include <bits/stdc++.h>
#include <deque>
#include <algorithm>
#include <string>
using namespace std;
int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, n;
    string p, a;

    cin >> x;
    while (x--) {
        bool avail = true, dir = true;
        string tmp = "";
        deque<int> dq;

        cin >> p >> n >> a;

        for (int i = 1; i < a.size(); i++) {
            if (a[i] == ',' || a[i] == ']') {
                if (tmp != "") {
                    dq.push_back(stoi(tmp));
                    tmp = "";
                }
            } else {
                tmp += a[i];
            }
        }
        
        for (int i = 0; i < p.size(); i++) {
            if (p[i] == 'R') dir = !dir;
            else if (p[i] == 'D') {
                if (dq.empty()) {
                    avail = false;
                    break;
                } else {
                    if (dir) dq.pop_front();
                    else dq.pop_back();
                }
            }
        }

        if (!avail) cout << "error\n";
        else {
            if (!dir) reverse(dq.begin(), dq.end());
            cout << '['; 
            for (int i = 0; i < dq.size(); i++) {
                cout << dq[i];
                if (i < dq.size() -1) cout << ',';
            }
            cout << "]\n";
        }
    }
}
