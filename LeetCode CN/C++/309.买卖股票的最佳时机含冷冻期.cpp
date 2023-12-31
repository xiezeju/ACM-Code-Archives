/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 买卖股票的最佳时机含冷冻期
 *
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 *
 * algorithms
 * Medium (64.68%)
 * Likes:    1653
 * Dislikes: 0
 * Total Accepted:    292.2K
 * Total Submissions: 451.6K
 * Testcase Example:  '[1,2,3,0,2]'
 *
 * 给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格
 * 。​
 *
 * 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
 *
 *
 * 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
 *
 *
 * 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: prices = [1,2,3,0,2]
 * 输出: 3
 * 解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
 *
 * 示例 2:
 *
 *
 * 输入: prices = [1]
 * 输出: 0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= prices.length <= 5000
 * 0 <= prices[i] <= 1000
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int n = prices.size();

            // dp[i][j][k] i代表天数，j代表是否处于冷冻期，k代表是否持有股票

            vector<vector<vector<int>>> dp(
                n + 1, vector<vector<int>>(2, vector<int>(2)));

            dp[0][0][1] = -prices[0];

            for (int i = 1; i < n; i++) {
                // 利用状态机建立状态转移方程
                dp[i][0][0] = max(dp[i - 1][1][0], dp[i - 1][0][0]);
                dp[i][0][1] = max(dp[i - 1][0][1], dp[i - 1][0][0] - prices[i]);
                dp[i][1][0] = dp[i - 1][0][1] + prices[i];
            }

            return max(dp[n - 1][0][0], dp[n - 1][1][0]);
        }
};

// @lc code=end
