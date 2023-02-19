#include <bits/stdc++.h>
using namespace std;
const int N = 1024 + 10;

int ans;
int pic[N][N];

void draw(const string& s, int& p, int r, int c, int w) {
  char ch = s[p++];
  if (ch == 'p') {
    draw(s, p, r, c + w / 2, w / 2);
    draw(s, p, r, c, w / 2);
    draw(s, p, r + w / 2, c, w / 2);
    draw(s, p, r + w / 2, c + w / 2, w / 2);
  } else if (ch == 'f') {
    for (int i = r; i < r + w; i++)
      for (int j = c; j < c + w; j++)
        if (pic[i][j] == 0) {
          pic[i][j] = 1;
          ans++;
        }
  }
}

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
    memset(pic, 0, sizeof(pic));
    ans = 0;
    for (int i = 0; i < 2; i++) {
      string s;
      cin >> s;
      int p = 0;
      draw(s, p, 0, 0, 32);
    }
    printf("There are %d black pixels.\n", ans);
  }

  return 0;
}