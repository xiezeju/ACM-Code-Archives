#include <bits/stdc++.h>
using namespace std;
struct Node {
  string name;
  int pl;
};

int main(void) {
  vector<Node> stu;
  int n;
  cin >> n;
  string name;
  for (int i = 1; i <= n; i++) {
    cin >> name;
    if (name == "?")
      ;
    else
      stu.push_back((Node){name, i});
  }
  int m, k;
  cin >> m;
  while (m--) {
    cin >> k;
    bool isprinted = false;
    for (int i = 0; i < (int)stu.size(); i++) {
      if (stu[i].pl == k) {
        cout << stu[i].name << endl;
        isprinted = true;
      } else if (stu[i].pl > k) {
        if (i == 0) {
          for (int j = 0; j < stu[i].pl - k; j++) cout << "left of ";
          cout << stu[i].name << endl;
        } else {
          int mi = stu[i - 1].pl + stu[i].pl;
          if (mi % 2 == 0 && k == mi / 2) {
            cout << "middle of ";
            cout << stu[i - 1].name;
            cout << " and ";
            cout << stu[i].name << endl;
          } else if (k <= mi / 2) {
            for (int j = stu[i - 1].pl; j < k; j++) cout << "right of ";
            cout << stu[i - 1].name << endl;
          } else {
            for (int j = k; j < stu[i].pl; j++) cout << "left of ";
            cout << stu[i].name << endl;
          }
        }
        isprinted = true;
      }
      if (isprinted) break;
    }
    if (!isprinted) {
      for (int j = stu[stu.size() - 1].pl; j < k; j++) cout << "right of ";
      cout << stu[stu.size() - 1].name << endl;
    }
  }
  return 0;
}
