/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除并获得点数
 *
 * https://leetcode.cn/problems/delete-and-earn/description/
 *
 * algorithms
 * Medium (61.58%)
 * Likes:    845
 * Dislikes: 0
 * Total Accepted:    104.9K
 * Total Submissions: 170.5K
 * Testcase Example:  '[3,4,2]'
 *
 * 给你一个整数数组 nums ，你可以对它进行一些操作。
 *
 * 每次操作中，选择任意一个 nums[i] ，删除它并获得 nums[i] 的点数。之后，你必须删除
 * 所有 等于 nums[i] - 1 和 nums[i] + 1 的元素。
 *
 * 开始你拥有 0 个点数。返回你能通过这些操作获得的最大点数。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [3,4,2]
 * 输出：6
 * 解释：
 * 删除 4 获得 4 个点数，因此 3 也被删除。
 * 之后，删除 2 获得 2 个点数。总共获得 6 个点数。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [2,2,3,3,3,4]
 * 输出：9
 * 解释：
 * 删除 3 获得 3 个点数，接着要删除两个 2 和 4 。
 * 之后，再次删除 3 获得 3 个点数，再次删除 3 获得 3 个点数。
 * 总共获得 9 个点数。
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
        int deleteAndEarn(vector<int>& nums) {
            int n = nums.size();

            int Max = *max_element(nums.begin(), nums.end());

            vector<int> sum(Max + 1);
            for (int& i : nums) {
                sum[i] += i;
            }

            vector<int> dp(Max + 1);
            dp[0] = sum[0];
            dp[1] = max(sum[0], sum[1]);
            for (int i = 2; i < dp.size(); i++) {
                dp[i] = max(dp[i - 1], dp[i - 2] + sum[i]);
            }
            return *max_element(dp.begin(), dp.end());
        }
};

// @lc code=end
