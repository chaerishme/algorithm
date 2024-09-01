#include <bits/stdc++.h>
using namespace std;
int n;
int operands[11]; // 수열 
int operators[4]; // 연산자의 개수
int mymin = 1000000001;
int mymax = -1000000001;
void getanswer(int result, int idx)
{
    if(idx == n)
    {
        if(result > mymax)
            mymax = result;
        if(result < mymin)
            mymin = result;
        return;
    }
    for(int i = 0; i < 4; i++)
    {
        if(operators[i] > 0)
        {
            operators[i]--;
            if(i == 0)
                getanswer(result + operands[idx], idx+1);
            else if(i == 1)
                getanswer(result - operands[idx], idx+1);
            else if(i == 2)
                getanswer(result * operands[idx], idx+1);
            else
                getanswer(result / operands[idx], idx+1);
            operators[i]++;
        }
    }
    return;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> operands[i];

    for(int i = 0; i < 4; i++)
        cin >> operators[i];

    getanswer(operands[0],1);

    cout << mymax << '\n';
    cout << mymin << '\n';
}