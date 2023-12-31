/*
 * @lc app=leetcode.cn id=1358 lang=cpp
 *
 * [1358] 包含所有三种字符的子字符串数目
 *
 * https://leetcode.cn/problems/number-of-substrings-containing-all-three-characters/description/
 *
 * algorithms
 * Medium (53.16%)
 * Likes:    102
 * Dislikes: 0
 * Total Accepted:    11.8K
 * Total Submissions: 22.1K
 * Testcase Example:  '"abcabc"'
 *
 * 给你一个字符串 s ，它只包含三种字符 a, b 和 c 。
 *
 * 请你返回 a，b 和 c 都 至少 出现过一次的子字符串数目。
 *
 *
 *
 * 示例 1：
 *
 * 输入：s = "abcabc"
 * 输出：10
 * 解释：包含 a，b 和 c 各至少一次的子字符串为 "abc", "abca", "abcab", "abcabc",
 * "bca", "bcab", "bcabc", "cab", "cabc" 和 "abc" (相同字符串算多次)。
 *
 *
 * 示例 2：
 *
 * 输入：s = "aaacb"
 * 输出：3
 * 解释：包含 a，b 和 c 各至少一次的子字符串为 "aaacb", "aacb" 和 "acb" 。
 *
 *
 * 示例 3：
 *
 * 输入：s = "abc"
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 3 <= s.length <= 5 x 10^4
 * s 只包含字符 a，b 和 c 。
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int numberOfSubstrings(string s) {
            int n = s.size();
            int kind = 0;

            vector<int> window(3);

            int ans = 0;
            int l = 0, r = 0;
            while (r < n) {
                int R = s[r] - 'a';
                if (window[R] == 0) {
                    kind++;
                }
                window[R]++;
                while (kind == 3) {
                    int L = s[l] - 'a';
                    window[L]--;
                    if (window[L] == 0) {
                        kind--;
                    }
                    l++;
                }
                r++;
                ans += r - l;
            }

            return ((1ll) * n * (n + 1) >> 1) - ans;
        }
};

// @lc code=end
