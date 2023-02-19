#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;

int order[6][3] = {
    0, 1, 2, 0, 2, 1, 1, 0, 2, 1, 2, 0, 2, 0, 1, 2, 1, 0,
};
int used[55];

int f(int P[], int X, int Y) {
  for (int i = 1; i <= 52; ++i) {
    if (!used[i]) {
      int min = 3;
      for (int t = 0; t < 6; ++t) {
        int count = 0;
        if (P[order[t][0]] < X) {
          count++;
        }
        if (P[order[t][1]] < Y) {
          count++;
        }
        if (P[order[t][2]] < i) {
          count++;
        }
        if (min > count) {
          min = count;
        }
      }
      if (min >= 2) {
        return i;
      }
    }
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  int P[3], X, Y;
  while (~scanf("%d%d%d%d%d", &P[0], &P[1], &P[2], &X, &Y) &&
         P[0] + P[1] + P[2] + X + Y) {
    for (int i = 1; i <= 52; ++i) {
      used[i] = 0;
    }
    used[P[0]] = 1;
    used[P[1]] = 1;
    used[P[2]] = 1;
    used[X] = 1;
    used[Y] = 1;

    printf("%d\n", f(P, X, Y));
  }
  return 0;
}
