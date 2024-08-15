//STL list 사용
#include <bits/stdc++.h>
using namespace std;
int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int m;

    cin >> s >> m;

    list<char> a(s.begin(), s.end());
    list<char>::iterator iter = a.end(); 

    while (m--) {
        char tmp;
        cin >> tmp;

        if (tmp == 'L') {
            if (iter != a.begin()) iter--;
        } else if (tmp == 'D') {
            if (iter != a.end()) iter++;
        } else if (tmp == 'B') {
            if (iter != a.begin()) iter = a.erase(--iter);
        } else if (tmp == 'P') {
            char tmp2;
            cin >> tmp2;
            a.insert(iter, tmp2);
        }
    }

    for (iter = a.begin(); iter != a.end(); iter++)
        cout << *iter;
}