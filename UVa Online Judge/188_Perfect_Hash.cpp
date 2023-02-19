#include <bits/stdc++.h>
#define LSOne(S) ((S) & -(S))

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
const int INF = 0x3f3f3f3f;
const long long LLINF = 4e18;
const double EPS = 1e-9;
const int N = 300;

char str[N];
int w[N];
int n, c;

void solve() {
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (c / w[i] % n == c / w[j] % n) {
        c = min((c / w[i] + 1) * w[i], (c / w[j] + 1) * w[j]);
        solve();
        return;
      }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (gets(str)) {
    n = 0;
    memset(w, 0, sizeof(w));
    for (int i = 0; i < strlen(str); i++)
      if (str[i] >= 'a' && str[i] <= 'z')
        w[n] = (w[n] << 5) + str[i] - 'a' + 1;
      else {
        n++;
        while (str[i + 1] == ' ') i++;
      }
    n++;
    sort(w, w + n);
    c = w[0];
    solve();
    puts(str);
    printf("%d\n\n", c);
  }
  return 0;
}
