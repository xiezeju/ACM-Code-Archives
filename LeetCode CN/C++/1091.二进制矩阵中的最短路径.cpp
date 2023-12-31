/*
 * @lc app=leetcode.cn id=1091 lang=cpp
 *
 * [1091] 二进制矩阵中的最短路径
 *
 * https://leetcode.cn/problems/shortest-path-in-binary-matrix/description/
 *
 * algorithms
 * Medium (40.39%)
 * Likes:    347
 * Dislikes: 0
 * Total Accepted:    79.7K
 * Total Submissions: 197.2K
 * Testcase Example:  '[[0,1],[1,0]]'
 *
 * 给你一个 n x n 的二进制矩阵 grid 中，返回矩阵中最短 畅通路径
 * 的长度。如果不存在这样的路径，返回 -1 。
 *
 * 二进制矩阵中的 畅通路径 是一条从 左上角 单元格（即，(0, 0)）到 右下角
 * 单元格（即，(n - 1, n - 1)）的路径，该路径同时满足下述要求：
 *
 *
 * 路径途经的所有单元格的值都是 0 。
 * 路径中所有相邻的单元格应当在 8 个方向之一
 * 上连通（即，相邻两单元之间彼此不同且共享一条边或者一个角）。
 *
 *
 * 畅通路径的长度 是该路径途经的单元格总数。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：grid = [[0,1],[1,0]]
 * 输出：2
 *
 *
 * 示例 2：
 *
 *
 * 输入：grid = [[0,0,0],[1,1,0],[1,1,0]]
 * 输出：4
 *
 *
 * 示例 3：
 *
 *
 * 输入：grid = [[1,0,0],[1,1,0],[1,1,0]]
 * 输出：-1
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == grid.length
 * n == grid[i].length
 * 1 <= n <= 100
 * grid[i][j] 为 0 或 1
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
            int n = grid.size();
            if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
                return -1;
            }

            vector<vector<int>> vis(n, vector<int>(n, -1));

            vis[0][0] = 1;

            queue<pair<int, int>> q;
            q.push({0, 0});

            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();

                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        int nx = x + dx;
                        int ny = y + dy;

                        if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                            vis[nx][ny] == -1 && grid[nx][ny] == 0) {
                            vis[nx][ny] = vis[x][y] + 1;
                            q.push({nx, ny});
                        }
                    }
                }
            }

            return vis[n - 1][n - 1];
        }
};

// @lc code=end
