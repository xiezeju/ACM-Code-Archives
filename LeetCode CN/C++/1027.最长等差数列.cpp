/*
 * @lc app=leetcode.cn id=1027 lang=cpp
 *
 * [1027] 最长等差数列
 *
 * https://leetcode.cn/problems/longest-arithmetic-subsequence/description/
 *
 * algorithms
 * Medium (49.24%)
 * Likes:    338
 * Dislikes: 0
 * Total Accepted:    41.2K
 * Total Submissions: 83.6K
 * Testcase Example:  '[3,6,9,12]'
 *
 * 给你一个整数数组 nums，返回 nums 中最长等差子序列的长度。
 *
 * 回想一下，nums 的子序列是一个列表 nums[i1], nums[i2], ..., nums[ik] ，且 0 <=
 * i1 < i2 < ... < ik <= nums.length - 1。并且如果 seq[i+1] - seq[i]( 0 <= i <
 * seq.length - 1) 的值都相同，那么序列 seq 是等差的。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [3,6,9,12]
 * 输出：4
 * 解释：
 * 整个数组是公差为 3 的等差数列。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [9,4,7,2,10]
 * 输出：3
 * 解释：
 * 最长的等差子序列是 [4,7,10]。
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [20,1,15,3,10,5,8]
 * 输出：4
 * 解释：
 * 最长的等差子序列是 [20,15,10,5]。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= nums.length <= 1000
 * 0 <= nums[i] <= 500
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int longestArithSeqLength(vector<int>& nums) {
            int n = nums.size();

            // dp[i][j]代表以nums[i]结尾，以j为公差的最长子序列的长度
            vector<vector<int>> dp(n + 1, vector<int>(1001));

            int ans = 0;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    int diff = nums[i] - nums[j] + 500;
                    dp[i][diff] = max(dp[i][diff], dp[j][diff] + 1);
                    ans = max(ans, dp[i][diff]);
                }
            }

            return ans + 1;
        }
};

// @lc code=end
