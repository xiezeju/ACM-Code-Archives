/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 *
 * https://leetcode.cn/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (54.32%)
 * Likes:    1336
 * Dislikes: 0
 * Total Accepted:    347.5K
 * Total Submissions: 642K
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * 给定两个字符串 s 和
 * p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
 *
 * 异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: s = "cbaebabacd", cnt = "abc"
 * 输出: [0,6]
 * 解释:
 * 起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
 * 起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
 *
 *
 * 示例 2:
 *
 *
 * 输入: s = "abab", cnt = "ab"
 * 输出: [0,1,2]
 * 解释:
 * 起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
 * 起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
 * 起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= s.length, cnt.length <= 3 * 10^4
 * s 和 p 仅包含小写字母
 *
 *
 */

// @lc code=start
class Solution {
    public:
        vector<int> findAnagrams(string s, string p) {
            int n = s.size();
            int m = p.size();
            if (m > n)
                return {};

            vector<int> cnt(26), window(26);

            int kind = 0;
            for (char& ch : p) {
                int c = ch - 'a';
                if (cnt[c] == 0)
                    kind++;
                cnt[c]++;
            }

            vector<int> a;

            int match = 0;

            // 先处理主串的前m个字符，可以使后续的过程统一
            for (int i = 0; i < m; i++) {
                int cur = s[i] - 'a';
                window[cur]++;
                if (cnt[cur] == window[cur]) {
                    match++;
                }
            }
            if (kind == match)
                a.emplace_back(0);

            for (int i = m; i < n; i++) {
                // 处理滑出当前窗口的字符
                int last = s[i - m] - 'a';
                if (cnt[last] == window[last]) {
                    match--;
                }
                window[last]--;

                int cur = s[i] - 'a';
                window[cur]++;
                if (cnt[cur] == window[cur]) {
                    match++;
                }
                // 因为划窗的长度是固定的，只要匹配数和模式串的字母种类数一样说明完全匹配
                if (kind == match) {
                    a.emplace_back(i - m + 1);
                }
            }
            return a;
        }
};

// @lc code=end
