#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

char maps[55][55];
int dxy[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};

bool in_map(int x, int y, int row, int column) {
  return x >= 0 && x < row && y >= 0 && y < column;
}
int dfs(int x, int y, int row, int column) {
  int sum = 0;
  if (in_map(x, y, row, column) == false || maps[x][y] == '#') {
    return sum;
  }

  sum = maps[x][y] == 'G';
  maps[x][y] = '#';

  int stop = false;
  for (int i = 0; i < 4; ++i) {
    if (in_map(x + dxy[i][0], y + dxy[i][1], row, column) == true &&
        maps[x + dxy[i][0]][y + dxy[i][1]] == 'T') {
      stop = true;
    }
  }
  if (stop == true) {
    return sum;
  }

  for (int i = 0; i < 4; ++i) {
    sum += dfs(x + dxy[i][0], y + dxy[i][1], row, column);
  }
  return sum;
}

int main() {
  int row, column;
  while (~scanf("%d%d", &column, &row)) {
    for (int i = 0; i < row; ++i) {
      scanf("%s", maps[i]);
    }

    // 寻找起点开始搜索
    int find_p = false;
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < column; ++j) {
        if (maps[i][j] == 'P') {
          printf("%d\n", dfs(i, j, row, column));
          find_p = true;
          break;
        }
      }
      if (find_p == true) break;
    }
  }
  return 0;
}
