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
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define LSOne(S) ((S) & -(S))
#define INF 0x3f3f3f3f
// #define int long long

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const long long LLINF = 4e18;
const double PI = acos(-1.0);
const double EPS = 1e-9;
const int N = 100;

int n, m;
int g[N][N];
int mat[N][N][N];
int temp[N][N];
void mat_power(int n1, int n2) {
  memset(temp, 0, sizeof temp);
  for (int i = 1; i <= m; i++)
    for (int k = 1; k <= m; k++)
      for (int j = 1; j <= m; j++) temp[i][j] += mat[n1][i][k] * mat[n2][k][j];
}

bool canmove(int x) {
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= m; j++)
      if (temp[i][j] != mat[x][i][j]) return false;
  return true;
}

void floyd() {
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        if (g[i][j] > g[i][k] + g[k][j]) g[i][j] = g[i][k] + g[k][j];
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (cin >> n >> m) {
    if (!n && !m) break;
    memset(g, 0x3f, sizeof g);
    for (int i = 1; i <= n; i++) g[i][i] = 0;
    for (int k = 1; k <= n; k++)
      for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) cin >> mat[k][i][j];
      }
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) {
        if (i == j) continue;
        mat_power(i, j);
        for (int k = 1; k <= n; k++) {
          if (i == k || g[i][k] == 1) continue;
          if (j == k) continue;
          if (canmove(k)) g[i][k] = min(g[i][k], 1);
        }
      }
    floyd();
    int k;
    cin >> k;
    while (k--) {
      int x, y;
      cin >> x >> y;
      if (g[x][y] == INF)
        cout << "Sorry" << endl;
      else
        cout << g[x][y] << endl;
    }
  }

  return 0;
}