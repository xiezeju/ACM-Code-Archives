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
const int N = 10;

int ax, ay, bx, by;
int v[N][N];

int dr[] = {1, 1, 2, 2, -1, -1, -2, -2};
int dc[] = {2, -2, 1, -1, 2, -2, 1, -1};

void dfs(int x, int y, int cnt) {
  if (x < 1 || x > 8 || y < 1 || y > 8 || cnt >= v[x][y]) return;

  v[x][y] = cnt;

  for (int i = 0; i < 8; i++) {
    int nx = x + dr[i];
    int ny = y + dc[i];
    dfs(nx, ny, cnt + 1);
  }
}

int32_t main() {
#ifdef Online_Judge
  freopen("INPUT.in", "r", stdin);
  freopen("OUTPUT.out", "w", stdout);
#endif

  ios::sync_with_stdio(false);
  cin.tie(0);

  string a, b;
  while (cin >> a >> b) {
    memset(v, 0x3f, sizeof v);

    ax = a[1] - '0';
    ay = a[0] - 'a' + 1;
    bx = b[1] - '0';
    by = b[0] - 'a' + 1;

    dfs(ax, ay, 0);
    cout << "To get from " << a << " to " << b << " takes " << v[bx][by]
         << " knight moves." << endl;
  }

  return 0;
}