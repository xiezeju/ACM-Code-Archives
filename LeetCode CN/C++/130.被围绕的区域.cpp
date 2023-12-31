/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 *
 * https://leetcode.cn/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (46.29%)
 * Likes:    1038
 * Dislikes: 0
 * Total Accepted:    246.2K
 * Total Submissions: 532K
 * Testcase Example:
 * '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * 给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X'
 * 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：board =
 * [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
 * 输出：[["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
 * 解释：被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。
 * 任何不在边界上，或不与边界上的 'O' 相连的 'O'
 * 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
 *
 *
 * 示例 2：
 *
 *
 * 输入：board = [["X"]]
 * 输出：[["X"]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == board.length
 * n == board[i].length
 * 1
 * board[i][j] 为 'X' 或 'O'
 *
 *
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        void dfs(int m, int n, vector<vector<char>>& board, int x, int y,
                 vector<vector<bool>>& vis) {
            if (x < 0 || x >= m || y < 0 || y >= n || vis[x][y] ||
                board[x][y] == 'X') {
                return;
            }
            vis[x][y] = true;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                dfs(m, n, board, nx, ny, vis);
            }
        }

        void solve(vector<vector<char>>& board) {
            int m = board.size();
            int n = board[0].size();

            vector<vector<bool>> vis(m, vector<bool>(n));

            for (int i = 0; i < m; i++) {
                if (i == 0 || i == m - 1) {
                    for (int j = 0; j < n; j++) {
                        if (board[i][j] == 'O') {
                            dfs(m, n, board, i, j, vis);
                        }
                    }
                } else {
                    dfs(m, n, board, i, 0, vis);
                    dfs(m, n, board, i, n - 1, vis);
                }
            }
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (board[i][j] == 'O' && !vis[i][j]) {
                        board[i][j] = 'X';
                    }
                }
            }
        }
};

// @lc code=end
