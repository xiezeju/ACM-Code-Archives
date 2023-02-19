#include <bits/stdc++.h>

using namespace std;

const long long MAXV = 1LL << 31;
set<int> c23;

int main() {
  bool f2 = true, f3 = true;
  c23.insert(1);
  set<int>::iterator iter = c23.begin();
  while (f2 || f3) {
    if (f2) {
      long long t2 = *iter * 2LL;
      if (t2 <= MAXV)
        c23.insert(int(t2));
      else
        f2 = false;
    }
    if (f3) {
      long long t3 = *iter * 3LL;
      if (t3 <= MAXV)
        c23.insert(int(t3));
      else
        f3 = false;
    }
    iter++;
  }

  int n;
  while (~scanf("%d", &n) && n) {
    iter = c23.lower_bound(n);
    printf("%d\n", *iter);
  }

  return 0;
}