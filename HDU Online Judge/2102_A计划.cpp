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
// #define int long long

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const long long LLINF = 4e18;
const double PI = acos(-1.0);
const double EPS = 1e-9;
const int N = 11;

char a[2][N][N];
bool v[2][N][N];
int n, m, t;
struct node {
  int x, y, z;
  int t;
};

int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

int main() {
#ifdef Online_Judge
  freopen("INPUT.in", "r", stdin);
  freopen("OUTPUT.out", "w", stdout);
#endif

  ios::sync_with_stdio(false);
  cin.tie(0);
  int c;
  cin >> c;
  while (c--) {
    cin >> n >> m >> t;
    memset(v, 0, sizeof(v));
    int ex, ey, ez;
    for (int k = 0; k < 2; k++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
          char b;
          cin >> b;
          a[k][i][j] = b;
          if (a[k][i][j] == 'P') ex = i, ey = j, ez = k;
        }
    queue<node> q;
    int ans = 1e9;
    q.push({0, 0, 0, 0});
    v[0][0][0] = 1;
    while (!q.empty()) {
      node u = q.front();
      q.pop();

      if (u.x == ex && u.y == ey && u.z == ez)
        ans = min(ans, u.t);
      else {
        for (int i = 0; i < 4; i++) {
          int x = u.x + dr[i];
          int y = u.y + dc[i];
          int z = u.z;

          if (x < 0 || x >= n || y < 0 || y >= m) continue;
          if (v[z][x][y] || a[z][x][y] == '*') continue;

          if (a[z][x][y] == '.' || a[z][x][y] == 'P') {
            v[z][x][y] = 1;
            q.push({x, y, z, u.t + 1});
          } else if (a[z][x][y] == '#') {
            int tz = z ^ 1;
            if (a[tz][x][y] != '*' && a[tz][x][y] != '#' && !v[tz][x][y]) {
              v[tz][x][y] = 1;
              q.push({x, y, tz, u.t + 1});
            }
          }
        }
      }
    }
    if (ans > t)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}