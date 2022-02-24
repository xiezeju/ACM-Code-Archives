#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 30;

int mv[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {1, 0}};
char a[maxn][maxn];
int n;
bool vis[maxn][maxn];

void dfs(int x, int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 8; i++) {
        int nx = x + mv[i][0];
        int ny = y + mv[i][1];
        if (nx >= 1 && ny >= 1 && nx <= n && ny <= n && !vis[nx][ny])
            dfs(nx, ny);
    }
}

int main() {
    ios::sync_with_stdio(false);
    int x = 1;
    while (cin >> n) {
        int ans = 0;
        memset(vis, 0, sizeof vis);
        memset(a, 0, sizeof a);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
                if (a[i][j] == '0') vis[i][j] = 1;
            }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (a[i][j] == '1' && !vis[i][j]) {
                    ++ans;
                    dfs(i, j);
                }
        cout << "Image number " << x << " contains " << ans << " war eagles." << endl;
        x++;
    }
    return 0;
}


