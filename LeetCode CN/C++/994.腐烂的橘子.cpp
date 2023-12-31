/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 *
 * https://leetcode.cn/problems/rotting-oranges/description/
 *
 * algorithms
 * Medium (51.08%)
 * Likes:    766
 * Dislikes: 0
 * Total Accepted:    129.9K
 * Total Submissions: 254.2K
 * Testcase Example:  '[[2,1,1],[1,1,0],[0,1,1]]'
 *
 * 在给定的 m x n 网格 grid 中，每个单元格可以有以下三个值之一：
 *
 *
 * 值 0 代表空单元格；
 * 值 1 代表新鲜橘子；
 * 值 2 代表腐烂的橘子。
 *
 *
 * 每分钟，腐烂的橘子 周围 4 个方向上相邻 的新鲜橘子都会腐烂。
 *
 * 返回
 * 直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：grid = [[2,1,1],[1,1,0],[0,1,1]]
 * 输出：4
 *
 *
 * 示例 2：
 *
 *
 * 输入：grid = [[2,1,1],[0,1,1],[1,0,1]]
 * 输出：-1
 * 解释：左下角的橘子（第 2 行， 第 0 列）永远不会腐烂，因为腐烂只会发生在 4
 * 个正向上。
 *
 *
 * 示例 3：
 *
 *
 * 输入：grid = [[0,2]]
 * 输出：0
 * 解释：因为 0 分钟时已经没有新鲜橘子了，所以答案就是 0 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 10
 * grid[i][j] 仅为 0、1 或 2
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int orangesRotting(vector<vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();

            queue<tuple<int, int, int>> q;

            vector<vector<int>> times(m, vector<int>(n, -1));

            int cnt = 0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 1) {
                        cnt++;
                    }

                    if (grid[i][j] == 2) {
                        q.push({0, i, j});
                        times[i][j] = 0;
                    }
                }
            }

            int dx[4] = {0, 0, 1, -1};
            int dy[4] = {1, -1, 0, 0};

            while (!q.empty()) {
                auto [t, x, y] = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n ||
                        grid[nx][ny] != 1) {
                        continue;
                    }
                    cnt--;
                    grid[nx][ny] = 2;
                    times[nx][ny] = t + 1;
                    q.push({t + 1, nx, ny});
                }
            }
            if (cnt != 0) {
                return -1;
            }

            int ans = 0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    ans = max(ans, times[i][j]);
                }
            }

            return ans;
        }
};

// @lc code=end
