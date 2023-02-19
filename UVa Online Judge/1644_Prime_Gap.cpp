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
  for (int i = 2; i <= x / i; i++)
    if (x % i == 0) return false;
  return x > 1;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n && n) {
    int a = n, b = n;
    while (!isprime(a)) a--;
    while (!isprime(b)) b++;
    cout << b - a << endl;
  }

  return 0;
}
