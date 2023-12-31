/*
 * @lc app=leetcode.cn id=727 lang=cpp
 *
 * [727] 最小窗口子序列
 *
 * https://leetcode.cn/problems/minimum-window-subsequence/description/
 *
 * algorithms
 * Hard (42.62%)
 * Likes:    156
 * Dislikes: 0
 * Total Accepted:    6.1K
 * Total Submissions: 14.3K
 * Testcase Example:  '"abcdebdde"\n"bde"'
 *
 * 给定字符串 S and T，找出 S 中最短的（连续）子串 W ，使得 T 是 W 的 子序列 。
 *
 * 如果 S 中没有窗口可以包含 T 中的所有字符，返回空字符串
 * ""。如果有不止一个最短长度的窗口，返回开始位置最靠左的那个。
 *
 * 示例 1：
 *
 * 输入：
 * S = "abcdebdde", T = "bde"
 * 输出："bcde"
 * 解释：
 * "bcde" 是答案，因为它在相同长度的字符串 "bdde" 出现之前。
 * "deb" 不是一个更短的答案，因为在窗口中必须按顺序出现 T 中的元素。
 *
 *
 *
 * 注：
 *
 *
 * 所有输入的字符串都只包含小写字母。All the strings in the input will only
 * contain lowercase letters. S 长度的范围为 [1, 20000]。 T 长度的范围为 [1,
 * 100]。
 *
 *
 *
 *
 */

// @lc code=start
// 动态规划解法
class Solution {
    public:
        string minWindow(string s1, string s2) {
            int n = s1.size();
            int m = s2.size();

            string ans = "";

            // last 记录字母在数组中最后出现的下标
            vector<int>         last(26, -1);
            // dp[i][j] 代表当前下标 i 下，字符 j 最后一次出现的位置
            vector<vector<int>> dp(n, vector<int>(26, -1));

            for (int i = 0; i < n; i++) {
                int j = s1[i] - 'a';
                dp[i] = last;
                last[j] = i;
            }

            int minLen = INT_MAX;

            for (int i = 0; i < n; i++) {
                if (s1[i] == s2[m - 1]) {
                    int pre = i;
                    int k = m - 2;
                    // 从字符串 s2 的倒数第二个位置往前跳
                    while (k >= 0) {
                        int j = s2[k] - 'a';
                        if (dp[pre][j] != -1) {
                            pre = dp[pre][j];
                            k--;
                        } else {
                            break;
                        }
                    }
                    // k < 0 说明字符串 s2 遍历完成，找到了一个子串
                    // 此时的 pre 就是 s2[0] 在 s1 中出现的最后位置
                    // 随后判断一下长度是不是比已经找到的短，如果是就更新
                    if (k < 0 && i - pre + 1 < minLen) {
                        minLen = i - pre + 1;
                        ans = s1.substr(pre, i - pre + 1);
                    }
                }
            }

            return ans;
        }
};

// @lc code=end
