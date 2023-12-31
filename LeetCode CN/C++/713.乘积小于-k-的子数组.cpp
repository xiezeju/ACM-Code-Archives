/*
 * @lc app=leetcode.cn id=713 lang=cpp
 *
 * [713] 乘积小于 K 的子数组
 *
 * https://leetcode.cn/problems/subarray-product-less-than-k/description/
 *
 * algorithms
 * Medium (49.87%)
 * Likes:    748
 * Dislikes: 0
 * Total Accepted:    108.8K
 * Total Submissions: 217.6K
 * Testcase Example:  '[10,5,2,6]\n100'
 *
 * 给你一个整数数组 nums 和一个整数 k ，请你返回子数组内所有元素的乘积严格小于 k
 * 的连续子数组的数目。
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [10,5,2,6], k = 100
 * 输出：8
 * 解释：8 个乘积小于 100
 * 的子数组分别为：[10]、[5]、[2],、[6]、[10,5]、[5,2]、[2,6]、[5,2,6]。
 * 需要注意的是 [10,5,2] 并不是乘积小于 100 的子数组。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1,2,3], k = 0
 * 输出：0
 *
 *
 *
 * 提示: 
 *
 *
 * 1 <= nums.length <= 3 * 10^4
 * 1 <= nums[i] <= 1000
 * 0 <= k <= 10^6
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int numSubarrayProductLessThanK(vector<int>& nums, int k) {
            if (k <= 1)
                return 0;
            int n = nums.size();
            int ans = 0;
            int l = 0, r = 0;

            long long mul = 1;

            while (r < n) {
                mul *= nums[r];
                while (mul >= k) {
                    mul /= nums[l];
                    l++;
                }
                r++;
                ans += r - l;
            }
            return ans;
        }
};

// @lc code=end
