/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 *
 * https://leetcode.cn/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (48.96%)
 * Likes:    873
 * Dislikes: 0
 * Total Accepted:    347.1K
 * Total Submissions: 707.4K
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,60]]\n3'
 *
 * 给你一个满足下述两条属性的 m x n 整数矩阵：
 *
 *
 * 每行中的整数从左到右按非严格递增顺序排列。
 * 每行的第一个整数大于前一行的最后一个整数。
 *
 *
 * 给你一个整数 target ，如果 target 在矩阵中，返回 true ；否则，返回 false 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 100
 * -10^4 <= matrix[i][j], target <= 10^4
 *
 *
 */

// @lc code=start
class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int n = matrix.size();
            int m = matrix[0].size();

            for (int i = 0; i < n; i++) {
                if (matrix[i][0] > target || matrix[i][m - 1] < target) {
                    continue;
                }
                int l = 0, r = m - 1;
                while (l < r) {
                    int mid = l + r >> 1;
                    if (target <= matrix[i][mid]) {
                        r = mid;
                    } else {
                        l = mid + 1;
                    }
                }
                if (matrix[i][l] == target) {
                    return true;
                }
            }

            return false;
        }
};

// @lc code=end
