/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 *
 * https://leetcode.cn/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (54.86%)
 * Likes:    1606
 * Dislikes: 0
 * Total Accepted:    187.7K
 * Total Submissions: 341.9K
 * Testcase Example:
 * '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1
 * 的最大矩形，并返回其面积。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：matrix =
 * [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
 * 输出：6
 * 解释：最大矩形如上图所示。
 *
 *
 * 示例 2：
 *
 *
 * 输入：matrix = [["0"]]
 * 输出：0
 *
 *
 * 示例 3：
 *
 *
 * 输入：matrix = [["1"]]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * rows == matrix.length
 * cols == matrix[0].length
 * 1 <= row, cols <= 200
 * matrix[i][j] 为 '0' 或 '1'
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int maximalRectangle(vector<vector<char>>& matrix) {
            int m = matrix.size();
            if (m == 0)
                return 0;
            int n = matrix[0].size();

            // 记录(i,j)该点及左边连续1的数量
            vector<vector<int>> left(m, vector<int>(n));

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++)
                    if (matrix[i][j] == '1')
                        left[i][j] = (j == 0 ? 0 : left[i][j - 1]) + 1;
            }

            // 对垂直方向求每个数上方第一个比自己小数
            // （和84.柱状图最大面积相同做法）
            int ans = 0;
            for (int j = 0; j < n; j++) {
                vector<int> up(m), down(m);
                stack<int>  s;

                for (int i = 0; i < m; i++) {
                    while (!s.empty() && left[s.top()][j] >= left[i][j]) {
                        s.pop();
                    }
                    up[i] = s.empty() ? -1 : s.top();
                    s.push(i);
                }

                s = stack<int>();
                for (int i = m - 1; i >= 0; i--) {
                    while (!s.empty() && left[s.top()][j] >= left[i][j]) {
                        s.pop();
                    }
                    down[i] = s.empty() ? m : s.top();
                    s.push(i);
                }

                for (int i = 0; i < m; i++) {
                    int h = down[i] - up[i] - 1;
                    ans = max(ans, h * left[i][j]);
                }
            }

            return ans;
        }
};

// @lc code=end
