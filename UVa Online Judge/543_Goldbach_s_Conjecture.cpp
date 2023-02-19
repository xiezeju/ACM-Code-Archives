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

bool isprime(int x) {
  for (int i = 2; i <= x / i; i++) {
    if (x % i == 0) return false;
  }
  return x > 1;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n && n) {
    int a = 0, b = 0;
    bool ok = 0;
    for (int i = 2; i <= n / 2; i++) {
      int j = n - i;
      if (isprime(i) && isprime(j)) {
        a = i;
        b = j;
        ok = 1;
        break;
      }
    }
    if (ok == 1)
      printf("%d = %d + %d\n", n, a, b);
    else
      printf("Goldbach's conjecture is wrong.\n");
  }

  return 0;
}
