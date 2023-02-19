#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 10;
int a[N];

int main() {
#ifdef Online_Judge
  freopen("INPUT.in", "r", stdin);
  freopen("OUTPUT.out", "w", stdout);
#endif

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  while (cin >> n) {
    if (!n) break;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      q.push(a[i]);
    }
    int ans = 0;
    while (q.size() > 1) {
      int n1 = q.top();
      q.pop();
      int n2 = q.top();
      q.pop();
      ans += n1 + n2;
      q.push(n1 + n2);
    }
    cout << ans << endl;
  }
  return 0;
}