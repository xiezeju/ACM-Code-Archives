/*
 * @lc app=leetcode.cn id=805 lang=cpp
 *
 * [805] 数组的均值分割
 *
 * https://leetcode.cn/problems/split-array-with-same-average/description/
 *
 * algorithms
 * Hard (42.81%)
 * Likes:    293
 * Dislikes: 0
 * Total Accepted:    22.4K
 * Total Submissions: 52.2K
 * Testcase Example:  '[1,2,3,4,5,6,7,8]'
 *
 * 给定你一个整数数组 nums
 *
 * 我们要将 nums 数组中的每个元素移动到 A 数组
 * 或者 B 数组中，使得 A 数组和 B 数组不为空，并且 average(A) == average(B) 。
 *
 * 如果可以完成则返回true ， 否则返回 false  。
 *
 * 注意：对于数组 arr ,  average(arr) 是 arr 的所有元素的和除以 arr 长度。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: nums = [1,2,3,4,5,6,7,8]
 * 输出: true
 * 解释: 我们可以将数组分割为 [1,4,5,8] 和 [2,3,6,7], 他们的平均值都是4.5。
 *
 *
 * 示例 2:
 *
 *
 * 输入: nums = [3,1]
 * 输出: false
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= nums.length <= 30
 * 0 <= nums[i] <= 10^4
 *
 *
 */

// @lc code=start
class Solution {
    public:
        bool splitArraySameAverage(vector<int>& nums) {
            int  n = nums.size();
            int  sum = accumulate(nums.begin(), nums.end(), 0);
            // 由题意 S1*n2 = S2*n1 -> S1*n2-(Sum-S1)*n1 = 0 -> S1* n = Sum * n1
            // 剪枝，判断是否存在一个满足sum*i = n*
            // S1的S1，如果不存在说明无法构成平均值相等的子集
            bool ok = false;
            for (int i = 1; i <= n / 2 && !ok; i++) {
                if (sum * i % n == 0) {
                    ok = true;
                }
            }
            if (!ok) {
                return false;
            }

            // dp[i]做状态压缩，第k位代表和为i的集合能否用k个数字取得，每次更新的时候只需要将k左移一位就可以
            vector<int> dp(sum + 1);
            dp[0] = 1;
            for (int& num : nums) {
                for (int i = sum; i >= num; i--) {
                    // 从小到大更新，每次将num扩充进dp数组，能放得下的话对应和的数字构成个数+1，也即向左移动一位
                    dp[i] |= dp[i - num] << 1;
                }
                for (int i = 1; i < n; i++) {
                    // 确保sum*i能被n整除，然后检查和S1为sum*i/n的集合能否由i和数字组合而成，能的话其二进制数对应位置上为1
                    if (!(sum * i % n) && dp[sum * i / n] >> i & 1) {
                        return true;
                    }
                }
            }
            return false;
        }
};

// @lc code=end
