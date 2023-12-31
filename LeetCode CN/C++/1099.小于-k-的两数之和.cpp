/*
 * @lc app=leetcode.cn id=1099 lang=cpp
 *
 * [1099] 小于 K 的两数之和
 *
 * https://leetcode.cn/problems/two-sum-less-than-k/description/
 *
 * algorithms
 * Easy (60.05%)
 * Likes:    84
 * Dislikes: 0
 * Total Accepted:    9.6K
 * Total Submissions: 15.9K
 * Testcase Example:  '[34,23,1,24,75,33,54,8]\n60'
 *
 * 给你一个整数数组 nums 和整数 k ，返回最大和 sum ，满足存在 i < j 使得 nums[i]
 * + nums[j] = sum 且 sum < k 。如果没有满足此等式的 i,j 存在，则返回 -1 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [34,23,1,24,75,33,54,8], k = 60
 * 输出：58
 * 解释：
 * 34 和 24 相加得到 58，58 小于 60，满足题意。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [10,20,30], k = 15
 * 输出：-1
 * 解释：
 * 我们无法找到和小于 15 的两个元素。
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 1
 * 1
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int twoSumLessThanK(vector<int>& nums, int k) {
            int n = nums.size();
            sort(nums.begin(), nums.end());
            int ans = -1;
            for (int i = 0; i < n - 1; i++) {
                int l = i + 1, r = n - 1;
                while (l < r) {
                    int mid = l + r + 1 >> 1;
                    if (nums[i] + nums[mid] + 1 > k) {
                        r = mid - 1;
                    } else {
                        l = mid;
                    }
                }
                int sum = nums[i] + nums[l];
                if (sum < k)
                    ans = max(ans, sum);
            }
            return ans;
        }
};

// @lc code=end
