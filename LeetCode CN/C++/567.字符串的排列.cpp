/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 *
 * https://leetcode.cn/problems/permutation-in-string/description/
 *
 * algorithms
 * Medium (44.66%)
 * Likes:    973
 * Dislikes: 0
 * Total Accepted:    276.9K
 * Total Submissions: 619.2K
 * Testcase Example:  '"ab"\n"eidbaooo"'
 *
 * 给你两个字符串 s1 和 s2 ，写一个函数来判断 s2 是否包含
 * s1 的排列。如果是，返回 true ；否则，返回 false 。
 *
 * 换句话说，s1 的排列之一是 s2 的 子串 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s1 = "ab" s2 = "eidbaooo"
 * 输出：true
 * 解释：s2 包含 s1 的排列之一 ("ba").
 *
 *
 * 示例 2：
 *
 *
 * 输入：s1= "ab" s2 = "eidboaoo"
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s1.length, s2.length <= 10^4
 * s1 和 s2 仅包含小写字母
 *
 *
 */

// @lc code=start
class Solution {
    public:
        bool checkInclusion(string s1, string s2) {
            int n = s1.size();
            int m = s2.size();
            if (n > m)
                return false;

            vector<int> cnt(26), window(26);

            int kind = 0;
            for (char& ch : s1) {
                int c = ch - 'a';
                if (cnt[c] == 0) {
                    kind++;
                }
                cnt[c]++;
            }

            int match = 0;
            for (int i = 0; i < n; i++) {
                int x = s2[i] - 'a';
                window[x]++;
                if (window[x] == cnt[x]) {
                    match++;
                }
                if (match == kind) {
                    return true;
                }
            }

            for (int i = n; i < m; i++) {
                int last = s2[i - n] - 'a';
                if (window[last] == cnt[last]) {
                    match--;
                }
                window[last]--;

                int x = s2[i] - 'a';
                window[x]++;
                if (window[x] == cnt[x]) {
                    match++;
                }
                if (match == kind) {
                    return true;
                }
            }
            return false;
        }
};

// @lc code=end
