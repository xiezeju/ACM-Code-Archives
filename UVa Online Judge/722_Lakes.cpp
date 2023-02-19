#include <bits/stdc++.h>
#define LSOne(S) ((S) & -(S))
#define INF 0x3f3f3f3f
// #define int long long

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const long long LLINF = 4e18;
const double PI = acos(-1.0);
const double EPS = 1e-9;
const int N = 105;

char g[N][N];
bool v[N][N];
int ans = 0;

int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

void dfs(int x, int y) {
  v[x][y] = 1;
  ans++;
  for (int i = 0; i < 4; i++) {
    int nx = x + dr[i];
    int ny = y + dc[i];
    if (nx < 0 || nx >= 100 || ny < 0 || ny >= 100) continue;
    if (!v[nx][ny] && g[nx][ny] == '0') dfs(nx, ny);
  }
}

int32_t main() {
#ifdef Online_Judge
  freopen("INPUT.in", "r", stdin);
  freopen("OUTPUT.out", "w", stdout);
#endif

  ios::sync_with_stdio(false);
  cin.tie(0);
  int M;
  cin >> M;

  while (M--) {
    ans = 0;
    memset(v, 0, sizeof v);
    memset(g, 0, sizeof g);

    int sx, sy;
    cin >> sx >> sy;
    cin.ignore();

    string a;
    int i = 0;
    while (getline(cin, a) && a != "") {
      for (int j = 0; a[j]; j++) g[i][j] = a[j];
      i++;
    }

    dfs(sx - 1, sy - 1);
    cout << ans << endl;
    if (M) cout << endl;
  }

  return 0;
}