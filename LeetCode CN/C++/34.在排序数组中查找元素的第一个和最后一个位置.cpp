/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (42.64%)
 * Likes:    2541
 * Dislikes: 0
 * Total Accepted:    881.1K
 * Total Submissions: 2.1M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值
 * target。请你找出给定目标值在数组中的开始位置和结束位置。
 *
 * 如果数组中不存在目标值 target，返回 [-1, -1]。
 *
 * 你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [5,7,7,8,8,10], target = 8
 * 输出：[3,4]
 *
 * 示例 2：
 *
 *
 * 输入：nums = [5,7,7,8,8,10], target = 6
 * 输出：[-1,-1]
 *
 * 示例 3：
 *
 *
 * 输入：nums = [], target = 0
 * 输出：[-1,-1]
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * nums 是一个非递减数组
 * -10^9 <= target <= 10^9
 *
 *
 */

// @lc code=start
class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            int n = nums.size();
            int l, r;

            if (n == 0)
                return {-1, -1};

            vector<int> a(2);

            l = 0, r = n - 1;
            while (l < r) {
                int mid = l + (r - l >> 1);
                if (target <= nums[mid]) {
                    r = mid;

                } else {
                    l = mid + 1;
                }
            }

            a[0] = nums[l] == target ? l : -1;

            l = 0, r = n - 1;
            while (l < r) {
                int mid = l + (r - l + 1 >> 1);
                if (target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid;
                }
            }

            a[1] = nums[r] == target ? r : -1;
            return a;
        }
};

// @lc code=end
