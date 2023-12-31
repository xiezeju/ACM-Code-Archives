/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 *
 * https://leetcode.cn/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (59.65%)
 * Likes:    2327
 * Dislikes: 0
 * Total Accepted:    716.8K
 * Total Submissions: 1.2M
 * Testcase Example:
 * '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * 给你一个由 '1'（陆地）和
 * '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
 *
 * 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
 *
 * 此外，你可以假设该网格的四条边均被水包围。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：grid = [
 * ⁠ ["1","1","1","1","0"],
 * ⁠ ["1","1","0","1","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","0","0","0"]
 * ]
 * 输出：1
 *
 *
 * 示例 2：
 *
 *
 * 输入：grid = [
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","1","0","0"],
 * ⁠ ["0","0","0","1","1"]
 * ]
 * 输出：3
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1
 * grid[i][j] 的值为 '0' 或 '1'
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int ans = 0;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        void dfs(int m, int n, vector<vector<char>>& grid, int x, int y) {
            if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '0') {
                return;
            }
            grid[x][y] = '0';
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                dfs(m, n, grid, nx, ny);
            }
        }

        int numIslands(vector<vector<char>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == '1') {
                        ans++;
                        dfs(m, n, grid, i, j);
                    }
                }
            }
            return ans;
        }
};

// @lc code=end
