#include <bits/stdc++.h>
#define LSOne(S) ((S) & -(S))

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const long long LLINF = 4e18;
const double EPS = 1e-9;

int vis[101][101];
int mv[8][2];
int r, c, N, M, w, even = 0, odd = 0;

void dfs(int x, int y) {
  if (!vis[x][y])
    vis[x][y] = 1;
  else
    return;

  for (int i = 0; i < 8; i++) {
    int nx = x + mv[i][0];
    int ny = y + mv[i][1];
    if (nx >= 0 & ny >= 0 && nx < r && ny < c && !vis[nx][ny]) dfs(nx, ny);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  int x = 1;
  while (t--) {
    memset(vis, 0, sizeof vis);

    cin >> r >> c >> M >> N >> w;

    mv[0][0] = +M, mv[0][1] = +N;
    mv[2][0] = +M, mv[2][1] = -N;
    mv[1][0] = -M, mv[1][1] = +N;
    mv[3][0] = -M, mv[3][1] = -N;
    mv[4][0] = +N, mv[4][1] = +M;
    mv[5][0] = +N, mv[5][1] = -M;
    mv[6][0] = -N, mv[6][1] = +M;
    mv[7][0] = -N, mv[7][1] = -M;

    while (w--) {
      int x, y;
      cin >> x >> y;
      vis[x][y] = -1;
    }
    dfs(0, 0);
    even = 0, odd = 0;
    for (int i = 0; i < r; i++)
      for (int j = 0; j < c; j++) {
        if (vis[i][j] == 1) {
          int sum = 0;
          for (int k = 0; k < 8; k++) {
            int nx = i + mv[k][0];
            int ny = j + mv[k][1];
            if (nx >= 0 & ny >= 0 && nx < r && ny < c)
              sum += (vis[nx][ny] == 1);
          }
          if (N == M || 0 == N || 0 == M) {
            sum /= 2;
          }
          if (sum % 2) {
            odd++;
          } else if (sum) {
            even++;
          }
          if (0 == i && 0 == j && 0 == sum) {
            even++;
          }
        }
      }
    printf("Case %d: %d %d\n", x++, even, odd);
  }

  return 0;
}
