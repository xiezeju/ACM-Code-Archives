/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 *
 * https://leetcode.cn/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (73.41%)
 * Likes:    1694
 * Dislikes: 0
 * Total Accepted:    342.9K
 * Total Submissions: 467.2K
 * Testcase Example:  '"aab"'
 *
 * 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s
 * 所有可能的分割方案。
 *
 * 回文串 是正着读和反着读都一样的字符串。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "aab"
 * 输出：[["a","a","b"],["aa","b"]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "a"
 * 输出：[["a"]]
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
        vector<vector<string>> ans;
        vector<string>         a;

        bool isPalindrome(string& s, int l, int r) {
            while (l < r) {
                if (s[l++] != s[r--]) {
                    return false;
                }
            }
            return true;
        }

        void dfs(string& s, int x, int n) {
            if (x == n) {
                ans.emplace_back(a);
                return;
            }
            for (int i = x; i < n; i++) {
                if (isPalindrome(s, x, i)) {
                    a.emplace_back(s.substr(x, i - x + 1));
                    dfs(s, i + 1, n);
                    a.pop_back();
                }
            }
        }

        vector<vector<string>> partition(string s) {
            dfs(s, 0, s.size());
            return ans;
        }
};

// @lc code=end
