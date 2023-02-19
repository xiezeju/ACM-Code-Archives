#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define LSOne(S) ((S) & -(S))
#define INF 0x3f3f3f3f

using namespace std;
typedef long long ll;

const long long LLINF = 4e18;
const double EPS = 1e-9;
const int N = 50;

int g[N][N], cost[N];
int path[N][N];  // path[i][j]保存了从i到j路径的第一个点(i后面那个点)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n) {
    if (!n) break;
    memset(g, 0x3f, sizeof g);

    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) {
        cin >> g[i][j];
        if (g[i][j] == -1) g[i][j] = INF;
        path[i][j] = j;
      }

    for (int i = 1; i <= n; i++) cin >> cost[i];

    for (int k = 1; k <= n; k++)
      for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
          if (g[i][j] > g[i][k] + g[k][j] + cost[k]) {
            g[i][j] = g[i][k] + g[k][j] + cost[k];
            path[i][j] = path[i][k];
          } else if (g[i][j] == g[i][k] + g[k][j] + cost[k] &&
                     path[i][j] > path[i][k])
            path[i][j] = path[i][k];
        }
    int x, y;
    while (cin >> x >> y) {
      if (x == -1 && y == -1) break;
      printf("From %d to %d :\nPath: %d", x, y, x);
      int u = x;
      while (u != y) {
        u = path[u][y];
        printf("-->%d", u);
      }
      printf("\nTotal cost : %d\n\n", g[x][y]);
    }
  }

  return 0;
}