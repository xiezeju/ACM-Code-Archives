/*
 * @lc app=leetcode.cn id=1020 lang=cpp
 *
 * [1020] 飞地的数量
 *
 * https://leetcode.cn/problems/number-of-enclaves/description/
 *
 * algorithms
 * Medium (62.00%)
 * Likes:    239
 * Dislikes: 0
 * Total Accepted:    66.1K
 * Total Submissions: 106.7K
 * Testcase Example:  '[[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]'
 *
 * 给你一个大小为 m x n 的二进制矩阵 grid ，其中 0 表示一个海洋单元格、1
 * 表示一个陆地单元格。
 *
 * 一次 移动
 * 是指从一个陆地单元格走到另一个相邻（上、下、左、右）的陆地单元格或跨过 grid
 * 的边界。
 *
 * 返回网格中 无法 在任意次数的移动中离开网格边界的陆地单元格的数量。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
 * 输出：3
 * 解释：有三个 1 被 0 包围。一个 1 没有被包围，因为它在边界上。
 *
 *
 * 示例 2：
 *
 *
 * 输入：grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
 * 输出：0
 * 解释：所有 1 都在边界上或可以到达边界。
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 500
 * grid[i][j] 的值为 0 或 1
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
            if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0) {
                return;
            }
            grid[x][y] = 0;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                dfs(grid, nx, ny);
            }
        }

        int numEnclaves(vector<vector<int>>& grid) {
            m = grid.size();
            n = grid[0].size();
            for (int i = 0; i < m; i++) {
                if (i == 0 || i == m - 1) {
                    for (int j = 0; j < n; j++) {
                        if (grid[i][j] == 1) {
                            dfs(grid, i, j);
                        }
                    }

                } else {
                    if (grid[i][0] == 1) {
                        dfs(grid, i, 0);
                    }
                    if (grid[i][n - 1] == 1) {
                        dfs(grid, i, n - 1);
                    }
                }
            }
            int ans = 0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 1) {
                        ans++;
                    }
                }
            }
            return ans;
        }
};

// @lc code=end
