#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;
const int maxn = 1e6 + 10;

struct sb {
  string s;
  int d, m, y;
} a[110];

bool cmp(sb a, sb b) {
  if (a.y != b.y)
    return a.y > b.y;
  else if (a.m != b.m)
    return a.m > b.m;
  else if (a.d != b.d)
    return a.d > b.d;
}

int main() {
  ios::sync_with_stdio(false);
  int t;
  while (cin >> t) {
    for (int i = 0; i < t; i++) cin >> a[i].s >> a[i].d >> a[i].m >> a[i].y;
    sort(a, a + t, cmp);
    cout << a[0].s << endl << a[t - 1].s << endl;
  }
  return 0;
}
