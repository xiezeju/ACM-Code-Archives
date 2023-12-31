/*
 * @lc app=leetcode.cn id=795 lang=cpp
 *
 * [795] 区间子数组个数
 *
 * https://leetcode.cn/problems/number-of-subarrays-with-bounded-maximum/description/
 *
 * algorithms
 * Medium (57.76%)
 * Likes:    363
 * Dislikes: 0
 * Total Accepted:    37.1K
 * Total Submissions: 64.1K
 * Testcase Example:  '[2,1,4,3]\n2\n3'
 *
 * 给你一个整数数组 nums 和两个整数：left 及 right 。找出 nums
 * 中连续、非空且其中最大元素在范围 [left, right]
 * 内的子数组，并返回满足条件的子数组的个数。
 *
 * 生成的测试用例保证结果符合 32-bit 整数范围。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [2,1,4,3], left = 2, right = 3
 * 输出：3
 * 解释：满足条件的三个子数组：[2], [2, 1], [3]
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [2,9,2,5,6], left = 2, right = 8
 * 输出：7
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * 0 <= nums[i] <= 10^9
 * 0 <= left <= right <= 10^9
 *
 *
 */

// @lc code=start
// 双指针做法，记录最后一次合法的最大值和不合法最大值的位置
/*
class Solution {
    public:
        int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
            int n = nums.size();
            int lastNoLegalMaxPos = -1, lastLegalMaxPos = -1;
            int sum = 0;
            for (int i = 0; i < n; i++) {
                int x = nums[i];
                if (x > right) {
                    lastNoLegalMaxPos = i;
                    lastLegalMaxPos = -1;
                } else if (left <= x && x <= right) {
                    lastLegalMaxPos = i;
                }
                if (lastLegalMaxPos != -1) {
                    sum += lastLegalMaxPos - lastNoLegalMaxPos;
                }
            }
            return sum;
        }
};
*/
// 计数法
class Solution {
    public:
        int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
            int n = nums.size();
            int sum = 0;
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                int x = nums[i];
                cnt = x <= right ? cnt + 1 : 0;
                sum += cnt;
            }
            cnt = 0;
            for (int i = 0; i < n; i++) {
                int x = nums[i];
                cnt = x < left ? cnt + 1 : 0;
                sum -= cnt;
            }
            return sum;
        }
};

// @lc code=end
