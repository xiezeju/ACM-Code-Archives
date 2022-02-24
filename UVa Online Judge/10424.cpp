#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;




char name1[30];
char name2[30];

int value(char c) {
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 1;
    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 1;
    return 0;
}

int bits(char* s) {
    int sum = 0;
    for (int i = 0 ; s[i] ; ++ i)
        sum += value(s[i]);
    while (sum > 9) {
        int temp = 0;
        while (sum) {
            temp += sum % 10;
            sum /= 10;
        }
        sum = temp;
    }
    return sum;
}

int main() {
    while (gets(name1) && gets(name2)) {
        double p = 1.0 * bits(name1) / bits(name2);
        if (p > 1.0) p = 1.0 / p;
        printf("%.2lf %%\n", 100 * p);
    }
    return 0;
}
