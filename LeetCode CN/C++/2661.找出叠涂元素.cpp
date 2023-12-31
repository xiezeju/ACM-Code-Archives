/*
 * @lc app=leetcode.cn id=2661 lang=cpp
 *
 * [2661] 找出叠涂元素
 *
 * https://leetcode.cn/problems/first-completely-painted-row-or-column/description/
 *
 * algorithms
 * Medium (51.62%)
 * Likes:    27
 * Dislikes: 0
 * Total Accepted:    7K
 * Total Submissions: 12.5K
 * Testcase Example:  '[1,3,4,2]\n[[1,4],[2,3]]'
 *
 * 给你一个下标从 0 开始的整数数组 arr 和一个 m x n 的整数 矩阵 mat 。arr 和 mat
 * 都包含范围 [1，m * n] 内的 所有 整数。
 *
 * 从下标 0 开始遍历 arr 中的每个下标 i ，并将包含整数 arr[i] 的 mat
 * 单元格涂色。
 *
 * 请你找出 arr 中在 mat
 * 的某一行或某一列上都被涂色且下标最小的元素，并返回其下标 i 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：arr = [1,3,4,2], mat = [[1,4],[2,3]]
 * 输出：2
 * 解释：遍历如上图所示，arr[2] 在矩阵中的第一行或第二列上都被涂色。
 *
 *
 * 示例 2：
 *
 *
 * 输入：arr = [2,8,7,4,1,3,5,6,9], mat = [[3,2,5],[1,4,6],[8,7,9]]
 * 输出：3
 * 解释：遍历如上图所示，arr[3] 在矩阵中的第二列上都被涂色。
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == mat.length
 * n = mat[i].length
 * arr.length == m * n
 * 1 <= m, n <= 10^5
 * 1 <= m * n <= 10^5
 * 1 <= arr[i], mat[r][c] <= m * n
 * arr 中的所有整数 互不相同
 * mat 中的所有整数 互不相同
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
            int m = mat.size();
            int n = mat[0].size();

            vector<int> row(m, n), col(n, m);

            unordered_map<int, pair<int, int>> s;

            int ans = INT_MAX;

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    s[mat[i][j]] = {i, j};
                }
            }
            int arr_size = n * m;
            for (int k = 0; k < arr_size; k++) {
                auto [i, j] = s[arr[k]];
                row[i]--;
                col[j]--;
                if (!row[i] || !col[j]) {
                    ans = k;
                    break;
                }
            }
            return ans;
        }
};

// @lc code=end
