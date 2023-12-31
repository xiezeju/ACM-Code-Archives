/*
 * @lc app=leetcode.cn id=487 lang=cpp
 *
 * [487] 最大连续1的个数 II
 *
 * https://leetcode.cn/problems/max-consecutive-ones-ii/description/
 *
 * algorithms
 * Medium (57.10%)
 * Likes:    139
 * Dislikes: 0
 * Total Accepted:    15.9K
 * Total Submissions: 27.9K
 * Testcase Example:  '[1,0,1,1,0]'
 *
 * 给定一个二进制数组 nums ，如果最多可以翻转一个 0 ，则返回数组中连续 1
 * 的最大个数。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,0,1,1,0]
 * 输出：4
 * 解释：翻转第一个 0 可以得到最长的连续 1。
 * 当翻转以后，最大连续 1 的个数为 4。
 *
 *
 * 示例 2:
 *
 *
 * 输入：nums = [1,0,1,1,0,1]
 * 输出：4
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= nums.length <= 10^5
 * nums[i] 不是 0 就是 1.
 *
 *
 *
 *
 * 进阶：如果输入的数字是作为 无限流
 * 逐个输入如何处理？换句话说，内存不能存储下所有从流中输入的数字。您可以有效地解决吗？
 *
 */

// @lc code=start
class Solution {
    public:
        int findMaxConsecutiveOnes(vector<int>& nums) {
            int n = nums.size();
            int l = 0, r = 0;
            int zero = 0;
            int ans = 0;
            while (r < n) {
                if (!nums[r] && zero <= 1)
                    zero++;
                while (zero > 1) {
                    if (!nums[l])
                        zero--;
                    l++;
                }
                ans = max(ans, r - l + 1);
                r++;
            }
            return max(ans, r - l + 1);
        }
};

// @lc code=end
