/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 *
 * https://leetcode.cn/problems/majority-element/description/
 *
 * algorithms
 * Easy (66.55%)
 * Likes:    2027
 * Dislikes: 0
 * Total Accepted:    801.6K
 * Total Submissions: 1.2M
 * Testcase Example:  '[3,2,3]'
 *
 * 给定一个大小为 n 的数组 nums
 * ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
 *
 * 你可以假设数组是非空的，并且给定的数组总是存在多数元素。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [3,2,3]
 * 输出：3
 *
 * 示例 2：
 *
 *
 * 输入：nums = [2,2,1,1,1,2,2]
 * 输出：2
 *
 *
 *
 * 提示：
 *
 *
 * n == nums.length
 * 1 <= n <= 5 * 10^4
 * -10^9 <= nums[i] <= 10^9
 *
 *
 *
 *
 * 进阶：尝试设计时间复杂度为 O(n)、空间复杂度为 O(1) 的算法解决此问题。
 *
 */

// @lc code=start

// 练习快排，但本题使用HashTable时间复杂度O(n)
class Solution {
    public:
        int partion(vector<int>& nums, int l, int r) {
            int re = l + rand() % (r - l + 1);
            swap(nums[re], nums[l]);
            int i = l, j = r;
            while (i < j) {
                while (i < j && nums[j] >= nums[l])
                    j--;
                while (i < j && nums[i] <= nums[l])
                    i++;
                swap(nums[i], nums[j]);
            }
            swap(nums[i], nums[l]);
            return i;
        }

        void quick_sort(vector<int>& nums, int l, int r) {
            if (l >= r) {
                return;
            }
            int mid = partion(nums, l, r);
            int i = mid - 1, j = mid + 1;
            while (i > l && nums[i] == nums[i + 1])
                i--;
            while (j < r && nums[j] == nums[j - 1])
                j++;
            quick_sort(nums, l, i);
            quick_sort(nums, j, r);
        }

        int majorityElement(vector<int>& nums) {
            int n = nums.size();
            quick_sort(nums, 0, n - 1);
            return nums[n / 2];
        }
};

// @lc code=end
