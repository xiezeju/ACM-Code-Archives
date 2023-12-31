/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 *
 * https://leetcode.cn/problems/next-permutation/description/
 *
 * algorithms
 * Medium (38.59%)
 * Likes:    2375
 * Dislikes: 0
 * Total Accepted:    471.1K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,3]'
 *
 * 整数数组的一个 排列  就是将其所有成员以序列或线性顺序排列。
 *
 *
 * 例如，arr = [1,2,3] ，以下这些都可以视作 arr
 * 的排列：[1,2,3]、[1,3,2]、[3,1,2]、[2,3,1] 。
 *
 *
 * 整数数组的 下一个排列
 * 是指其整数的下一个字典序更大的排列。更正式地，如果数组的所有排列根据其字典顺序从小到大排列在一个容器中，那么数组的
 * 下一个排列
 * 就是在这个有序容器中排在它后面的那个排列。如果不存在下一个更大的排列，那么这个数组必须重排为字典序最小的排列（即，其元素按升序排列）。
 *
 *
 * 例如，arr = [1,2,3] 的下一个排列是 [1,3,2] 。
 * 类似地，arr = [2,3,1] 的下一个排列是 [3,1,2] 。
 * 而 arr = [3,2,1] 的下一个排列是 [1,2,3] ，因为 [3,2,1]
 * 不存在一个字典序更大的排列。
 *
 *
 * 给你一个整数数组 nums ，找出 nums 的下一个排列。
 *
 * 必须 原地 修改，只允许使用额外常数空间。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,2,3]
 * 输出：[1,3,2]
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [3,2,1]
 * 输出：[1,2,3]
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [1,1,5]
 * 输出：[1,5,1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 100
 *
 *
 */

// @lc code=start
class Solution {
    public:
        void nextPermutation(vector<int>& nums) {
            int n = nums.size();
            int r = n - 1;
            // 从后往前寻找第一个非降序的数
            while (r >= 1) {
                if (nums[r - 1] < nums[r]) {
                    break;
                }
                r--;
            }

            // 没找到说明这个数组都是降序排列的，直接排序返回
            if (r == 0) {
                sort(nums.begin(), nums.end());
                return;
            }

            // 找到非降序和降序的分界点 r 之后，从后往前找第一个比
            // nums[r-1]大的数
            for (int i = n - 1; i >= r - 1; i--) {
                // 找到了后交换，并且翻转后面的降序序列变为升序序列
                // 解释原因：
                // 因为在找到第一个比nums[r-1]大的数之后交换后，r-1的位置恰好变大了一点
                // 而交换过去的那个较小的数并不会改变后面序列的降序性，现在只需要把它变成升序
                // 后面变为升序之后就是以交换后r-1位置上的数为最高位构成的数的最小值
                if (nums[r - 1] < nums[i]) {
                    swap(nums[r - 1], nums[i]);
                    reverse(nums.begin() + r, nums.end());
                    return;
                }
            }
        }
};

// @lc code=end
