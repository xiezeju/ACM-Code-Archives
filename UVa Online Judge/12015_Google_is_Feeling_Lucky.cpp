#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;

struct q {
  string s;
  int c;
} ss[10];

bool cmp(q x, q y) { return x.c > y.c; }

int main() {
  ios::sync_with_stdio(false);
  int t, q = 1;
  cin >> t;
  while (t--) {
    string s[10];
    for (int i = 0; i < 10; i++) cin >> ss[i].s >> ss[i].c;
    sort(ss, ss + 10, cmp);
    int x = ss[0].c;
    cout << "Case #" << q++ << ":" << endl;
    for (int i = 0; i < 10; i++)
      if (ss[i].c == x) cout << ss[i].s << endl;
  }
  return 0;
}
