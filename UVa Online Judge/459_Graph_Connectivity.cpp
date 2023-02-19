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
const int N = 100;
int to[N], ne[N], h[N];
int idx;
bool vis[N];

void add(int x, int y) {
  to[++idx] = y;
  ne[idx] = h[x], h[x] = idx;
}

void dfs(int x) {
  vis[x] = 1;
  for (int i = h[x]; ~i; i = ne[i])
    if (!vis[to[i]]) dfs(to[i]);
};

string s;
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    idx = 0;
    memset(h, -1, sizeof h);
    memset(vis, 0, sizeof vis);
    char c;
    cin >> c;
    int num_node = c - 'A' + 1;
    cin.ignore();
    while (getline(cin, s) && s != "")
      add(s[0] - 'A', s[1] - 'A'), add(s[1] - 'A', s[0] - 'A');
    int numCC = 0;
    for (int i = 0; i < num_node; i++)
      if (!vis[i]) {
        ++numCC;
        dfs(i);
      }
    cout << numCC << endl;
    if (t) cout << endl;
  }

  return 0;
}
