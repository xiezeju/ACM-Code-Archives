#include <bits/stdc++.h>
#define LSOne(S) ((S) & -(S))

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const long long LLINF = 4e18;
const double EPS = 1e-9;
const int N = 500010;

int L, n, m;
int a[N];

bool check(int x) {
  int cnt = 1, dis = 0;
  for (int i = 1; i <= n + 1; i++) {
    dis += a[i] - a[i - 1];
    if (dis > x) {
      cnt++;
      dis = a[i] - a[i - 1];
    }
  }
  return cnt <= m;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  while (cin >> L >> n >> m) {
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[n + 1] = L;
    sort(a + 1, a + 1 + n);

    int l = 0, r = L, mid;

    for (int i = 1; i <= n + 1; i++) l = max(l, a[i] - a[i - 1]);

    while (l < r) {
      if (check(mid = l + r >> 1))
        r = mid;
      else
        l = mid + 1;
    }
    cout << l << endl;
  }

  return 0;
}