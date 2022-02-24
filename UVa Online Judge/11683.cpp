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
    int a, c;
    while (cin >> a) {
        if (a == 0) break;
        cin >> c;
        int x, ans = 0, p = a;
        for (int i = 0 ; i < c; i++) {
            cin >> x;
            if (x < p)
                ans += p - x;
            p = x;
        }
        cout << ans << endl;
    }
    return 0;
}


