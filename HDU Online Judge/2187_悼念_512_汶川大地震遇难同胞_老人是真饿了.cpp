#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
struct food {
  int p, w;
};
food my[1010];
bool comp(food a, food b) { return a.p < b.p; }
int main() {
  int c;
  cin >> c;
  while (c--) {
    double n;
    int m;
    cin >> n >> m;
    int i = 0, j;
    while (i < m) {
      cin >> my[i].p >> my[i].w;
      i++;
    }
    sort(my, my + m, comp);
    double sum = 0, count = 0;
    for (i = 0; i < m; i++) {
      if (n >= my[i].p * my[i].w) {
        sum = sum + my[i].w;
        n = n - my[i].p * my[i].w;
      } else {
        sum = sum + n * 1.0 / my[i].p;
        break;
      }
    }
    printf("%.2f\n", sum);
  }
  return 0;
}