#include <iostream>
using namespace std;
int a[1010] = {};
int main() {
  int n, i;
  while (cin >> n) {
    a[1] = 2, a[2] = 4;
    for (i = 3; i <= n; ++i) a[i] = a[i - 1] + i * (i - 1) / 2 + 1;
    cout << a[n] << endl;
  }
  return 0;
}