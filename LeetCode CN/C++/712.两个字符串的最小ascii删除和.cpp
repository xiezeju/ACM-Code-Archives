/*
 * @lc app=leetcode.cn id=712 lang=cpp
 *
 * [712] 两个字符串的最小ASCII删除和
 *
 * https://leetcode.cn/problems/minimum-ascii-delete-sum-for-two-strings/description/
 *
 * algorithms
 * Medium (69.50%)
 * Likes:    355
 * Dislikes: 0
 * Total Accepted:    36.6K
 * Total Submissions: 52.7K
 * Testcase Example:  '"sea"\n"eat"'
 *
 * 给定两个字符串s1 和 s2，返回
 * 使两个字符串相等所需删除字符的 ASCII 值的最小和 。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: s1 = "sea", s2 = "eat"
 * 输出: 231
 * 解释: 在 "sea" 中删除 "s" 并将 "s" 的值(115)加入总和。
 * 在 "eat" 中删除 "t" 并将 116 加入总和。
 * 结束时，两个字符串相等，115 + 116 = 231 就是符合条件的最小和。
 *
 *
 * 示例 2:
 *
 *
 * 输入: s1 = "delete", s2 = "leet"
 * 输出: 403
 * 解释: 在 "delete" 中删除 "dee" 字符串变成 "let"，
 * 将 100[d]+101[e]+101[e] 加入总和。在 "leet" 中删除 "e" 将 101[e] 加入总和。
 * 结束时，两个字符串都等于 "let"，结果即为 100+101+101+101 = 403 。
 * 如果改为将两个字符串转换为 "lee" 或 "eet"，我们会得到 433 或 417
 * 的结果，比答案更大。
 *
 *
 *
 *
 * 提示:
 *
 *
 * 0 <= s1.length, s2.length <= 1000
 * s1 和 s2 由小写英文字母组成
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int minimumDeleteSum(string s1, string s2) {
            int                 m = s1.size();
            int                 n = s2.size();
            // dp[i][j]代表将s1[0...i]变到s2[0...j]的最小代价
            vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0x3f3f3f3f));
            vector<int>         as1(m + 1), as2(n + 1);
            for (int i = 1; i <= m; i++) {
                as1[i] = as1[i - 1] + s1[i - 1];
            }
            for (int i = 1; i <= n; i++) {
                as2[i] = as2[i - 1] + s2[i - 1];
            }

            // 初始化边界情况
            for (int i = 0; i <= m; i++) {
                dp[i][0] = as1[i];
            }
            for (int i = 0; i <= n; i++) {
                dp[0][i] = as2[i];
            }

            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                    // 两字符相等不需要修改
                    if (s1[i - 1] == s2[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1];
                    } else {
                        // 两字符不相等时需要考虑以下三种情况
                        //  Case 1: 同时删除s1和s2中的一个字符
                        //  Case 2：删除s1中一个字符
                        //  Case 3：删除s2中的一个字符
                        dp[i][j] =
                            min(dp[i][j],
                                min(dp[i - 1][j - 1] + s1[i - 1] + s2[j - 1],
                                    min(dp[i - 1][j] + s1[i - 1],
                                        dp[i][j - 1] + s2[j - 1])));
                    }
                }
            }
            return dp[m][n];
        }
};

// @lc code=end
