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
const int N = 55;

int n, m;
int pipe[11][4] = {{1, 0, 0, 1}, {1, 1, 0, 0}, {0, 0, 1, 1}, {0, 1, 1, 0},
                   {1, 0, 1, 0}, {0, 1, 0, 1}, {1, 1, 0, 1}, {1, 0, 1, 1},
                   {0, 1, 1, 1}, {1, 1, 1, 0}, {1, 1, 1, 1}};
int a[N][N];
int p[N * N];

void init() {
  for (int i = 0; i <= n * m; i++) p[i] = i;
}

int find(int x) { return p[x] == x ? x : find(p[x]); }

void add(int i, int j) {
  int x = find(i);
  int y = find(j);
  if (x == y) return;
  p[y] = x;
}

int main() {
#ifdef Online_Judge
  freopen("INPUT.in", "r", stdin);
  freopen("OUTPUT.out", "w", stdout);
#endif

  ios::sync_with_stdio(false);
  cin.tie(0);
  while (cin >> m >> n) {
    if (m == -1 && n == -1) break;
    init();
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= n; j++) {
        char b;
        cin >> b;
        a[i][j] = b - 'A';
      }

    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= n; j++) {
        int c = (i - 1) * n + j;
        int k = a[i][j];
        int up = a[i - 1][j];
        int down = a[i + 1][j];
        int left = a[i][j - 1];
        int right = a[i][j + 1];
        if (i > 1 && pipe[k][0] && pipe[up][2]) add(c, c - n);
        if (i < m && pipe[k][2] && pipe[down][0]) add(c, c + n);
        if (j > 1 && pipe[k][3] && pipe[left][1]) add(c, c - 1);
        if (j < n && pipe[k][1] && pipe[right][3]) add(c, c + 1);
      }
    int ans = 0;
    for (int i = 1; i <= m * n; i++)
      if (i == find(i)) ans++;
    cout << ans << endl;
  }
  return 0;
}