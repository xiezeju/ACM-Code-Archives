#include <iostream>
using namespace std;

int main() {
  int n, i, q;
  cin >> n;
  for (i = 1; i <= n; ++i) {
    long long a[10001] = {};
    a[0] = 0;
    a[1] = 2, a[2] = 8;
    while (n--) {
      cin >> q;
      for (i = 3; i <= q; ++i) a[i] = a[i - 1] + 6 * (i - 1);
      cout << a[q] << endl;
    }
  }
  return 0;
}
