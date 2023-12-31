/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 *
 * https://leetcode.cn/problems/find-the-duplicate-number/description/
 *
 * algorithms
 * Medium (64.14%)
 * Likes:    2298
 * Dislikes: 0
 * Total Accepted:    346.9K
 * Total Submissions: 541.5K
 * Testcase Example:  '[1,3,4,2,2]'
 *
 * 给定一个包含 n + 1 个整数的数组 nums ，其数字都在 [1, n] 范围内（包括 1 和
 * n），可知至少存在一个重复的整数。
 *
 * 假设 nums 只有 一个重复的整数 ，返回 这个重复的数 。
 *
 * 你设计的解决方案必须 不修改 数组 nums 且只用常量级 O(1) 的额外空间。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,3,4,2,2]
 * 输出：2
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [3,1,3,4,2]
 * 输出：3
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 10^5
 * nums.length == n + 1
 * 1 <= nums[i] <= n
 * nums 中 只有一个整数 出现 两次或多次 ，其余整数均只出现 一次
 *
 *
 *
 *
 * 进阶：
 *
 *
 * 如何证明 nums 中至少存在一个重复的数字?
 * 你可以设计一个线性级时间复杂度 O(n) 的解决方案吗？
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int findDuplicate(vector<int>& nums) {
            int n = nums.size();
            int l = 0, r = n - 1;
            while (l < r) {
                int mid = l + r >> 1;
                int cnt = 0;
                for (int i = 0; i < n; i++) {
                    cnt += nums[i] <= mid;
                }
                if (cnt > mid) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            return l;
        }
};

// @lc code=end
