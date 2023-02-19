#include <bits/stdc++.h>
using namespace std;

int n;
char a[5][5];
bool v[5][5];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
int ans = 0;

bool can_set(int x, int y) {
  for (int i = 0; i < 4; i++) {
    int nx = x;
    int ny = y;
    for (;;) {
      nx += dr[i];
      ny += dc[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= n) break;
      if (a[nx][ny] == 'X') break;
      if (a[nx][ny] == 'O') return false;
    }
  }
  return true;
}

void dfs(int num, int cnt) {
  if (num == n * n) {
    ans = max(ans, cnt);
    return;
  } else {
    int x, y;
    x = num / n;
    y = num % n;
    if (a[x][y] == '.' && can_set(x, y)) {
      a[x][y] = 'O';
      ans = max(ans, cnt);
      dfs(num + 1, cnt + 1);
      a[x][y] = '.';
    }
    dfs(num + 1, cnt);
  }
}

int main() {
#ifdef Online_Judge
  freopen("INPUT.in", "r", stdin);
  freopen("OUTPUT.out", "w", stdout);
#endif

  while (cin >> n, n) {
    memset(a, 0, sizeof a);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) cin >> a[i][j];
    ans = 0;

    dfs(0, 0);
    cout << ans << endl;
  }

  return 0;
}