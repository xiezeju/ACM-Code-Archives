#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;
int main() {
  int _, i;
  char a[1000], b[1000], c[1000];
  scanf("%d", &_);
  while (_--) {
    int ans = 0;
    scanf("%s%s%s", a, b, c);
    for (i = 2; i <= 16; i++) {
      int ta, tb, tc;
      ta = strtol(a, NULL, i);
      if (!ta && a != "0") continue;
      tb = strtol(b, NULL, i);
      if (!tb && b != "0") continue;
      tc = strtol(c, NULL, i);
      if (!tc && c != "0") continue;
      if (ta * tb == tc) {
        ans = i;
        break;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}