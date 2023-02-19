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
const int N = 110;
int n, m;
char a[N][N];
bool v[N][N];
int cnt;
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

void dfs(int x, int y) {
  v[x][y] = 1;
  cnt++;
  for (int i = 0; i < 4; i++) {
    int nx = x + dr[i];
    int ny = y + dc[i];
    if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
    if (a[nx][ny] == '#' || v[nx][ny]) continue;
    dfs(nx, ny);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (cin >> m >> n) {
    if (!n && !m) break;
    memset(v, 0, sizeof v);
    int s, e;
    cnt = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        cin >> a[i][j];
        if (a[i][j] == '@') s = i, e = j;
      }
    dfs(s, e);
    cout << cnt << endl;
  }

  return 0;
}