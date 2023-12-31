/*
 * @lc app=leetcode.cn id=689 lang=cpp
 *
 * [689] 三个无重叠子数组的最大和
 *
 * https://leetcode.cn/problems/maximum-sum-of-3-non-overlapping-subarrays/description/
 *
 * algorithms
 * Hard (56.20%)
 * Likes:    359
 * Dislikes: 0
 * Total Accepted:    25.6K
 * Total Submissions: 44.8K
 * Testcase Example:  '[1,2,1,2,6,7,5,1]\n2'
 *
 * 给你一个整数数组 nums 和一个整数 k ，找出三个长度为 k
 * 、互不重叠、且全部数字和（3 * k 项）最大的子数组，并返回这三个子数组。
 *
 * 以下标的数组形式返回结果，数组中的每一项分别指示每个子数组的起始位置（下标从
 * 0 开始）。如果有多个结果，返回字典序最小的一个。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,2,1,2,6,7,5,1], k = 2
 * 输出：[0,3,5]
 * 解释：子数组 [1, 2], [2, 6], [7, 5] 对应的起始下标为 [0, 3, 5]。
 * 也可以取 [2, 1], 但是结果 [1, 3, 5] 在字典序上更大。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1,2,1,2,1,2,1,2,1], k = 2
 * 输出：[0,2,4]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 2 * 10^4
 * 1 <= nums[i] < 2^16
 * 1 <= k <= floor(nums.length / 3)
 *
 *
 */

// @lc code=start

// 待研究
class Solution {
    public:
        vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
            int n = nums.size();

            vector<int> sum(n + 1);

            for (int i = 1; i <= n; i++) {
                sum[i] = sum[i - 1] + nums[i - 1];
            }

            vector<vector<int>> dp(n + 5, vector<int>(4));
            vector<int>         ans(3);

            for (int i = n - k + 1; i >= 1; i--) {
                for (int j = 1; j < 4; j++)
                    dp[i][j] =
                        max(dp[i + 1][j],
                            dp[i + k][j - 1] + sum[i + k - 1] - sum[i - 1]);
            }

            int i = 1, j = 3, idx = 0;
            while (j > 0) {
                if (dp[i + 1][j] >
                    dp[i + k][j - 1] + sum[i + k - 1] - sum[i - 1]) {
                    i++;
                } else {
                    ans[idx++] = i - 1;
                    i += k;
                    j--;
                }
            }

            return ans;
        }
};

// @lc code=end
