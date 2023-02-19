#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 7;
int sum[N];

void build(int p) {
  int v;
  cin >> v;
  if (v == -1) return;
  sum[p] += v;
  build(p - 1);
  build(p + 1);
}

// 输入第一个节点
bool init() {
  int v;
  cin >> v;
  if (v == -1) return false;
  memset(sum, 0, sizeof sum);
  int p = N >> 1;
  sum[p] = v;
  build(p - 1);
  build(p + 1);
  return true;
}

int32_t main() {
#ifdef Online_Judge
  freopen("INPUT.in", "r", stdin);
  freopen("OUTPUT.out", "w", stdout);
#endif

  ios::sync_with_stdio(false);
  cin.tie(0);
  int k = 0;
  while (init()) {
    int p = 0;
    while (sum[p] == 0) p++;
    cout << "Case " << ++k << ":\n" << sum[p++];
    while (sum[p] != 0) {
      cout << " " << sum[p];
      p++;
    }
    cout << "\n\n";
  }
  return 0;
}