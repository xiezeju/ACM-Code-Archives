/*
 * @lc app=leetcode.cn id=790 lang=cpp
 *
 * [790] 多米诺和托米诺平铺
 *
 * https://leetcode.cn/problems/domino-and-tromino-tiling/description/
 *
 * algorithms
 * Medium (54.23%)
 * Likes:    336
 * Dislikes: 0
 * Total Accepted:    29.9K
 * Total Submissions: 55.2K
 * Testcase Example:  '3'
 *
 * 有两种形状的瓷砖：一种是 2 x 1 的多米诺形，另一种是形如 "L"
 * 的托米诺形。两种形状都可以旋转。
 *
 *
 *
 * 给定整数 n ，返回可以平铺 2 x n 的面板的方法的数量。返回对 10^9 +
 * 7 取模 的值。
 *
 * 平铺指的是每个正方形都必须有瓷砖覆盖。两个平铺不同，当且仅当面板上有四个方向上的相邻单元中的两个，使得恰好有一个平铺有一个瓷砖占据两个正方形。
 *
 *
 *
 * 示例 1:
 *
 *
 *
 *
 * 输入: n = 3
 * 输出: 5
 * 解释: 五种不同的方法如上所示。
 *
 *
 * 示例 2:
 *
 *
 * 输入: n = 1
 * 输出: 1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 1000
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int numTilings(int n) {
            const int mod = 1e9 + 7;

            // 考虑第i列的正方形覆盖情况，一共有4种状态
            // Case 0：两下两个正方形都没有被覆盖
            // Case 1：只有上面的正方形被覆盖
            // Case 2：只有下面的正方形被覆盖
            // Case 3：上下两个正方形都被覆盖
            vector<vector<long long>> dp(n + 1, vector<long long>(4));
            dp[0][3] = 1;
            for (int i = 1; i <= n; i++) {
                // Case 0 这种状态只能由第i-1列铺满转移而来
                dp[i][0] = dp[i - 1][3];
                // Case 1 这种状态可以由第i-1列不铺而直接铺托米诺 +
                // 第i-1列覆盖下正方形，而在上方横向放置多米诺
                // 这两种状态转移而来
                dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
                // Case 1 这种状态可以由第i-1列不铺而直接铺托米诺 +
                // 第i-1列覆盖上正方形，而在下方横向放置多米诺
                // 这两种状态转移而来
                dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
                // Case 3 这种状态可以由所有状态转移而来
                dp[i][3] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] +
                            dp[i - 1][3]) %
                           mod;
            }

            return dp[n][3];
        }
};

// @lc code=end
