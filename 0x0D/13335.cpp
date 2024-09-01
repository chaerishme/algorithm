#include <bits/stdc++.h>
#include <queue>
using namespace std;
int n, w, L, ans, a[1000];
queue<int> q;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> w >> L;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int sum = 0;
    for(int i = 0; i < n; i++) {
        while(true) {
            if(q.size() == w) {
                sum -= q.front();
                q.pop();
            }
            if(a[i] + sum <= L) {
                break;
            }
            q.push(0);
            ans++;
        }
        q.push(a[i]);
        sum += a[i];
        ans++;
    }    
    
    cout << ans + w << '\n';
}