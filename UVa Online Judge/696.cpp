#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;

int f(int n, int m) {
    if (n < m) return f(m, n);
    else if (m == 1) return  n;
    else if (m == 2)
        return (n / 4) * 4 + ((n % 4 > 1) ? 2 : n % 4) * 2;
    else return (n * m + 1) / 2;
}


int main() {
    ios::sync_with_stdio(false);
    int r, c;
    while (scanf("%d%d", &r, &c), r + c)
        printf("%d knights may be placed on a %d row %d column board.\n", f(r, c), r, c);
    return 0;
}


