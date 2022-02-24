#include <bits/stdc++.h>
using namespace std;

inline bool later(int *seq, int src, int cmp) {
    return find(seq, seq + 25, src) > find(seq, seq + 25, cmp);
}

int main() {
    int n, a[25], b[25];
    while (~scanf("%d", &n)) {
        int inv = 0;
        for (int i = 0; i < n; ++i)
            scanf("%d", a + i);
        for (int i = 0; i < n; ++i)
            scanf("%d", b + i);
        for (int i = 0; i < n - 1; ++i)
            for (int j = i + 1; j < n; ++j)
                inv += later(a, b[i], b[j]);
        printf("%d\n", inv);
    }
}
