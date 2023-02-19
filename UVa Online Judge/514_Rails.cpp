#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;
const int maxn = 2e6 + 10;

int b[1010];
int main() {
  int i, n, k, t;
  stack<int> s;
  while (scanf("%d", &n), n) {
    while (1) {
      while (!s.empty()) s.pop();
      k = t = 0;
      scanf("%d", &b[0]);
      if (b[0] == 0) break;
      for (i = 1; i < n; i++) scanf("%d", &b[i]);
      for (i = 1; i <= n; i++) {
        s.push(i);
        while (!s.empty() && s.top() == b[k]) {
          k++;
          s.pop();
        }
      }
      if (s.empty())
        printf("Yes\n");
      else
        printf("No\n");
    }
    printf("\n");
  }
}
