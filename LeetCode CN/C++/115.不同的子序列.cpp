/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 *
 * https://leetcode.cn/problems/distinct-subsequences/description/
 *
 * algorithms
 * Hard (51.41%)
 * Likes:    1149
 * Dislikes: 0
 * Total Accepted:    154K
 * Total Submissions: 299.3K
 * Testcase Example:  '"rabbbit"\n"rabbit"'
 *
 * 给你两个字符串 s 和 t ，统计并返回在 s 的 子序列 中 t
 * 出现的个数，结果需要对 10^9 + 7 取模。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "rabbbit", t = "rabbit"
 * 输出：3
 * 解释：
 * 如下所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
 * rabbbit
 * rabbbit
 * rabbbit
 *
 * 示例 2：
 *
 *
 * 输入：s = "babgbag", t = "bag"
 * 输出：5
 * 解释：
 * 如下所示, 有 5 种可以从 s 中得到 "bag" 的方案。
 * babgbag
 * babgbag
 * babgbag
 * babgbag
 * babgbag
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length, t.length <= 1000
 * s 和 t 由英文字母组成
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int numDistinct(string s, string t) {

            const int mod = 1e9 + 7;

            int m = s.size();
            int n = t.size();

            vector<vector<int>> dp(m + 1, vector<int>(n + 1));
            for (int i = 0; i <= m; i++) {
                dp[i][0] = 1;
            }
            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                    if (s[i - 1] == t[j - 1]) {
                        dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
                    } else {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }
            return dp[m][n];
        }
};

// @lc code=end
