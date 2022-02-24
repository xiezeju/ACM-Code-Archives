#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 110;

int mv[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {1, 0}};
char c[maxn][maxn];
int main() {
    ios::sync_with_stdio(false);
    int m, n, x = 1;
    while (cin >> m >> n) {
        if (m == 0 && n == 0) break;
        if (x != 1)cout << endl;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++) {
                cin >> c[i][j];
                if (c[i][j] == '.') c[i][j] = '0';
            }
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (c[i][j] == '*')
                    for (int k = 0; k < 8; k++) {
                        int nx = i + mv[k][0];
                        int ny = j + mv[k][1];
                        if (nx >= 1 && ny >= 1 && nx <= m && ny <= n && c[nx][ny] != '*')
                            c[nx][ny] += 1;
                    }
        cout << "Field #" << x << ":" << endl;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++)
                cout << c[i][j];
            cout << endl;
        }
        x++;
    }
    return 0;
}


