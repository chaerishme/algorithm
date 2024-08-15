//STL list 사용
#include <bits/stdc++.h>
using namespace std;
int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m;
    cin >> m;

    while (m--) {
        string s;
        cin >> s;

        list<char> a(s.begin(), s.end());
        list<char>::iterator iter;
        list<char> result;
        list<char>::iterator iter2 = result.begin();
        
        for (iter = a.begin(); iter != a.end(); iter++) {
            if (*iter == '<') {
                if (iter2 != result.begin()) iter2--;
            } else if (*iter == '>') {
                if (iter2 != result.end()) iter2++;
            } else if (*iter == '-') {
                if (iter2 != result.begin()) iter2 = result.erase(--iter2);
            } else {
                char tmp2 = *iter;
                result.insert(iter2, tmp2);
            }
        }

        for (iter2 = result.begin(); iter2 != result.end(); iter2++)
            cout << *iter2;

        cout << '\n';
    }

}