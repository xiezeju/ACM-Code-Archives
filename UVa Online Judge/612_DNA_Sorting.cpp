#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;
const int maxn = 2e6 + 10;

struct sb {
  string s;
  int a, b;
} b[110];

bool cmp(sb x, sb y) {
  if (x.a != y.a)
    return x.a < y.a;
  else
    return x.b < y.b;
}

int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
      cin >> b[i].s;
      b[i].b = i;
      for (int j = 0; j < n; j++)
        for (int k = j + 1; k < n; k++)
          if (b[i].s[k] < b[i].s[j]) b[i].a++;
    }
    sort(b, b + m, cmp);
    for (int i = 0; i < m; i++) cout << b[i].s << endl;
    if (t) cout << endl;
  }
  return 0;
}
