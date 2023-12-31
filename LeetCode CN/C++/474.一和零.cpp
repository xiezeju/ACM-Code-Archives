/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 *
 * https://leetcode.cn/problems/ones-and-zeroes/description/
 *
 * algorithms
 * Medium (65.55%)
 * Likes:    1065
 * Dislikes: 0
 * Total Accepted:    179.6K
 * Total Submissions: 274K
 * Testcase Example:  '["10","0001","111001","1","0"]\n5\n3'
 *
 * 给你一个二进制字符串数组 strs 和两个整数 m 和 n 。
 *
 *
 * 请你找出并返回 strs 的最大子集的长度，该子集中 最多 有 m 个 0 和 n 个 1 。
 *
 * 如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
 * 输出：4
 * 解释：最多有 5 个 0 和 3 个 1 的最大子集是 {"10","0001","1","0"} ，因此答案是
 * 4 。 其他满足题意但较小的子集包括 {"0001","1"} 和 {"10","1","0"} 。{"111001"}
 * 不满足题意，因为它含 4 个 1 ，大于 n 的值 3 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：strs = ["10", "0", "1"], m = 1, n = 1
 * 输出：2
 * 解释：最大的子集是 {"0", "1"} ，所以答案是 2 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= strs.length <= 600
 * 1 <= strs[i].length <= 100
 * strs[i] 仅由 '0' 和 '1' 组成
 * 1 <= m, n <= 100
 *
 *
 */

// @lc code=start
class Solution {
    public:
        pair<int, int> GetOneZero(string& s) {
            pair<int, int> a;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] - '0' == 0) {
                    a.first++;
                } else {
                    a.second++;
                }
            }
            return a;
        }

        int findMaxForm(vector<string>& strs, int m, int n) {
            int l = strs.size();

            vector<vector<int>> dp(m + 1, vector<int>(n + 1));

            for (int i = 0; i < l; i++) {
                auto [zero, one] = GetOneZero(strs[i]);
                for (int j = m; j >= zero; j--) {
                    for (int k = n; k >= one; k--) {
                        dp[j][k] = max(dp[j][k], dp[j - zero][k - one] + 1);
                    }
                }
            }

            return dp[m][n];
        }
};

// @lc code=end
