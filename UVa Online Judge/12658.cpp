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
    int n;
    while (cin >> n) {
        vi v;
        char a[5 + 1][4 * n + 1];
        for (int i = 1; i <= 5; i++)
            for (int j = 1; j <= 4 * n; j++) {
                cin >> a[i][j];
                if (i == 4) {
                    if (j % 4 == 1 && a[i][j] == '*') v.push_back(2);
                    if (j % 4 == 2 && a[i][j] == '*') v.push_back(1);
                    if (j % 4 == 3 && a[i][j] == '*') v.push_back(3);
                }
            }
        for (int i = 0; i < v.size(); i++) cout << v[i];
        cout << endl;
    }
    return 0;
}


