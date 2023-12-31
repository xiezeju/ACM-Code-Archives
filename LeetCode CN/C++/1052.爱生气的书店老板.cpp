/*
 * @lc app=leetcode.cn id=1052 lang=cpp
 *
 * [1052] 爱生气的书店老板
 *
 * https://leetcode.cn/problems/grumpy-bookstore-owner/description/
 *
 * algorithms
 * Medium (58.03%)
 * Likes:    267
 * Dislikes: 0
 * Total Accepted:    65K
 * Total Submissions: 112.1K
 * Testcase Example:  '[1,0,1,2,1,1,7,5]\n[0,1,0,1,0,1,0,1]\n3'
 *
 * 有一个书店老板，他的书店开了 n 分钟。每分钟都有一些顾客进入这家商店。给定一个长度为
 * n 的整数数组 customers ，其中 customers[i] 是在第 i
 * 分钟开始时进入商店的顾客数量，所有这些顾客在第 i 分钟结束后离开。
 *
 * 在某些时候，书店老板会生气。 如果书店老板在第 i 分钟生气，那么 grumpy[i] =
 * 1，否则 grumpy[i] = 0。
 *
 * 当书店老板生气时，那一分钟的顾客就会不满意，若老板不生气则顾客是满意的。
 *
 * 书店老板知道一个秘密技巧，能抑制自己的情绪，可以让自己连续 minutes 分钟不生气，但却只能使用一次。
 *
 * 请你返回 这一天营业下来，最多有多少客户能够感到满意 。
 *
 *
 * 示例 1：
 *
 *
 * 输入：customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], minutes = 3
 * 输出：16
 * 解释：书店老板在最后 3 分钟保持冷静。
 * 感到满意的最大客户数量 = 1 + 1 + 1 + 1 + 7 + 5 = 16.
 *
 *
 * 示例 2：
 *
 *
 * 输入：customers = [1], grumpy = [0], minutes = 1
 * 输出：1
 *
 *
 *
 * 提示：
 *
 *
 * n == customers.length == grumpy.length
 * 1 <= minutes <= n <= 2 * 10^4
 * 0 <= customers[i] <= 1000
 * grumpy[i] == 0 or 1
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int maxSatisfied(vector<int>& customers, vector<int>& grumpy,
                         int minutes) {
            int n = customers.size();

            vector<int> anger_sum(n + 1);

            int sum = 0;
            for (int i = 1; i <= n; i++) {
                anger_sum[i] = anger_sum[i - 1] +
                               (grumpy[i - 1] == 0 ? 0 : customers[i - 1]);
                sum += (grumpy[i - 1] == 1 ? 0 : customers[i - 1]);
            }
            int ans = INT_MIN;
            for (int i = minutes; i <= n; i++) {
                ans = max(ans, sum + anger_sum[i] - anger_sum[i - minutes]);
            }
            return ans;
        }
};

// @lc code=end
