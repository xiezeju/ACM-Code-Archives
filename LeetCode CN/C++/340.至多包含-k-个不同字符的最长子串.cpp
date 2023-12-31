/*
 * @lc app=leetcode.cn id=340 lang=cpp
 *
 * [340] 至多包含 K 个不同字符的最长子串
 *
 * https://leetcode.cn/problems/longest-substring-with-at-most-k-distinct-characters/description/
 *
 * algorithms
 * Medium (51.17%)
 * Likes:    248
 * Dislikes: 0
 * Total Accepted:    27.7K
 * Total Submissions: 54K
 * Testcase Example:  '"eceba"\n2'
 *
 * 给你一个字符串 s 和一个整数 k ，请你找出 至多 包含 k 个 不同
 * 字符的最长子串，并返回该子串的长度。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "eceba", k = 2
 * 输出：3
 * 解释：满足题目要求的子串是 "ece" ，长度为 3 。
 *
 * 示例 2：
 *
 *
 * 输入：s = "aa", k = 1
 * 输出：2
 * 解释：满足题目要求的子串是 "aa" ，长度为 2 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 5 * 10^4
 * 0 <= k <= 50
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int lengthOfLongestSubstringKDistinct(string s, int k) {
            int n = s.size();
            int l = 0, r = 0;
            int ans = 0;
            int kind = 0;

            vector<int> window(128);

            while (r < n) {
                int R = s[r];
                if (window[R] == 0) {
                    kind++;
                }
                window[R]++;

                while (kind > k) {
                    int L = s[l];
                    window[L]--;
                    if (window[L] == 0) {
                        kind--;
                    }
                    l++;
                }
                if (kind <= k)
                    ans = max(ans, r - l + 1);
                r++;
            }
            return ans;
        }
};

// @lc code=end
