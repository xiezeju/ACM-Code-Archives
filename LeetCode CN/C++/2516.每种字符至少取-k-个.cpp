/*
 * @lc app=leetcode.cn id=2516 lang=cpp
 *
 * [2516] 每种字符至少取 K 个
 *
 * https://leetcode.cn/problems/take-k-of-each-character-from-left-and-right/description/
 *
 * algorithms
 * Medium (37.65%)
 * Likes:    35
 * Dislikes: 0
 * Total Accepted:    6K
 * Total Submissions: 15.9K
 * Testcase Example:  '"aabaaaacaabc"\n2'
 *
 * 给你一个由字符 'a'、'b'、'c' 组成的字符串 s 和一个非负整数 k
 * 。每分钟，你可以选择取走 s 最左侧 还是 最右侧 的那个字符。
 *
 * 你必须取走每种字符 至少 k 个，返回需要的 最少 分钟数；如果无法取到，则返回 -1
 * 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "aabaaaacaabc", k = 2
 * 输出：8
 * 解释：
 * 从 s 的左侧取三个字符，现在共取到两个字符 'a' 、一个字符 'b' 。
 * 从 s 的右侧取五个字符，现在共取到四个字符 'a' 、两个字符 'b' 和两个字符 'c'
 * 。 共需要 3 + 5 = 8 分钟。 可以证明需要的最少分钟数是 8 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "a", k = 1
 * 输出：-1
 * 解释：无法取到一个字符 'b' 或者 'c'，所以返回 -1 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^5
 * s 仅由字母 'a'、'b'、'c' 组成
 * 0 <= k <= s.length
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int takeCharacters(string s, int k) {
            int         n = s.size();
            vector<int> cnt(3, 0);
            for (int i = 0; i < n; i++) {
                cnt[s[i] - 'a']++;
            }
            if (cnt[0] < k || cnt[1] < k || cnt[2] < k) {
                return -1;
            }
            int         r = 0;
            vector<int> cnt_l(3, 0), cnt_r = cnt;

            int ans = n + 1;
            for (int l = -1; l < n; l++) {
                if (l != -1) {
                    cnt_l[s[l] - 'a']++;
                }
                while (r < n) {
                    int cur = s[r] - 'a';
                    if (cnt_l[cur] + cnt_r[cur] - 1 < k) {
                        break;
                    }
                    cnt_r[cur]--;
                    r++;
                }

                ans = min(ans, l + 1 + n - r);
            }
            return ans;
        }
};

// @lc code=end
