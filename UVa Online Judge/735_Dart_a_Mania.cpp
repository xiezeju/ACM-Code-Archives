#include <iostream>
#include <set>
#include <vector>

#define INF 1000000000
using namespace std;

void dfs(int x, int depth, int score, int& cnt, set<int>& se, vector<int>& v,
         set<set<int>>& sese) {
  v.push_back(x);
  score -= x;
  if (depth == 3 && score == 0) {
    cnt++;
    set<int> tmp;
    for (auto&& i : v) tmp.insert(i);
    sese.insert(tmp);
  }
  if (depth == 3 || score < 0) {
    v.pop_back();
    return;
  }
  for (auto&& i : se) dfs(i, depth + 1, score, cnt, se, v, sese);
  v.pop_back();
}

int main() {
  set<int> se;
  for (int i = 1; i <= 20; i++)
    for (int j = 1; j <= 3; j++) se.insert(i * j);
  se.insert(0);
  se.insert(50);
  int n;
  while (cin >> n, n > 0) {
    int cnt = 0;
    vector<int> v;
    set<set<int>> sese;
    dfs(0, 0, n, cnt, se, v, sese);
    if (cnt == 0) {
      cout << "THE SCORE OF " << n << " CANNOT BE MADE WITH THREE DARTS."
           << endl;
    } else {
      cout << "NUMBER OF COMBINATIONS THAT SCORES " << n << " IS "
           << sese.size() << "." << endl;
      cout << "NUMBER OF PERMUTATIONS THAT SCORES " << n << " IS " << cnt << "."
           << endl;
    }
    cout << "******************************************************************"
            "****"
         << endl;
  }
  cout << "END OF OUTPUT" << endl;
}