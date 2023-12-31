/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 *
 * https://leetcode.cn/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (45.35%)
 * Likes:    2754
 * Dislikes: 0
 * Total Accepted:    487K
 * Total Submissions: 1.1M
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s
 * 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
 *
 *
 *
 * 注意：
 *
 *
 * 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
 * 如果 s 中存在这样的子串，我们保证它是唯一的答案。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "ADOBECODEBANC", t = "ABC"
 * 输出："BANC"
 * 解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "a", t = "a"
 * 输出："a"
 * 解释：整个字符串 s 是最小覆盖子串。
 *
 *
 * 示例 3:
 *
 *
 * 输入: s = "a", t = "aa"
 * 输出: ""
 * 解释: t 中两个字符 'a' 均应包含在 s 的子串中，
 * 因此没有符合条件的子字符串，返回空字符串。
 *
 *
 *
 * 提示：
 *
 *
 * ^n == s.length
 * ^n == t.length
 * 1 <= n, n <= 10^5
 * s 和 t 由英文字母组成
 *
 *
 *
 * 进阶：你能设计一个在 o(n+n) 时间内解决此问题的算法吗？
 */

// @lc code=start
class Solution {
    public:
        string minWindow(string s, string t) {
            int n = s.size();

            vector<int> count(65, 0);
            vector<int> window(65, 0);

            unordered_set<char> k;

            // 统计模式串t内字符出现的频数
            for (auto& ch : t) {
                count[ch - 'A']++;
                k.insert(ch);
            }
            // 统计模式串t中字符的种类数
            int kind = k.size();

            int l = 0, r = 0;
            int substr_start = 0; // 记录答案子串的起点
            int match = 0;        // 记录当前窗口字母种类的匹配数
            int minLen = n + 1;   // 匹配子串的最小长度
            while (r < n) {
                // r一直向右走，并且不断扩充当前滑动窗口中的字母数量
                int R = s[r] - 'A';
                if (count[R] > 0) {
                    window[R]++;
                    if (count[R] == window[R]) {
                        match++;
                    }
                }
                r++;

                // 当前滑动窗口已经为匹配状态时，考虑更新最短长度以及向右移动l
                while (match == kind) {
                    // 当前匹配状态下的子串长度比之前找到的更短，更新长度以及子串的起点
                    if (r - l < minLen) {
                        substr_start = l;
                        minLen = r - l;
                    }
                    int L = s[l] - 'A';
                    // l所在字符是模式串t内的字符，更新当前滑动窗口
                    if (count[L] > 0) {
                        window[L]--;
                        // 打破匹配状态，之后就可以跳出while循环继续向右移动r了
                        if (window[L] < count[L]) {
                            match--;
                        }
                    }
                    l++;
                }
            }

            return minLen > n ? "" : s.substr(substr_start, minLen);
        }
};

// @lc code=end
