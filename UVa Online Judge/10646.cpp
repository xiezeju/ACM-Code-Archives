/* ��52�����۵��ƣ�������ȡ2���������e��Ȼ������������²�����

            ��ȡ��������Ƶ�����ֵX��2~9��ľ���10����

            �ڼӵ�Y�ϣ���ʼ��0����

            ���ӵ���������ƣ����ӵ������10-X���ƣ�

            Ȼ���ڰ����ϵ��ƷŻص��ƶѵ����棬���������ϔ��ĵ�Y������ʲ�N��*/
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


