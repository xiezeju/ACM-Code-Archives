/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 *
 * https://leetcode.cn/problems/edit-distance/description/
 *
 * algorithms
 * Hard (62.82%)
 * Likes:    3177
 * Dislikes: 0
 * Total Accepted:    409.1K
 * Total Submissions: 651.1K
 * Testcase Example:  '"horse"\n"ros"'
 *
 * 给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数
 *  。
 *
 * 你可以对一个单词进行如下三种操作：
 *
 *
 * 插入一个字符
 * 删除一个字符
 * 替换一个字符
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：word1 = "horse", word2 = "ros"
 * 输出：3
 * 解释：
 * horse -> rorse (将 'h' 替换为 'r')
 * rorse -> rose (删除 'r')
 * rose -> ros (删除 'e')
 *
 *
 * 示例 2：
 *
 *
 * 输入：word1 = "intention", word2 = "execution"
 * 输出：5
 * 解释：
 * intention -> inention (删除 't')
 * inention -> enention (将 'i' 替换为 'e')
 * enention -> exention (将 'n' 替换为 'x')
 * exention -> exection (将 'n' 替换为 'c')
 * exection -> execution (插入 'u')
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= word1.length, word2.length <= 500
 * word1 和 word2 由小写英文字母组成
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int minDistance(string word1, string word2) {
            int m = word1.size();
            int n = word2.size();

            vector<vector<int>> dp(m + 1, vector<int>(n + 1));

            // dp[i][j]代表s[0...i]变道s[0...j]的最小步骤
            for (int i = 0; i <= m; i++) {
                dp[i][0] = i;
            }
            for (int i = 0; i <= n; i++) {
                dp[0][i] = i;
            }

            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                    // 注意下标，字符串的下标从0开始，实际上的要和本循环中下标错开一位
                    if (word1[i - 1] == word2[j - 1]) {
                        // 当两个字符相等的时候，说明不需要进行操作
                        dp[i][j] = dp[i - 1][j - 1];
                    } else {
                        // 当两个字符不相等的时候，需要考虑以下三种情况
                        //  Case 1: 替换word1或word2中的一个字符
                        //  Case 2:
                        //  删除word1中的一个字符<=>向word2中添加一个字符 Case
                        //  3: 删除word2中的一个字符<=>向word1中添加一个字符
                        //  以上三种情况都需要操作数+1
                        dp[i][j] = max(
                            dp[i][j], 1 + min(dp[i - 1][j - 1],
                                              min(dp[i - 1][j], dp[i][j - 1])));
                    }
                }
            }
            return dp[m][n];
        }
};

// @lc code=end
