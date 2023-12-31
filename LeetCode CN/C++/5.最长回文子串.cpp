/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode.cn/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (37.82%)
 * Likes:    6884
 * Dislikes: 0
 * Total Accepted:    1.5M
 * Total Submissions: 4.1M
 * Testcase Example:  '"babad"'
 *
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 *
 * 如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "cbbd"
 * 输出："bb"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 1000
 * s 仅由数字和英文字母组成
 *
 *
 */

// @lc code=start

// 动态规划解法
/*
class Solution {
    public:
        string longestPalindrome(string s) {
            int n = s.size();

            vector<vector<bool>> dp(n, vector<bool>(n));

            for (int i = 0; i < n; i++)
                dp[i][i] = true;

            int maxLength = 1;
            int start = 0;

            for (int length = 2; length <= n; length++) {
                for (int l = 0; l < n; l++) {
                    int r = length + l - 1;
                    if (r >= n) {
                        break;
                    }
                    if (s[l] != s[r]) {
                        dp[l][r] = false;
                    } else {
                        if (r - l < 3) {
                            dp[l][r] = true;
                        } else {
                            dp[l][r] = dp[l + 1][r - 1];
                        }
                    }

                    if (dp[l][r] == true && length > maxLength) {
                        start = l;
                        maxLength = length;
                    }
                }
            }
            return s.substr(start, maxLength);
        }
};
*/
// 中心扩展法
class Solution {
    public:
        pair<int, int> expend(string& s, int l, int r) {
            while (0 <= l && r < s.size() && s[l] == s[r]) {
                l--;
                r++;
            }
            return {l + 1, r - 1};
        }

        string longestPalindrome(string s) {
            int start = 0, end = 0;

            for (int i = 0; i < s.size(); i++) {
                auto [l1, r1] = expend(s, i, i);
                auto [l2, r2] = expend(s, i, i + 1);
                if (r1 - l1 > end - start) {
                    start = l1;
                    end = r1;
                }
                if (r2 - l2 > end - start) {
                    start = l2;
                    end = r2;
                }
            }
            return s.substr(start, end - start + 1);
        }
};

// @lc code=end
