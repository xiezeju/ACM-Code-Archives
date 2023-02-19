#include <bits/stdc++.h>
#define LSOne(S) ((S) & -(S))

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;
const int N = 17;
int a[N] = {};
bool vis[N];
int n, h, cnt = 0;

void dfs(int x) {
  if (x > n) return;
  if (x == n && cnt == h) {
    for (int i = 0; i < n; i++) cout << a[i];
    cout << endl;
    return;
  }
  for (int i = 0; i <= 1; i++) {
    int tmp = a[x];
    if (!vis[x]) {
      vis[x] = 1;
      a[x] = i;
      if (i == 1) cnt++;
      dfs(x + 1);
      if (i == 1) cnt--;
      a[x] = tmp;
      vis[x] = 0;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> h;
    cnt = 0;
    memset(vis, 0, sizeof vis);
    dfs(0);
    if (t) cout << endl;
  }

  return 0;
}
