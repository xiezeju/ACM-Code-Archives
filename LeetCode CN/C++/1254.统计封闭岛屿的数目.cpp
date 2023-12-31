/*
 * @lc app=leetcode.cn id=1254 lang=cpp
 *
 * [1254] 统计封闭岛屿的数目
 *
 * https://leetcode.cn/problems/number-of-closed-islands/description/
 *
 * algorithms
 * Medium (64.03%)
 * Likes:    273
 * Dislikes: 0
 * Total Accepted:    59.7K
 * Total Submissions: 93.3K
 * Testcase Example:
 * '[[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]'
 *
 * 二维矩阵 grid 由 0 （土地）和 1 （水）组成。岛是由最大的4个方向连通的
 * 0 组成的群，封闭岛是一个 完全 由1包围（左、上、右、下）的岛。
 *
 * 请返回 封闭岛屿 的数目。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：grid =
 * [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
 * 输出：2
 * 解释：
 * 灰色区域的岛屿是封闭岛屿，因为这座岛屿完全被水域包围（即被 1 区域包围）。
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入：grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
 * 输出：1
 *
 *
 * 示例 3：
 *
 *
 * 输入：grid = [[1,1,1,1,1,1,1],
 * [1,0,0,0,0,0,1],
 * [1,0,1,1,1,0,1],
 * [1,0,1,0,1,0,1],
 * [1,0,1,1,1,0,1],
 * [1,0,0,0,0,0,1],
 * ⁠            [1,1,1,1,1,1,1]]
 * 输出：2
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= grid.length, grid[0].length <= 100
 * 0 <= grid[i][j] <=1
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int m, n;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        void dfs(vector<vector<int>>& grid, int x, int y) {
            if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 1) {
                return;
            }
            grid[x][y] = 1;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                dfs(grid, nx, ny);
            }
        }

        int closedIsland(vector<vector<int>>& grid) {
            m = grid.size();
            n = grid[0].size();
            for (int i = 0; i < m; i++) {
                if (i == 0 || i == m - 1) {
                    for (int j = 0; j < n; j++) {
                        if (grid[i][j] == 0) {
                            dfs(grid, i, j);
                        }
                    }

                } else {
                    if (grid[i][0] == 0) {
                        dfs(grid, i, 0);
                    }
                    if (grid[i][n - 1] == 0) {
                        dfs(grid, i, n - 1);
                    }
                }
            }
            int ans = 0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 0) {
                        dfs(grid, i, j);
                        ans++;
                    }
                }
            }
            return ans;
        }
};

// @lc code=end
