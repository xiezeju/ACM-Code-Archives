#include <bits/stdc++.h>
#define LSOne(S) ((S) & -(S))
#define INF 0x3f3f3f3f
// #define int long long

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const long long LLINF = 4e18;
const double PI = acos(-1.0);
const double EPS = 1e-9;
const int MAX = 30100;

int L, C, T, N, VR, V1, V2, M, num;
float dp[MAX];
int charge[MAX];

int main() {
  int i, j, k;
  float tmp, rabbit, TV1, ans;
  while (cin >> L >> N >> C >> T >> VR >> V1 >> V2) {
    for (i = 1; i <= N; i++) cin >> charge[i];
    dp[0] = -1 * T;
    charge[0] = 0;
    charge[N + 1] = L;
    TV1 = C / (V1 + 0.0);
    rabbit = L / (VR + 0.0);
    for (i = 1; i <= N + 1; i++) {
      ans = 1e9;
      for (j = 0; j < i; j++) {
        tmp = dp[j];
        k = charge[i] - charge[j];
        if (C < k)
          tmp += TV1 + (k - C + 0.0) / V2;
        else
          tmp += k / (V1 + 0.0);
        ans = ans > tmp ? tmp : ans;
      }
      dp[i] = ans + T;
    }
    if (dp[N + 1] < rabbit)
      printf("What a pity rabbit!\n");
    else
      printf("Good job,rabbit!\n");
  }
  return 0;
}