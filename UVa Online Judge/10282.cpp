#include <bits/stdc++.h>
using namespace std;

int32_t main()
{

#ifdef Online_Judge
    freopen("INPUT.in", "r", stdin);
    freopen("OUTPUT.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0);

    string s, s1, s2;
    map<string, string> a;
    while (getline(cin, s) && s.size())
    {
        stringstream ss(s);
        while (ss >> s1 >> s2)
        {

            a[s2] = s1;
        }
    }
    while (cin >> s)
    {
        if (a.count(s))
            cout << a[s] << endl;
        else
            cout << "eh" << endl;
    }

    return 0;
}