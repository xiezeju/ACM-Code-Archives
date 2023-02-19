#include <bits/stdc++.h>
#define LSOne(S) ((S) & -(S))
#define INF 0x3f3f3f3f
// #define int long long

using namespace std;

const int N = 10010;

int32_t main() {
#ifdef Online_Judge
  freopen("INPUT.in", "r", stdin);
  freopen("OUTPUT.out", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    stack<int> st;
    string s;
    int sum = 0;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '\\') st.push(i);
      if (s[i] == '/' && st.size() != 0) {
        sum += i - st.top();
        st.pop();
      }
    }
    cout << sum << endl;
  }

  return 0;
}