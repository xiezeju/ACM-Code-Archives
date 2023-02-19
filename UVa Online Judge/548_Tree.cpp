#include <bits/stdc++.h>
using namespace std;

const int N = 10000 + 10;

int inorder[N], postorder[N], lch[N], rch[N];
int n;

bool read_data(int* a) {
  string s;
  if (!getline(cin, s)) return false;
  stringstream ss(s);
  int x;
  n = 0;
  while (ss >> x) a[n++] = x;
  return n > 0;
}

int build(int L1, int R1, int L2, int R2) {
  if (L1 > R1) return 0;
  int root = postorder[R2];
  int p = L1;
  while (inorder[p] != root) p++;
  int cnt = p - L1;
  lch[root] = build(L1, p - 1, L2, L2 + cnt - 1);
  rch[root] = build(p + 1, R1, L2 + cnt, R2 - 1);
  return root;
}

int ans_node, best_sum;

void dfs(int u, int sum) {
  sum += u;
  if (!lch[u] && !rch[u]) {
    if (sum < best_sum || (sum == best_sum && u < ans_node)) {
      ans_node = u;
      best_sum = sum;
    }
  }
  if (lch[u]) dfs(lch[u], sum);
  if (rch[u]) dfs(rch[u], sum);
}

int32_t main() {
#ifdef Online_Judge
  freopen("INPUT.in", "r", stdin);
  freopen("OUTPUT.out", "w", stdout);
#endif

  ios::sync_with_stdio(false);
  cin.tie(0);

  while (read_data(inorder)) {
    read_data(postorder);
    build(0, n - 1, 0, n - 1);
    best_sum = 1e9;
    dfs(postorder[n - 1], 0);
    cout << ans_node << endl;
  }

  return 0;
}