/*
 * @lc app=leetcode.cn id=1631 lang=cpp
 *
 * [1631] 最小体力消耗路径
 *
 * https://leetcode.cn/problems/path-with-minimum-effort/description/
 *
 * algorithms
 * Medium (50.91%)
 * Likes:    385
 * Dislikes: 0
 * Total Accepted:    45.3K
 * Total Submissions: 89K
 * Testcase Example:  '[[1,2,2],[3,8,2],[5,3,5]]'
 *
 * 你准备参加一场远足活动。给你一个二维 rows x
 * columns 的地图 heights ，其中 heights[row][col] 表示格子 (row,
 * col) 的高度。一开始你在最左上角的格子 (0,
 * 0) ，且你希望去最右下角的格子 (rows-1, columns-1) （注意下标从 0
 * 开始编号）。你每次可以往 上，下，左，右 四个方向之一移动，你想要找到耗费 体力
 * 最小的一条路径。
 *
 * 一条路径耗费的 体力值 是路径上相邻格子之间 高度差绝对值 的 最大值 决定的。
 *
 * 请你返回从左上角走到右下角的最小 体力消耗值 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：heights = [[1,2,2],[3,8,2],[5,3,5]]
 * 输出：2
 * 解释：路径 [1,3,5,3,5] 连续格子的差值绝对值最大为 2 。
 * 这条路径比路径 [1,2,2,2,5] 更优，因为另一条路径差值最大值为 3 。
 *
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入：heights = [[1,2,3],[3,8,4],[5,3,5]]
 * 输出：1
 * 解释：路径 [1,2,3,4,5] 的相邻格子差值绝对值最大为 1 ，比路径 [1,3,5,3,5]
 * 更优。
 *
 *
 * 示例 3：
 *
 *
 * 输入：heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
 * 输出：0
 * 解释：上图所示路径不需要消耗任何体力。
 *
 *
 *
 *
 * 提示：
 *
 *
 * rows == heights.length
 * columns == heights[i].length
 * 1
 * 1
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int minimumEffortPath(vector<vector<int>>& heights) {
            int m = heights.size();
            int n = heights[0].size();

            typedef tuple<int, int, int> Node;

            vector<vector<int>> dis(m, vector<int>(n, 0x3f3f3f3f));
            priority_queue<Node, vector<Node>, greater<Node>> q;

            dis[0][0] = 0;
            q.push({0, 0, 0});

            int dx[4] = {0, 0, 1, -1};
            int dy[4] = {1, -1, 0, 0};

            while (!q.empty()) {
                auto [d, x, y] = q.top();
                q.pop();

                if (x == m - 1 && y == n - 1) {
                    return dis[x][y];
                }

                if (dis[x][y] < d) {
                    continue;
                }

                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                        continue;
                    }

                    int sum = abs(heights[x][y] - heights[nx][ny]);

                    if (dis[nx][ny] > max(d, sum)) {
                        dis[nx][ny] = max(d, sum);
                        q.push({dis[nx][ny], nx, ny});
                    }
                }
            }

            return 0;
        }
};

// @lc code=end
