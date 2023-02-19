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
const int N = 1010;

int n, m, x, y;
int a[N][N];
int s[N][N];

void Matrix_sum(int x, int y) {
  s[x][y] = s[x - 1][y] + s[x][y - 1] - s[x - 1][y - 1] + a[x][y];
}

int main() {
#ifdef Online_Judge
  freopen("INPUT.in", "r", stdin);
  freopen("OUTPUT.out", "w", stdout);
#endif

  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m >> x >> y;
    memset(s, 0, sizeof(s));
    int ans = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        cin >> a[i][j];
        Matrix_sum(i, j);
        if (i >= x && j >= y)
          ans = max(ans, s[i][j] - s[i][j - y] - s[i - x][j] + s[i - x][j - y]);
      }
    cout << ans << endl;
  }

  return 0;
}