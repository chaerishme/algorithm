#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main (void) {
    while (1) {
        stack<char> s;
        string tmp;
        int ans = 1;

        getline(cin, tmp);
        if (tmp == ".") break;

        for (char i : tmp) {
            if (i == '(' || i == '[') s.push(i);
            else if (i == ')') {
                if (!s.empty() && s.top() == '(') s.pop();
                else {
                    ans = 0;
                    break;
                }
            } else if (i == ']') {
                if (!s.empty() && s.top() == '[') s.pop();
                else {
                    ans = 0;
                    break;
                }
            }
        }
        
        if (s.empty() && ans == 1) cout << "yes\n";
        else cout << "no\n";
    }
}
