#include <algorithm>
#include <iostream>
using namespace std;
const int N = 50005;

int n, k;

struct cow {
  int idx;
  int a, b;
} c[N];

bool cmp1(cow c1, cow c2) { return c1.a > c2.a; }

bool cmp2(cow c1, cow c2) { return c1.b > c2.b; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  while (cin >> n >> k) {
    for (int i = 1; i <= n; i++) {
      int a, b;
      cin >> a >> b;
      c[i] = {i, a, b};
    }

    sort(c + 1, c + n + 1, cmp1);
    sort(c + 1, c + k + 1, cmp2);

    cout << c[1].idx << endl;
  }

  return 0;
}