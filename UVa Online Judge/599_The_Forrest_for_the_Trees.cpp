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

int to[N], ne[N], h[N], idx, cnt;
bool vis[27];
void add(int x, int y) {
  to[++idx] = y;
  ne[idx] = h[x], h[x] = idx;
}

void dfs(int x) {
  vis[x] = 1;  // 遍历到的边就标记一下
  if (h[x] == -1) return;
  for (int i = h[x]; ~i; i = ne[i]) {
    if (!vis[to[i]]) {
      cnt++;
      dfs(to[i]);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  string s;

  cin.ignore();  // 因为上面用了cin，此处防止getline把上面那个cin的回车读入，不要乱用ignore

  while (t--) {
    int tree = 0, acorn = 0;
    idx = 0;
    memset(h, -1, sizeof h);  // 记得一定要初始化
    memset(vis, 0, sizeof vis);

    while (1) {
      getline(cin, s);
      if (s[0] == '*') break;
      add(s[1] - 'A', s[3] - 'A');  // 双向连边
      add(s[3] - 'A', s[1] - 'A');
    }

    getline(cin, s);
    for (int i = 0; i < s.size(); i++)
      if (i % 2 == 0 && !vis[s[i] - 'A']) {
        cnt = 1;
        dfs(s[i] - 'A');
        if (cnt > 1)
          tree++;
        else
          acorn++;
      }

    cout << "There are " << tree << " tree(s) and " << acorn << " acorn(s)."
         << endl;
  }

  return 0;
}
