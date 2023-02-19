
#include <bits/stdc++.h>

using namespace std;

const int N = 5;
int a[N];
bool flag, vis[N];

void dfs(int cnt, int result) {
  if (cnt == N) {
    if (result == 23) flag = true;
  } else if (!flag) {
    for (int i = 0; i < N; i++) {
      if (!vis[i]) {
        vis[i] = true;
        dfs(cnt + 1, result + a[i]);
        dfs(cnt + 1, result - a[i]);
        dfs(cnt + 1, result * a[i]);
        vis[i] = 0;
      }
    }
  }
}

int main() {
  for (;;) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
      scanf("%d", &a[i]);
      sum += a[i];
    }
    if (sum == 0) break;

    flag = false;
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < N; i++) {
      vis[i] = true;
      dfs(1, a[i]);
      vis[i] = false;
      if (flag) break;
    }

    printf("%s\n", flag ? "Possible" : "Impossible");
  }

  return 0;
}
