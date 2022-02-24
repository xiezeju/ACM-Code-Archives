#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;
const int maxn = 2e6 + 10;


class UnionFind {

private:
    vi p, ranks, Size;
public:
    UnionFind(int N) {
        p.assign(N+1, 0);for (int i = 0; i <= N; i++) p[i] = i;
        ranks.assign(N+1, 0);
        Size.assign(N+1, 1);
    }
    int find(int i) {return p[i] == i ? i : p[i] = find(p[i]);}
    bool same(int i, int j) {return find(i) == find(j);}
    int size(int i) {return Size[find(i)];}

    void unionset(int i, int j) {
        if (same(i, j)) return;
        int x = find(i), y = find(j);
        p[x] = y;
        Size[y] += Size[x];
    }
};



int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        UnionFind s(n);
        int Max = -1;
        int p, q;
        for (int i = 0; i < m; i++) {
            cin >> p >> q;
            s.unionset(p, q);
        }
        for (int i = 0; i < n; i++) {
            if (Max < s.size(i)) Max = s.size(i);
        }
        cout << Max << endl;
    }
    return 0;
}
