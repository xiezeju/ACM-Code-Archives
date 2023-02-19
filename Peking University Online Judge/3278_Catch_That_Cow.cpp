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

using namespace std;

const int N = 100010;

int n, k;
bool v[N];
struct node {
  int x;
  int cnt;
  node(int xx, int cc) : x(xx), cnt(cc) {}
};
queue<node> q;

int main() {
#ifdef Online_Judge
  freopen("INPUT.in", "r", stdin);
  freopen("OUTPUT.out", "w", stdout);
#endif

  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k;
  int t;
  int ans = 1e9;
  q.push({n, 0});
  v[n] = 1;

  while (!q.empty()) {
    node u = q.front();
    q.pop();
    if (u.x == k) ans = min(ans, u.cnt);

    for (int i = 0; i < 3; i++) {
      if (i == 0)
        t = u.x + 1;
      else if (i == 1)
        t = u.x - 1;
      else if (i == 2)
        t = u.x * 2;
      if (t < 0 || t > 100000) continue;

      if (!v[t]) {
        v[t] = 1;
        q.push({t, u.cnt + 1});
      }
    }
  }
  cout << ans << endl;

  return 0;
}