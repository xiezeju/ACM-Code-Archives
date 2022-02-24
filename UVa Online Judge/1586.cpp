#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;


int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        char c[2];
        int x, a[5] = {};
        double ans;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == 'C') {
                if (!isdigit(s[i + 1])) a[1]++;
                else if (isdigit(s[i + 1])) {
                    c[0] = s[i + 1];
                    if (isdigit(s[i + 2])) {
                        c[1] = s[i + 2];
                        x = 10 * c[0] + c[1] - 11 * '0';
                    } else x = c[0] - '0';
                    a[1] += x;
                }
            }
            if (s[i] == 'H') {
                if (!isdigit(s[i + 1])) a[2]++;
                else if (isdigit(s[i + 1])) {
                    c[0] = s[i + 1];
                    if (isdigit(s[i + 2])) {
                        c[1] = s[i + 2];
                        x = 10 * c[0] + c[1] - 11 * '0';
                    } else x = c[0] - '0';
                    a[2] += x;
                }
            }
            if (s[i] == 'O') {
                if (!isdigit(s[i + 1])) a[3]++;
                else if (isdigit(s[i + 1])) {
                    c[0] = s[i + 1];
                    if (isdigit(s[i + 2])) {
                        c[1] = s[i + 2];
                        x = 10 * c[0] + c[1] - 11 * '0';
                    } else x = c[0] - '0';
                    a[3] += x;
                }
            }
            if (s[i] == 'N') {
                if (!isdigit(s[i + 1])) a[4]++;
                else if (isdigit(s[i + 1])) {
                    c[0] = s[i + 1];
                    if (isdigit(s[i + 2])) {
                        c[1] = s[i + 2];
                        x = 10 * c[0] + c[1] - 11 * '0';
                    } else x = c[0] - '0';
                    a[4] += x;
                }
            }
        }
        int q = s.size() - 1;
        if (!isdigit(s[q])) {
            if (s[q] == 'C') a[1]++;
            if (s[q] == 'H') a[2]++;
            if (s[q] == 'O') a[3]++;
            if (s[q] == 'N') a[4]++;
        }
        ans = 12.01*a[1]+1.008*a[2]+16.00*a[3]+14.01*a[4];
        printf("%.3lf\n",ans);
    }
    return 0;
}


