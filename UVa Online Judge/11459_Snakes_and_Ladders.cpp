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

int main() {
  ios::sync_with_stdio(false);
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    vector<int> p(a + 1, 1);
    map<int, int> mp;
    int x = 1;
    for (int i = 0; i < b; i++) {
      int aa, bb;
      scanf("%d %d", &aa, &bb);
      mp[aa] = bb;
    }
    for (int j = 1; j <= c; j++) {
      int op;
      scanf("%d", &op);
      p[x] += op;
      if (p[x] > 100) p[x] == 100;
      if (mp.count(p[x])) p[x] = mp[p[x]];
      if (p[x] == 100) {
        p[x] = 100;
        while (++j <= c) scanf("%d", &op);
        break;
      }
      x++;
      if (x > a) x = 1;
    }
    for (int i = 1; i <= a; i++)
      printf("Position of player %d is %d.\n", i, p[i]);
  }
  return 0;
}
