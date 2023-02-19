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
const int N = 1e5 + 5;
struct Node {
  int l, r;
  int x;
} a[N];
queue<int> Q;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i].x);
      a[i].l = i - 1;
      a[i].r = i + 1;
      Q.push(i);
    }
    a[0].r = 1;
    a[n + 1].x = 9999999;
    while (!Q.empty()) {
      int now = Q.front();
      Q.pop();
      int pre = a[now].l;
      int next = a[now].r;
      if (a[now].x > a[next].x) {
        Q.push(pre);
        a[pre].r = a[next].r;
        a[a[next].r].l = pre;
        a[next].l = pre;
      }
    }
    int ans = 0;
    int now = a[0].r;
    while (now <= n) {
      ans++;
      now = a[now].r;
    }
    printf("%d\n", ans);
    now = a[0].r;
    while (now <= n) {
      printf("%d ", a[now].x);
      now = a[now].r;
    }
    puts("");
  }
  return 0;
}