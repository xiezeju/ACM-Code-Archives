#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;

int main() {
  int a, b, c, x, y;
  while (~scanf("%d%d%d", &a, &b, &c)) {
    map<int, int> mp;
    vector<int> pos(N, 1);

    for (int i = 1; i <= b; i++) {
      scanf("%d%d", &x, &y);
      mp[x] = y;
    }

    int player = 0;
    for (int i = 1; i <= c; i++) {
      scanf("%d", &x);
      pos[player] = pos[player] + x > 100 ? 100 : pos[player] + x;

      if (mp.count(pos[player])) pos[player] = mp[pos[player]];
      if (pos[player] == 100) {
        while (++i <= c) scanf("%d", &x);
        break;
      }

      player++;
      player %= a;
    }

    for (int i = 0; i < a; i++)
      printf("Position of player %d is %d.\n", i + 1, pos[i]);
  }

  return 0;
}