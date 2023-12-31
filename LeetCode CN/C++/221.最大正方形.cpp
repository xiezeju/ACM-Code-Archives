/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 *
 * https://leetcode.cn/problems/maximal-square/description/
 *
 * algorithms
 * Medium (49.85%)
 * Likes:    1569
 * Dislikes: 0
 * Total Accepted:    291.7K
 * Total Submissions: 585K
 * Testcase Example:
 * '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1'
 * 的最大正方形，并返回其面积。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：matrix =
 * [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
 * 输出：4
 *
 *
 * 示例 2：
 *
 *
 * 输入：matrix = [["0","1"],["1","0"]]
 * 输出：1
 *
 *
 * 示例 3：
 *
 *
 * 输入：matrix = [["0"]]
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1
 * matrix[i][j] 为 '0' 或 '1'
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int maximalSquare(vector<vector<char>>& matrix) {
            int m = matrix.size();
            int n = matrix[0].size();

            vector<vector<int>> dp(m, vector<int>(n));

            for (int i = 0; i < n; i++) {
                if (matrix[0][i] == '1') {
                    dp[0][i] = 1;
                }
            }
            for (int i = 0; i < m; i++) {
                if (matrix[i][0] == '1') {
                    dp[i][0] = 1;
                }
            }

            for (int i = 1; i < m; i++) {
                for (int j = 1; j < n; j++) {
                    if (matrix[i][j] == '1') {
                        dp[i][j] = min(dp[i - 1][j - 1],
                                       min(dp[i][j - 1], dp[i - 1][j])) +
                                   1;
                    }
                }
            }
            int Maxlength = 0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    Maxlength = max(Maxlength, dp[i][j]);
                }
            }
            return Maxlength * Maxlength;
        }
};

// @lc code=end
