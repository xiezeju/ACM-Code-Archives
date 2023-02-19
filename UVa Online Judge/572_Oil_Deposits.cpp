#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, m;          // 行、列
char Map[N][N];    // 用于存储地图
bool visit[N][N];  // 用于标记已经访问过的点
int ans;

// 用于访问周围的八个方向
int dx[] = {1, 1, 1, -1, -1, -1, 0, 0}, dy[] = {1, 0, -1, 1, 0, -1, 1, -1};

void dfs(int x, int y) {
  // 进来的每个格子先标记一下，避免后续重复访问
  visit[x][y] = 1;
  for (int i = 0; i < 8; i++) {
    // 计算出移动过后的坐标
    int nx = x + dx[i];
    int ny = y + dy[i];
    // 新坐标不能越界，否则为非法访问
    if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
    // 新坐标合法的前提下还需要保证它之前没有被访问过
    if (!visit[nx][ny] && Map[nx][ny] == '@') dfs(nx, ny);
  }
}

int main() {
  while (cin >> n >> m, n || m) {
    // 新一轮的数据清空之前的访问状态，这一步至关重要，以后会经常用
    memset(visit, 0, sizeof visit);
    ans = 0;

    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) cin >> Map[i][j];

    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        // 找入口并且入口没有被访问过
        if (Map[i][j] == '@' && !visit[i][j]) {
          dfs(i, j);
          ans++;
        }
      }
    cout << ans << endl;
  }
  return 0;
}
