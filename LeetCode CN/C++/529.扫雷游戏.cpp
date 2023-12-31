/*
 * @lc app=leetcode.cn id=529 lang=cpp
 *
 * [529] 扫雷游戏
 *
 * https://leetcode.cn/problems/minesweeper/description/
 *
 * algorithms
 * Medium (63.97%)
 * Likes:    356
 * Dislikes: 0
 * Total Accepted:    53.2K
 * Total Submissions: 83.2K
 * Testcase Example:
 '[["E","E","E","E","E"],["E","E","M","E","E"],["E","E","E","E","E"],["E","E","E","E","E"]]\n'
 +
  '[3,0]'
 *
 * 让我们一起来玩扫雷游戏！
 *
 * 给你一个大小为 m x n 二维字符矩阵 board ，表示扫雷游戏的盘面，其中：
 *
 *
 * 'M' 代表一个 未挖出的 地雷，
 * 'E' 代表一个 未挖出的 空方块，
 * 'B' 代表没有相邻（上，下，左，右，和所有4个对角线）地雷的 已挖出的 空白方块，
 * 数字（'1' 到 '8'）表示有多少地雷与这块 已挖出的 方块相邻，
 * 'X' 则表示一个 已挖出的 地雷。
 *
 *
 * 给你一个整数数组 click ，其中 click = [clickr, clickc] 表示在所有 未挖出的
 方块（'M' 或者
 * 'E'）中的下一个点击位置（clickr 是行下标，clickc 是列下标）。
 *
 * 根据以下规则，返回相应位置被点击后对应的盘面：
 *
 *
 * 如果一个地雷（'M'）被挖出，游戏就结束了- 把它改为 'X' 。
 * 如果一个 没有相邻地雷
 的空方块（'E'）被挖出，修改它为（'B'），并且所有和其相邻的 未挖出
 方块都应该被递归地揭露。
 * 如果一个 至少与一个地雷相邻 的空方块（'E'）被挖出，修改它为数字（'1' 到 '8'
 ），表示相邻地雷的数量。
 * 如果在此次点击中，若无更多方块可被揭露，则返回盘面。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：board =
 * [["E","E","E","E","E"],["E","E","M","E","E"],["E","E","E","E","E"],["E","E","E","E","E"]],
 * click = [3,0]
 *
 * 输出：[["B","1","E","1","B"],["B","1","M","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：board =
 * [["B","1","E","1","B"],["B","1","M","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]],
 * click = [1,2]
 *
 * 输出：[["B","1","E","1","B"],["B","1","X","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == board.length
 * n == board[i].length
 * 1 <= m, n <= 50
 * board[i][j] 为 'M'、'E'、'B' 或数字 '1' 到 '8' 中的一个
 * click.length == 2
 * 0 <= clickr < m
 * 0 <= clickc < n
 * board[clickr][clickc] 为 'M' 或 'E'
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
        int dy[8] = {1, -1, 0, 1, -1, 0, 1, -1};

        vector<vector<char>> updateBoard(vector<vector<char>>& board,
                                         vector<int>&          click) {
            int st = click[0];
            int ed = click[1];
            if (board[st][ed] == 'M') {
                board[st][ed] = 'X';
                return board;
            }
            int m = board.size();
            int n = board[0].size();

            vector<vector<bool>>  vis(m, vector<bool>(n));
            queue<pair<int, int>> q;
            q.emplace(st, ed);
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                vector<pair<int, int>> a;
                int                    cnt = 0;

                for (int i = 0; i < 8; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (!(nx >= 0 && nx < m && ny >= 0 && ny < n))
                        continue;
                    if (board[nx][ny] == 'M') {
                        cnt++;
                        continue;
                    }
                    if (board[nx][ny] == 'E')
                        a.emplace_back(nx, ny);
                }
                if (cnt)
                    board[x][y] = cnt + '0';
                else {
                    board[x][y] = 'B';
                    for (auto& [nx, ny] : a) {
                        if (vis[nx][ny])
                            continue;
                        q.emplace(nx, ny);
                        vis[nx][ny] = true;
                    }
                }
            }

            return board;
        }
};

// @lc code=end
