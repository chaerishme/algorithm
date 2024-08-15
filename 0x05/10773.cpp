#include <bits/stdc++.h>
#include <stack>
using namespace std;
int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> list;
    int N, num, sum = 0;

    cin >> N;
    while (N--) {
        cin >> num;
        if (num == 0) 
            list.pop();
        else 
            list.push(num);
    }

    int size = list.size();
    for (int i = 0; i < size; i++) {
        sum += list.top();
        list.pop();
    }

    cout << sum << endl;
}