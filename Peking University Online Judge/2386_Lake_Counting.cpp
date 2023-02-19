#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
int N, M;
#define MAX 100
char field[MAX][MAX];

void dfs(int i, int j) {
  field[i][j] = '.';
  for (int dx = -1; dx <= 1; dx++) {
    for (int dy = -1; dy <= 1; dy++) {
      int nx = i + dx;
      int ny = j + dy;
      if (nx >= 0 && nx < N && ny >= 0 && ny < M && field[nx][ny] == 'W')
        dfs(nx, ny);
    }
  }
}

int main() {
  int ans = 0;
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> field[i][j];
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (field[i][j] == 'W') {
        dfs(i, j);
        ans++;
      }
    }
  }
  printf("%d", ans);
  return 0;
}