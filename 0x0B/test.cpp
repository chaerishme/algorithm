#include <bits/stdc++.h>
using namespace std;
void printnum(int x) {
    if (x > 10) return;
    cout << x++ << '\n';
    printnum(x); 
} 
int printsum(int x){
    if (x==0) return 0;
    return x + printsum(x-1);
}
int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    printnum(1);
    cout << printsum(10) << '\n';
}
