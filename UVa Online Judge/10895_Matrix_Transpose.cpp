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
const int N = 10001;
int g[N][N];
int vis[N];
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int m, n;
  while (cin >> m >> n) {
    memset(g, 0, sizeof g);
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= m; i++) {
      int r;
      cin >> r;
      queue<int> v;
      for (int j = 1; j <= r; j++) {
        int q;
        cin >> q;
        vis[q]++;
        v.push(q);
      }

      for (int j = 1; j <= r; j++) {
        int q;
        cin >> q;
        g[i][v.front()] = q;
        v.pop();
      }
    }
    cout << n << " " << m << endl;
    for (int i = 1; i <= n; i++) {
      queue<int> v;
      cout << vis[i];
      for (int j = 1; j <= m; j++) {
        if (g[j][i]) {
          cout << " " << j;
          v.push(g[j][i]);
        }
      }
      cout << endl;
      while (v.size()) {
        if (v.size() == 1)
          cout << v.front() << endl;
        else
          cout << v.front() << " ";
        v.pop();
      }
    }
  }
  return 0;
}
