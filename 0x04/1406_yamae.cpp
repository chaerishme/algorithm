// 야매 사용
#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
char dat[MX];
int pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, char tmp){
    dat[unused] = tmp;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];

    if(nxt[addr] != -1) pre[nxt[addr]] = unused; // 주의! 맨 끝에 원소를 추가할 경우
    nxt[addr] = unused;
    unused++;
}

void erase(int addr){
    if (nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
    nxt[pre[addr]] = nxt[addr];
}

void traverse(){
  int cur = nxt[0];
  while(cur != -1){
    cout << dat[cur];
    cur = nxt[cur];
  }
  cout << "\n\n";
}

int main(void) {
  fill(pre, pre+MX, -1);
  fill(nxt, nxt+MX, -1);

    string s;
    int m;

    cin >> s >> m;

    for (int i = 0; i < s.length(); i++) {
        insert(i, s[i]);
    }

    int cursor = s.length();

    while (m--)  {
        char tmp;
        cin >> tmp;

        if (tmp == 'L') {
            if (pre[cursor] != -1) cursor = pre[cursor];
        } else if (tmp == 'D') {
            if (nxt[cursor] != -1) cursor = nxt[cursor];
        } else if (tmp == 'B') {
            if (cursor != 0) {
                erase(cursor);
                cursor = pre[cursor];
            }
        } else if (tmp == 'P') {
            char tmp2;
            cin >> tmp2;
            insert(cursor, tmp2);
            cursor = nxt[cursor];
        }
    }

    traverse();
}