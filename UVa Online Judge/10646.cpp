/* 有52張倒扣的牌，從上面取2張放在手裡，然後執行三次如下操作：

            ①取最上面的牌的牌面值X（2~9外的均為10）；

            ②加到Y上（初始為0）；

            ③扔掉最上面的牌，再扔掉上面的10-X張牌；

            然後在把手上的牌放回到牌堆的上面，問從下向上數的第Y張牌是什麼。*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;

struct pai {
    char a, b;

} p1[55], p2[26];


int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    int g = 1;
    while (t--) {
        for (int i = 1; i <= 27; i++)cin >> p1[i].a >> p1[i].b;
        for (int i = 1; i <= 25; i++)cin >> p2[i].a >> p2[i].b;
        int top = 27, y = 0, x = 0;
        for (int i = 1; i <= 3; i++) {
            if (p1[top].a >= '1' && p1[top].a <= '9')
                x = p1[top].a - '0';
            else x = 10;
            y += x;
            for (int j = 10 - x; j >= 0; --j) top--;
        }

        for (int i = 1; i <= 25; i++) {
            p1[++top].a = p2[i].a;
            p1[top].b = p2[i].b;
        }

        cout << "Case " << g++ << ": " << p1[y].a << p1[y].b << endl;
    }
    return 0;
}


