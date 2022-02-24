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
const int N = 30;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a, b, c, d;
    for (a = 8; a <= 125; a++)
        for (b = a; b <= 2000; b++)
            for (c = b; c <= 2000; c++)
                if (a * b * c > 1000000) {
                    d = 1000000 * (a + b + c) / (a * b * c - 1000000);
                    if (c <= d && a + b + c + d <= 2000 &&
                        1000000 * (a + b + c + d) == a * b * c * d)
                        printf("%.2lf %.2lf %.2lf %.2lf\n", a / 100.0, b / 100.0, c / 100.0,
                               d / 100.0);
                }

    return 0;
}
