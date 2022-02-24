#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    cin.ignore();
    while (n--)
    {
        stack<char> s;
        string str;
        int flag = 0;
        getline(cin, str);
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '[' || str[i] == '(')
                s.push(str[i]);
            else if (!s.empty() && s.top() == '(' && str[i] == ')')
                s.pop();
            else if (!s.empty() && s.top() == '[' && str[i] == ']')
                s.pop();
            else
                flag = 1;
        }
        if (!flag && !s.size())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}