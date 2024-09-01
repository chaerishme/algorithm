#include <iostream>
#include <cmath>
using namespace std;
int n, num;
int board[22][22];
int team1[12];
int team2[12];
bool vis[12];
int ans = -1;
void fc(int start, int cnt){
    if(cnt == num){
        int tmp1 = 0;
        int tmp2 = 0;
        for (int i = 0; i < n; i++){
            if(vis[i]){
                team1[tmp1] = i;
                tmp1++;
            }else{
                team2[tmp2] = i;
                tmp2++;
            }
        }
        tmp1 = 0;
        tmp2 = 0;
        for (int j = 0; j < num - 1; j++)
        {
            for (int k = j + 1; k < num; k++)
            {
                tmp1 += board[team1[j]][team1[k]] + board[team1[k]][team1[j]];
                tmp2 += board[team2[j]][team2[k]] + board[team2[k]][team2[j]];
            }
        }
        int sub = abs(tmp1 - tmp2);
        if(ans > sub || ans == -1) ans = sub;
    } else {
        for (int i = start; i < n;i++){ 
            if(!vis[i]){
                vis[i] = true;
                fc(i + 1, cnt + 1);
                vis[i] = false;
            }
        }
    }
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    num = n / 2;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }
    fc(0, 0);
    cout << ans << '\n';
}