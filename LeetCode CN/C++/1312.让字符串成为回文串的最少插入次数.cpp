/*
 * @lc app=leetcode.cn id=1312 lang=cpp
 *
 * [1312] 让字符串成为回文串的最少插入次数
 *
 * https://leetcode.cn/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/
 *
 * algorithms
 * Hard (69.52%)
 * Likes:    213
 * Dislikes: 0
 * Total Accepted:    27.6K
 * Total Submissions: 39.7K
 * Testcase Example:  '"zzazz"'
 *
 * 给你一个字符串 s ，每一次操作你都可以在字符串的任意位置插入任意字符。
 *
 * 请你返回让 s 成为回文串的 最少操作次数 。
 *
 * 「回文串」是正读和反读都相同的字符串。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "zzazz"
 * 输出：0
 * 解释：字符串 "zzazz" 已经是回文串了，所以不需要做任何插入操作。
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "mbadm"
 * 输出：2
 * 解释：字符串可变为 "mbdadbm" 或者 "mdbabdm" 。
 *
 *
 * 示例 3：
 *
 *
 * 输入：s = "leetcode"
 * 输出：5
 * 解释：插入 5 个字符后字符串变为 "leetcodocteel" 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 500
 * s 中所有字符都是小写字母。
 *
 *
 */

// @lc code=start

// 思路1
/*
class Solution {
    public:
        int minInsertions(string s) {

            int n = s.size();

            string t(s.rbegin(), s.rend());

            vector<vector<int>> dp(n + 1, vector<int>(n + 1));

            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

                    if (s[i - 1] == t[j - 1]) {
                        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                    }
                }
            }

            return n - dp[n][n];
        }
};

*/

class Solution {
    public:
        int minInsertions(string s) {
            int n = s.size();

            // dp[i][j]代表s[i...j]变为回文串的最小操作次数
            vector<vector<int>> dp(n, vector<int>(n));

            for (int i = n - 1; i >= 0; i--) {
                for (int j = i + 1; j < n; j++) {
                    // 两字符相等说明已经是回文串，不需要额外操作
                    if (s[i] == s[j]) {
                        dp[i][j] = dp[i + 1][j - 1];
                    } else {

                        // 两字符不相等，说明s[i]和s[j]不能同时作为回文串的开头，需要进行插入操作，可以选择插入字符s[i]或s[j]到字符串中的任意位置，取操作次数最小的+1
                        dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
                    }
                }
            }
            return dp[0][n - 1];
        }
};

// @lc code=end
