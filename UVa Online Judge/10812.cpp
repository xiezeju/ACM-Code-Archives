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
    int n; cin >> n;
    while (n--) {
        int s, d; cin >> s >> d;
        if (s < d||(s+d)%2) cout << "impossible" << endl;
        else {
            int m = (s + d) / 2;
            int n = s - m;
            cout << m << " " << n << endl;
        }
    }
    return 0;
}


