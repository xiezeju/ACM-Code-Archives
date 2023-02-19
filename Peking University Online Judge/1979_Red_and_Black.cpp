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
const int N = 25;

int n, m;
int ans = 0;
char a[N][N];
bool v[N][N];

int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

void dfs(int x, int y) {
  v[x][y] = 1;
  ans++;
  for (int i = 0; i < 4; i++) {
    int ux = x + dr[i];
    int uy = y + dc[i];
    if (ux < 1 || ux > n || uy < 1 || uy > m) continue;

    if (!v[ux][uy] && a[ux][uy] == '.') dfs(ux, uy);
  }
}

int main() {
#ifdef Online_Judge
  freopen("INPUT.in", "r", stdin);
  freopen("OUTPUT.out", "w", stdout);
#endif

  ios::sync_with_stdio(false);
  cin.tie(0);

  while (cin >> m >> n, n || m) {
    int sx, sy;
    ans = 0;
    memset(v, 0, sizeof v);

    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        cin >> a[i][j];
        if (a[i][j] == '@') sx = i, sy = j;
      }
    dfs(sx, sy);
    cout << ans << endl;
  }

  return 0;
}