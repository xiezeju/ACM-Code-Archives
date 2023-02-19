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
const int N = 30100;

vector<int> G[N];
int v[N];
int n, m;

void topo() {
  priority_queue<int> Q;
  stack<int> st;
  for (int i = 1; i <= n; i++)
    if (!v[i]) Q.push(i);  // 入度为0的点
  while (!Q.empty()) {
    int x = Q.top();
    Q.pop();
    for (int i = 0; i < (int)G[x].size(); i++) {
      v[G[x][i]]--;
      if (v[G[x][i]] == 0) Q.push(G[x][i]);
    }
    st.push(x);
  }
  printf("%d", st.top());
  st.pop();
  while (!st.empty()) {
    printf(" %d", st.top());
    st.pop();
  }
  printf("\n");
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) G[i].clear();
    memset(v, 0, sizeof(v));
    for (int i = 0; i < m; i++) {
      scanf("%d%d", &a, &b);
      G[b].push_back(a);  // 反向建图
      v[a]++;             // 入度增加
    }
    topo();
  }

  return 0;
}