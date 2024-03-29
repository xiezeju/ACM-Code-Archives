/*
 * @lc app=leetcode.cn id=980 lang=cpp
 *
 * [980] 不同路径 III
 *
 * https://leetcode.cn/problems/unique-paths-iii/description/
 *
 * algorithms
 * Hard (78.24%)
 * Likes:    333
 * Dislikes: 0
 * Total Accepted:    36.1K
 * Total Submissions: 46.1K
 * Testcase Example:  '[[1,0,0,0],[0,0,0,0],[0,0,2,-1]]'
 *
 * 在二维网格 grid 上，有 4 种类型的方格：
 *
 *
 * 1 表示起始方格。且只有一个起始方格。
 * 2 表示结束方格，且只有一个结束方格。
 * 0 表示我们可以走过的空方格。
 * -1 表示我们无法跨越的障碍。
 *
 *
 * 返回在四个方向（上、下、左、右）上行走时，从起始方格到结束方格的不同路径的数目。
 *
 * 每一个无障碍方格都要通过一次，但是一条路径中不能重复通过同一个方格。
 *
 *
 *
 * 示例 1：
 *
 * 输入：[[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
 * 输出：2
 * 解释：我们有以下两条路径：
 * 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
 * 2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
 *
 * 示例 2：
 *
 * 输入：[[1,0,0,0],[0,0,0,0],[0,0,0,2]]
 * 输出：4
 * 解释：我们有以下四条路径：
 * 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
 * 2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
 * 3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
 * 4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
 *
 * 示例 3：
 *
 * 输入：[[0,1],[2,0]]
 * 输出：0
 * 解释：
 * 没有一条路能完全穿过每一个空的方格一次。
 * 请注意，起始和结束方格可以位于网格中的任意位置。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= grid.length * grid[0].length <= 20
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int ans = 0;
        int cnt = 1;
        int sx, sy;

        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {1, -1, 0, 0};

        void dfs(int m, int n, vector<vector<int>>& grid, int x, int y,
                 int step) {
            if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == -1) {
                return;
            }

            if (grid[x][y] == 2) {
                if (step == 0) {
                    ans++;
                }

                return;
            }

            grid[x][y] = -1;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                dfs(m, n, grid, nx, ny, step - 1);
            }

            grid[x][y] = 0;
        }

        int uniquePathsIII(vector<vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] != -1) {
                        if (grid[i][j] == 1) {
                            sx = i, sy = j;
                        } else if (grid[i][j] == 0) {
                            cnt++;
                        }
                    }
                }
            }
            dfs(m, n, grid, sx, sy, cnt);
            return ans;
        }
};

// @lc code=end
