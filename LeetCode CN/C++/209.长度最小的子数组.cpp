/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 *
 * https://leetcode.cn/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (46.53%)
 * Likes:    1941
 * Dislikes: 0
 * Total Accepted:    635.5K
 * Total Submissions: 1.4M
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * 给定一个含有 n 个正整数的数组和一个正整数 target 。
 *
 * 找出该数组中满足其总和大于等于 target 的长度最小的 连续子数组 [numsl,
 * numsl+1, ..., numsr-1, numsr]
 * ，并返回其长度。如果不存在符合条件的子数组，返回 0 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：target = 7, nums = [2,3,1,2,4,3]
 * 输出：2
 * 解释：子数组 [4,3] 是该条件下的长度最小的子数组。
 *
 *
 * 示例 2：
 *
 *
 * 输入：target = 4, nums = [1,4,4]
 * 输出：1
 *
 *
 * 示例 3：
 *
 *
 * 输入：target = 11, nums = [1,1,1,1,1,1,1,1]
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= target <= 10^9
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^5
 *
 *
 *
 *
 * 进阶：
 *
 *
 * 如果你已经实现 O(n) 时间复杂度的解法, 请尝试设计一个 O(n log(n))
 * 时间复杂度的解法。
 *
 *
 */

// @lc code=start
// 二分查找做法
/*
class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            int         n = nums.size();
            vector<int> sum(n + 1);

            for (int i = 1; i <= n; i++)
                sum[i] = sum[i - 1] + nums[i - 1];

            int ans = n + 1;
            for (int i = 1; i <= n; i++) {
                // 枚举每个sum的起点：sum[0...n-1]，然后对起点后面的数进行二分
                int l = i, r = n;
                while (l < r) {
                    // 寻找 >= target + sum[i - 1] 的最小值
                    int mid = l + r >> 1;
                    if (target <= sum[mid] - sum[i - 1])
                        r = mid;
                    else
                        l = mid + 1;
                }
                // 由于不管二分的结果如何 l 一定会落在 [i, n]内
                // 因此一定要检验是否满足题意，若满足才更新答案
                if (target <= sum[l] - sum[i - 1]) {
                    ans = min(ans, l - (i - 1));
                }
            }

            return ans > n ? 0 : ans;
        }
};
*/

class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            int n = nums.size();
            int ans = n + 1;

            int l = 0, r = 0;
            int sum = 0;
            while (r < n) {
                sum += nums[r];
                while (sum >= target) {
                    sum -= nums[l];
                    ans = min(ans, r - l + 1);
                    l++;
                }
                r++;
            }

            return ans > n ? 0 : ans;
        }
};

// @lc code=end
