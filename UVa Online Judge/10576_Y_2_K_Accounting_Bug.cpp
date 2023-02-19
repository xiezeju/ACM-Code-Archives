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

// 找出1-5月a+b+c+d+e<0，则1-12月必为 (a b c d e )* 2 + (a b)
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int s, d;
  while (cin >> s >> d) {
    int Max = -1 - 12 * d;
    for (int i = 0; i < (1 << 5); i++) {
      int sum_5 = 0, sum_2 = 0;
      for (int j = 0; j < 5; j++) {
        if (i & (1 << j)) {
          sum_5 -= d;
          if (j < 2) sum_2 -= d;
        } else {
          sum_5 += s;
          if (j < 2) sum_2 += s;
        }
      }
      int sum_12 = 2 * sum_5 + sum_2;
      if (Max < sum_12 && sum_5 < 0) Max = sum_12;
    }

    if (Max < 0)
      cout << "Deficit" << endl;
    else
      cout << Max << endl;
  }

  return 0;
}
