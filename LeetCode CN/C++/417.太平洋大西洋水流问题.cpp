/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 *
 * https://leetcode.cn/problems/pacific-atlantic-water-flow/description/
 *
 * algorithms
 * Medium (56.20%)
 * Likes:    640
 * Dislikes: 0
 * Total Accepted:    88.3K
 * Total Submissions: 157.2K
 * Testcase Example:
 * '[[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]'
 *
 * 有一个 m × n 的矩形岛屿，与 太平洋 和 大西洋
 * 相邻。 “太平洋” 处于大陆的左边界和上边界，而 “大西洋”
 * 处于大陆的右边界和下边界。
 *
 * 这个岛被分割成一个由若干方形单元格组成的网格。给定一个 m x n
 * 的整数矩阵 heights ， heights[r][c] 表示坐标 (r, c) 上单元格 高于海平面的高度
 * 。
 *
 * 岛上雨水较多，如果相邻单元格的高度 小于或等于
 * 当前单元格的高度，雨水可以直接向北、南、东、西流向相邻单元格。水可以从海洋附近的任何单元格流入海洋。
 *
 * 返回网格坐标 result 的 2D 列表 ，其中 result[i] = [ri, ci] 表示雨水从单元格
 * (ri, ci) 流动 既可流向太平洋也可流向大西洋 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
 * 输出: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
 *
 *
 * 示例 2：
 *
 *
 * 输入: heights = [[2,1],[1,2]]
 * 输出: [[0,0],[0,1],[1,0],[1,1]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == heights.length
 * n == heights[r].length
 * 1 <= m, n <= 200
 * 0 <= heights[r][c] <= 10^5
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int m, n;

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        void dfs(vector<vector<int>>& heights, int x, int y,
                 vector<vector<bool>>& occean) {
            if (occean[x][y]) {
                return;
            }

            occean[x][y] = true;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n ||
                    heights[nx][ny] < heights[x][y]) {
                    continue;
                }

                dfs(heights, nx, ny, occean);
            }
        }

        vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

            m = heights.size();
            n = heights[0].size();
            vector<vector<bool>> pacific(m, vector<bool>(n)),
                atlantic(m, vector<bool>(n));

            for (int i = 0; i < m; i++) {
                dfs(heights, i, 0, pacific);
            }

            for (int i = 0; i < n; i++) {
                dfs(heights, 0, i, pacific);
            }

            for (int i = 0; i < m; i++) {
                dfs(heights, i, n - 1, atlantic);
            }

            for (int i = 0; i < n; i++) {
                dfs(heights, m - 1, i, atlantic);
            }
            vector<vector<int>> ans;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (pacific[i][j] && atlantic[i][j]) {

                        ans.emplace_back(vector<int>{i, j});
                    }
                }
            }
            return ans;
        }
};

// @lc code=end
