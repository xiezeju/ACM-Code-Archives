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
////#define int long long

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const long long LLINF = 4e18;
const double EPS = 1e-9;
const int N = 110;

int a[N][4], path[N];
bool v[N];
int m, kase;
void dfs(int x, int cnt) {
  if (cnt == 20 && v[x] == 0) {
    if (a[x][1] == m || a[x][2] == m || a[x][3] == m) {
      path[cnt] = x;
      cout << kase++ << ":  ";
      for (int i = 1; i <= 20; i++) cout << path[i] << " ";
      cout << m << endl;
    }
  }
  for (int i = 1; i <= 3; i++) {
    if (!v[x]) {
      v[x] = 1;
      path[cnt] = x;
      dfs(a[x][i], cnt + 1);
      v[x] = 0;
    }
  }
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  for (int i = 1; i <= 20; i++) cin >> a[i][1] >> a[i][2] >> a[i][3];

  while (cin >> m) {
    if (!m) break;
    memset(v, 0, sizeof v);
    kase = 1;
    dfs(m, 1);
  }
  return 0;
}