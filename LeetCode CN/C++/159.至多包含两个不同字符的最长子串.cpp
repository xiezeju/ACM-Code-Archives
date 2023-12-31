/*
 * @lc app=leetcode.cn id=159 lang=cpp
 *
 * [159] 至多包含两个不同字符的最长子串
 *
 * https://leetcode.cn/problems/longest-substring-with-at-most-two-distinct-characters/description/
 *
 * algorithms
 * Medium (55.79%)
 * Likes:    218
 * Dislikes: 0
 * Total Accepted:    34.4K
 * Total Submissions: 61.7K
 * Testcase Example:  '"eceba"'
 *
 * 给你一个字符串 s ，请你找出 至多 包含 两个不同字符
 * 的最长子串，并返回该子串的长度。
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "eceba"
 * 输出：3
 * 解释：满足题目要求的子串是 "ece" ，长度为 3 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "ccaabbb"
 * 输出：5
 * 解释：满足题目要求的子串是 "aabbb" ，长度为 5 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^5
 * s 由英文字母组成
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int lengthOfLongestSubstringTwoDistinct(string s) {
            int n = s.size();
            int l = 0, r = 0;
            int ans = 0;
            int kind = 0;

            vector<int> window(65);

            while (r < n) {
                int R = s[r] - 'A';
                if (window[R] == 0) {
                    kind++;
                }
                window[R]++;

                while (kind > 2) {
                    int L = s[l] - 'A';
                    window[L]--;
                    if (window[L] == 0) {
                        kind--;
                    }
                    l++;
                }
                if (kind <= 2)
                    ans = max(ans, r - l + 1);
                r++;
            }
            return ans;
        }
};

// @lc code=end
