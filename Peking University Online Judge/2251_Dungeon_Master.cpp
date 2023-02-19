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
const int N = 35;

char a[N][N][N];
bool v[N][N][N];
int l, r, c;
int sx, sy, sz;
int ex, ey, ez;
int dx[] = {0, 0, 0, 0, 1, -1};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {1, -1, 0, 0, 0, 0};

struct node {
  int x, y, z;
  int t;
};
int ans;
void bfs() {
  queue<node> q;
  q.push({sx, sy, sz, 0});
  v[sz][sx][sy] = 1;
  while (!q.empty()) {
    node u = q.front();
    q.pop();
    int t = u.t;
    if (u.x == ex && u.y == ey && u.z == ez)
      ans = min(ans, t);
    else {
      for (int i = 0; i < 6; i++) {
        int x = u.x + dx[i];
        int y = u.y + dy[i];
        int z = u.z + dz[i];
        if (x < 1 || x > r || y < 1 || y > c || z < 1 || z > l) continue;
        if (v[z][x][y] || a[z][x][y] == '#') continue;
        v[z][x][y] = 1;
        q.push({x, y, z, t + 1});
      }
    }
  }
}

int main() {
#ifdef Online_Judge
  freopen("INPUT.in", "r", stdin);
  freopen("OUTPUT.out", "w", stdout);
#endif

  ios::sync_with_stdio(false);
  cin.tie(0);
  while (cin >> l >> r >> c, l || r || c) {
    ans = INF;
    memset(v, 0, sizeof v);
    for (int k = 1; k <= l; k++)
      for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++) {
          char b;
          cin >> b;
          a[k][i][j] = b;
          if (a[k][i][j] == 'S')
            sx = i, sy = j, sz = k;
          else if (a[k][i][j] == 'E')
            ex = i, ey = j, ez = k;
        }
    bfs();
    if (ans == INF)
      cout << "Trapped!" << endl;
    else
      cout << "Escaped in " << ans << " minute(s)." << endl;
  }

  return 0;
}