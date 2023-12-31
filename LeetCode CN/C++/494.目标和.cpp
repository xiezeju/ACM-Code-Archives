/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 *
 * https://leetcode.cn/problems/target-sum/description/
 *
 * algorithms
 * Medium (48.44%)
 * Likes:    1778
 * Dislikes: 0
 * Total Accepted:    389.8K
 * Total Submissions: 805K
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * 给你一个非负整数数组 nums 和一个整数 target 。
 *
 * 向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式
 * ：
 *
 *
 * 例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-'
 * ，然后串联起来得到表达式 "+2-1" 。
 *
 *
 * 返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,1,1,1,1], target = 3
 * 输出：5
 * 解释：一共有 5 种方法让最终目标和为 3 。
 * -1 + 1 + 1 + 1 + 1 = 3
 * +1 - 1 + 1 + 1 + 1 = 3
 * +1 + 1 - 1 + 1 + 1 = 3
 * +1 + 1 + 1 - 1 + 1 = 3
 * +1 + 1 + 1 + 1 - 1 = 3
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1], target = 1
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 20
 * 0 <= nums[i] <= 1000
 * 0 <= sum(nums[i]) <= 1000
 * -1000 <= target <= 1000
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int findTargetSumWays(vector<int>& nums, int target) {
            int n = nums.size();

            int sum = 0;

            for (auto& i : nums) {
                sum += i;
            }
            // 由于题目给的nums中都是非负整数，考虑到构成target的元素分为两部分，一部分是加负号的，一部分是剩下加正号的
            // 记加负号的元素总和为negative，那么加正号的元素总和就是 sum
            // -negative，而target =  (sum-negative) - negative
            // 问题就转换为从数组中选取元素使得总和为negative

            // negative指的是原数组里的元素应该加负号的总和，所以它是非负的，且为偶数
            if (sum - target < 0 || (sum - target) & 1 == 1)
                return 0;
            int negative = (sum - target) / 2;

            vector<int> dp(negative + 1);
            dp[0] = 1;

            for (int i = 0; i < n; i++) {
                for (int j = negative; j >= nums[i]; j--) {
                    dp[j] += dp[j - nums[i]];
                }
            }

            return dp[negative];
        }
};

// @lc code=end
