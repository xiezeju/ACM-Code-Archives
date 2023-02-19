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
#define int long long

using namespace std;
typedef long long ll;

const long long LLINF = 4e18;
const double EPS = 1e-9;
const int N = 150;

int n, m;
int g[N][N];   // 用于更新最短路
int mp[N][N];  // 用于保存原始边权

int Floyd() {
  int res = INF;
  /*
    最小环长度 = (i->j最大标号不超过k的最短路径 + i->k和k->j的路径) 的最小值
    可以证明因为i->j均小于k,所以i->j的最短路径中必定不包含点k,
    只需要不断找到i->j之外的一个点进行更新就总能找到最短的环路。
  */
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i < k; i++)
      for (int j = i + 1; j < k; j++)
        res = min(res, g[i][j] + mp[i][k] + mp[k][j]);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
  }

  return res;
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (cin >> n >> m) {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) {
        if (i == j)
          g[i][j] = mp[i][j] = 0;
        else
          g[i][j] = mp[i][j] = INF;
      }
    while (m--) {
      int x, y, z;
      cin >> x >> y >> z;
      mp[x][y] = mp[y][x] = g[x][y] = g[y][x] = min(g[x][y], z);
    }
    int ans = Floyd();
    if (ans < INF)
      cout << ans << endl;
    else
      cout << "It's impossible." << endl;
  }
  return 0;
}
