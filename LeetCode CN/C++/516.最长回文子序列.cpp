/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 *
 * https://leetcode.cn/problems/longest-palindromic-subsequence/description/
 *
 * algorithms
 * Medium (67.13%)
 * Likes:    1122
 * Dislikes: 0
 * Total Accepted:    203.7K
 * Total Submissions: 303.5K
 * Testcase Example:  '"bbbab"'
 *
 * 给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。
 *
 * 子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "bbbab"
 * 输出：4
 * 解释：一个可能的最长回文子序列为 "bbbb" 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "cbbd"
 * 输出：2
 * 解释：一个可能的最长回文子序列为 "bb" 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * s 仅由小写英文字母组成
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int longestPalindromeSubseq(string s) {
            int n = s.size();
            if (n < 2)
                return n;
            vector<vector<int>> dp(n, vector<int>(n));

            for (int i = 0; i < n; i++) {
                dp[i][i] = 1;
            }

            for (int length = 2; length <= n; length++) {
                for (int l = 0; l < n; l++) {
                    int r = length + l - 1;
                    if (r >= n) {
                        break;
                    }
                    if (s[l] == s[r]) {
                        dp[l][r] = dp[l + 1][r - 1] + 2;

                    } else {
                        dp[l][r] = max(dp[l][r - 1], dp[l + 1][r]);
                    }
                }
            }
            return dp[0][n - 1];
        }
};

// @lc code=end
