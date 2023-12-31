/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 *
 * https://leetcode.cn/problems/number-of-longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (44.77%)
 * Likes:    809
 * Dislikes: 0
 * Total Accepted:    93.1K
 * Total Submissions: 207.9K
 * Testcase Example:  '[1,3,5,4,7]'
 *
 * 给定一个未排序的整数数组 nums ， 返回最长递增子序列的个数 。
 *
 * 注意 这个数列必须是 严格 递增的。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: [1,3,5,4,7]
 * 输出: 2
 * 解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
 *
 *
 * 示例 2:
 *
 *
 * 输入: [2,2,2,2,2]
 * 输出: 5
 * 解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。
 *
 *
 *
 *
 * 提示: 
 *
 *
 *
 *
 * 1 <= nums.length <= 2000
 * -10^6 <= nums[i] <= 10^6
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int findNumberOfLIS(vector<int>& nums) {
            int n = nums.size();
            int maxLength = 0;
            int ans = 0;

            // dp[i]代表以nums[i]结尾的最长上升子序列的长度
            // sum[i]代表以nums[i]结尾的最长上升子序列的个数

            vector<int> dp(n, 1);
            vector<int> sum(n, 1);

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    if (nums[i] > nums[j]) {
                        // 如果当前的dp[i]需要更新则更新，顺便重置sum[i]
                        if (dp[j] + 1 > dp[i]) {
                            dp[i] = dp[j] + 1;
                            sum[i] = sum[j];
                        } else if (dp[j] + 1 == dp[i]) {
                            // 如果此时以nums[j]结尾的最长上升子序列的长度恰好比以nums[i]结尾的最长上升子序列长度少1，就将sum[i]加上sum[j]
                            sum[i] += sum[j];
                        }
                    }
                }
                // 更新maxLength和ans
                if (dp[i] > maxLength) {
                    maxLength = dp[i];
                    ans = sum[i];
                } else if (dp[i] == maxLength) {
                    // 如果有多个长度相等的不同最长上升子序列都要加上
                    ans += sum[i];
                }
            }
            return ans;
        }
};

// @lc code=end
