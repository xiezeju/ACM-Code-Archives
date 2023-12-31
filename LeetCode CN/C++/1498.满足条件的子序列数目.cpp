/*
 * @lc app=leetcode.cn id=1498 lang=cpp
 *
 * [1498] 满足条件的子序列数目
 *
 * https://leetcode.cn/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/
 *
 * algorithms
 * Medium (38.55%)
 * Likes:    136
 * Dislikes: 0
 * Total Accepted:    11.3K
 * Total Submissions: 29.3K
 * Testcase Example:  '[3,5,6,7]\n9'
 *
 * 给你一个整数数组 nums 和一个整数 target 。
 *
 * 请你统计并返回 nums 中能满足其最小元素与最大元素的 和 小于或等于 target 的
 * 非空 子序列的数目。
 *
 * 由于答案可能很大，请将结果对 10^9 + 7 取余后返回。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [3,5,6,7], target = 9
 * 输出：4
 * 解释：有 4 个子序列满足该条件。
 * [3] -> 最小元素 + 最大元素 <= target (3 + 3 <= 9)
 * [3,5] -> (3 + 5 <= 9)
 * [3,5,6] -> (3 + 6 <= 9)
 * [3,6] -> (3 + 6 <= 9)
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [3,3,6,8], target = 10
 * 输出：6
 * 解释：有 6 个子序列满足该条件。（nums 中可以有重复数字）
 * [3] , [3] , [3,3], [3,6] , [3,6] , [3,3,6]
 *
 * 示例 3：
 *
 *
 * 输入：nums = [2,3,3,4,6,7], target = 12
 * 输出：61
 * 解释：共有 63 个非空子序列，其中 2 个不满足条件（[6,7], [7]）
 * 有效序列总数为（63 - 2 = 61）
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^6
 * 1 <= target <= 10^6
 *
 *
 */

// @lc code=start
class Solution {
    public:
        const int mod = 1e9 + 7;

        int quickpow(int a, int n) {
            int ans = 1;
            while (n) {
                if (n & 1) {
                    ans = (ans * a) % mod;
                }
                a = (a * a) % mod;
                n >>= 1;
            }
            return ans;
        }

        int numSubseq(vector<int>& nums, int target) {
            int n = nums.size();

            sort(nums.begin(), nums.end());

            long long ans = 0;

            for (int i = 0; i < n; i++) {
                int l = i, r = n - 1;
                while (l < r) {
                    int mid = l + r + 1 >> 1;
                    if (target + 1 <= nums[i] + nums[mid]) {
                        r = mid - 1;
                    } else {
                        l = mid;
                    }
                }
                if (nums[i] + nums[l] > target) {
                    break;
                }

                ans = (ans + quickpow(2, l - i)) % mod;
            }
            return ans;
        }
};

// @lc code=end
