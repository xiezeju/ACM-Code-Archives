/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 *
 * https://leetcode.cn/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (52.22%)
 * Likes:    1909
 * Dislikes: 0
 * Total Accepted:    466.1K
 * Total Submissions: 892.4K
 * Testcase Example:  '[1,5,11,5]'
 *
 * 给你一个 只包含正整数 的 非空 数组 nums
 * 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,5,11,5]
 * 输出：true
 * 解释：数组可以分割成 [1, 5, 5] 和 [11] 。
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1,2,3,5]
 * 输出：false
 * 解释：数组不能分割成两个元素和相等的子集。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 1
 *
 *
 */

// @lc code=start
class Solution {
    public:
        bool canPartition(vector<int>& nums) {

            int n = nums.size();
            int sum = accumulate(nums.begin(), nums.end(), 0);

            int t = sum / 2;
            if (sum & 1)
                return false;
            vector<int> dp(t + 1);
            dp[0] = true;
            for (int i = 0; i < n; i++) {
                for (int k = t; k >= nums[i]; k--) {
                    dp[k] |= dp[k - nums[i]];
                }
            }

            return dp[t];
        }
};

// @lc code=end
