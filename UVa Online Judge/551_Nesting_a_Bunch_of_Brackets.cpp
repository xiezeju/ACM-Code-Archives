#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;
const int maxn = 2e6 + 10;

inline bool isclosed(char c) {
  return c == '}' || c == '>' || c == ')' || c == ']';
}

int main() {
  ios::sync_with_stdio(false);
  map<char, int> m;

  m[']'] = '[';
  m['('] = ')';
  m[')'] = '(';
  m['{'] = '}';
  m['}'] = '{';
  m['<'] = '>';
  m['>'] = '<';
  string s;
  while (getline(cin, s)) {
    stack<int> a;
    int pos = 1, flag = 0;
    for (int i = 0; s[i]; i++) {
      if (s[i] == '(' && s[i + 1] == '*')
        a.push('(' * 100 + '*'), i++;
      else if (s[i] == '*' && s[i + 1] == ')') {
        if (!a.size() || a.top() != '(' * 100 + '*') {
          flag = 1;
          break;
        } else
          a.pop();
        i++;
      } else if (m[s[i]]) {
        if (isclosed(s[i])) {
          if (!a.size() || m[s[i]] != a.top()) {
            flag = 1;
            break;
          } else
            a.pop();
        } else
          a.push(s[i]);
      }
      pos++;
    }
    if (a.size() || flag)
      cout << "NO " << pos << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
