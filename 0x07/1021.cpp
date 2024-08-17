#include <bits/stdc++.h>
#include <deque>
using namespace std;
int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n, cnt = 0;
    cin >> t >> n;

    deque<int> dq;
    
    for (int i = 1; i <= t; i++) dq.push_back(i);

    while (n--) {
        int val, idx;
        cin >> val;

        if (dq.front() == val) {
            dq.pop_front();
            continue;
        } 

        for (int i = 0; i < dq.size(); i++) {
            if (dq[i] == val) {
                idx = i;
                break;
            }
        }

        if (idx <= dq.size() / 2) { // 왼쪽에 위치 
            while (1) {
                if (dq.front() == val) {
                    dq.pop_front();
                    break;
                } 
                dq.push_back(dq.front());
                dq.pop_front();
                cnt++;
            }
        }  else {
            while (1) {
                if (dq.front() == val) {
                    dq.pop_front();
                    break;
                } 
                dq.push_front(dq.back());
                dq.pop_back();
                cnt++;
            }
        }
    }

    cout << cnt << '\n';
}