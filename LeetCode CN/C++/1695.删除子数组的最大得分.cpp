/*
 * @lc app=leetcode.cn id=1695 lang=cpp
 *
 * [1695] 删除子数组的最大得分
 *
 * https://leetcode.cn/problems/maximum-erasure-value/description/
 *
 * algorithms
 * Medium (52.45%)
 * Likes:    73
 * Dislikes: 0
 * Total Accepted:    15.3K
 * Total Submissions: 29.2K
 * Testcase Example:  '[4,2,4,5,6]'
 *
 * 给你一个正整数数组 nums ，请你从中删除一个含有 若干不同元素
 * 的子数组。删除子数组的 得分 就是子数组各元素之 和 。
 *
 * 返回 只删除一个 子数组可获得的 最大得分 。
 *
 * 如果数组 b 是数组 a 的一个连续子序列，即如果它等于 a[l],a[l+1],...,a[r]
 * ，那么它就是 a 的一个子数组。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [4,2,4,5,6]
 * 输出：17
 * 解释：最优子数组是 [2,4,5,6]
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [5,2,1,2,5,2,1,2,5]
 * 输出：8
 * 解释：最优子数组是 [5,2,1] 或 [1,2,5]
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
        int maximumUniqueSubarray(vector<int>& nums) {
            int n = nums.size();
            int l = 0, r = 0;
            int ans = 0;

            vector<int> sum(n + 1);
            vector<int> window(1e4 + 1);

            for (int i = 1; i <= n; i++) {
                sum[i] = sum[i - 1] + nums[i - 1];
            }

            while (r < n) {
                int R = nums[r];
                window[R]++;

                while (window[R] > 1) {
                    int L = nums[l];
                    window[L]--;
                    l++;
                }

                ans = max(ans, sum[r + 1] - sum[l]);
                r++;
            }

            return ans;
        }
};

// @lc code=end
