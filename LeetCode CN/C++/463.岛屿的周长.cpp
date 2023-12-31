/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
 *
 * https://leetcode.cn/problems/island-perimeter/description/
 *
 * algorithms
 * Easy (69.99%)
 * Likes:    705
 * Dislikes: 0
 * Total Accepted:    141.4K
 * Total Submissions: 201.9K
 * Testcase Example:  '[[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]'
 *
 * 给定一个 row x col 的二维网格地图 grid ，其中：grid[i][j] = 1 表示陆地，
 * grid[i][j] = 0 表示水域。
 *
 * 网格中的格子 水平和垂直
 * 方向相连（对角线方向不相连）。整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。
 *
 * 岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1
 * 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
 * 输出：16
 * 解释：它的周长是上面图片中的 16 个黄色的边
 *
 * 示例 2：
 *
 *
 * 输入：grid = [[1]]
 * 输出：4
 *
 *
 * 示例 3：
 *
 *
 * 输入：grid = [[1,0]]
 * 输出：4
 *
 *
 *
 *
 * 提示：
 *
 *
 * row == grid.length
 * col == grid[i].length
 * 1
 * grid[i][j] 为 0 或 1
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int adj = 0, num = 0;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        int m, n;

        vector<vector<bool>> vis;

        void dfs(vector<vector<int>>& grid, int x, int y,
                 vector<vector<bool>>& vis) {

            num++;

            vis[x][y] = true;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n ||
                    grid[nx][ny] == 0) {
                    continue;
                }
                adj++;
                if (vis[nx][ny]) {
                    continue;
                }

                dfs(grid, nx, ny, vis);
            }
        }

        int islandPerimeter(vector<vector<int>>& grid) {
            m = grid.size();
            n = grid[0].size();
            vis.resize(m, vector<bool>(n));
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 1 && !vis[i][j]) {
                        dfs(grid, i, j, vis);
                    }
                }
            }
            return 4 * num - adj;
        }
};

// @lc code=end
