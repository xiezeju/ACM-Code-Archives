/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (39.26%)
 * Likes:    9811
 * Dislikes: 0
 * Total Accepted:    2.6M
 * Total Submissions: 6.6M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: s = "abcabcbb"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 *
 *
 * 示例 2:
 *
 *
 * 输入: s = "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 *
 *
 * 示例 3:
 *
 *
 * 输入: s = "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= s.length <= 5 * 10^4
 * s 由英文字母、数字、符号和空格组成
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int         n = s.size();
            vector<int> cnt(128);
            int         l = 0, r = 0;
            int         ans = 0;
            while (r < n) {
                while (r < n && cnt[s[r]] < 1) {
                    cnt[s[r]]++;
                    r++;
                }
                ans = max(r - l, ans);
                while (cnt[s[r]] > 0) {
                    cnt[s[l]]--;
                    l++;
                }
            }
            return ans;
        }
};

// @lc code=end
