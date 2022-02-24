#include <bits/stdc++.h>
using namespace std;

int32_t main()
{

#ifdef Online_Judge
    freopen("INPUT.in", "r", stdin);
    freopen("OUTPUT.out", "w", stdout);
#endif

    string s;
    set<string> a;
    while (cin >> s)
    {
        for (int i = 0; i < s.size(); i++)
            if (isalpha(s[i]))
                s[i] = tolower(s[i]);
            else
                s[i] = ' ';
        stringstream ss(s);
        while (ss >> s)
            a.insert(s);
    }
    for (auto i : a)
        cout << i << endl;
    return 0;
}