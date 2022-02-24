#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;


int reserves[22];
int main() {
    ios::sync_with_stdio(false);
    int b, n, from, to, value;
    while (~scanf("%d%d", &b, &n) && n + b) {
        for (int i = 1; i <= b; ++ i)
            scanf("%d", &reserves[i]);
        for (int i = 1; i <= n; ++ i) {
            scanf("%d%d%d", &from, &to, &value);
            reserves[from] -= value;
            reserves[to] += value;
        }
        int flag = 1;
        for (int i = 1; i <= b; ++ i) {
            if (reserves[i] < 0) {
                flag = 0;
                break;
            }
        }
        if (flag)
            puts("S");

        else
            puts("N");
    }
    return 0;
}

