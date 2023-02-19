#include <bits/stdc++.h>
#define LSOne(S) ((S) & -(S))

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n) {
    if (n < 0) break;
    int i, j;
    bool flag = 0;
    for (i = sqrt(n) + 1; i >= 2;
         i--) {  // sqrt（n）+ 1 的加1是为了包含n=3的情况
      int x = n;
      for (j = 1; j <= i; j++) {  // 利用带余除法 x * i + 1 = s
        if (x % i != 1) break;
        x--;
        x = x - x / i;
      }
      if (x % i == 0 &&
          j ==
              i + 1) {  // 确保上面那个循环没有中途break，只要再检验一下x%i若为零则说明是最后一轮
        flag = 1;
        break;
      }
    }

    if (!flag)
      cout << n << " coconuts, no solution" << endl;
    else
      cout << n << " coconuts, " << i << " people and 1 monkey" << endl;
  }

  return 0;
}
