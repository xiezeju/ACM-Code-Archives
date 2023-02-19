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
const int N = 30;
int n;
vector<int> q[N];

void find_block(int a, int &p, int &h) {
  for (p = 0; p < n; p++) {
    for (h = 0; h < q[p].size(); h++)
      if (q[p][h] == a) return;
  }
}

void clear_above(int p, int h) {
  for (int i = h + 1; i < q[p].size(); i++) q[q[p][i]].push_back(q[p][i]);
  q[p].resize(h + 1);
}

void pile_onto(int p, int h, int p2) {
  for (int i = h; i < q[p].size(); i++) q[p2].push_back(q[p][i]);
  q[p].resize(h);
}

void print() {
  for (int i = 0; i < n; i++) {
    printf("%d:", i);
    for (int j = 0; j < q[i].size(); j++) printf(" %d", q[i][j]);
    printf("\n");
  }
}

int32_t main() {
#ifdef Online_Judge
  freopen("INPUT.in", "r", stdin);
  freopen("OUTPUT.out", "w", stdout);
#endif

  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  string x, y;
  for (int i = 0; i < n; i++) q[i].push_back(i);
  int a, b;
  while (cin >> x >> a >> y >> b) {
    int pa, pb, ha, hb;
    find_block(a, pa, ha);
    find_block(b, pb, hb);
    if (pa == pb) continue;
    if (y == "onto") clear_above(pb, hb);
    if (x == "move") clear_above(pa, ha);
    pile_onto(pa, ha, pb);
  }
  print();
  return 0;
}