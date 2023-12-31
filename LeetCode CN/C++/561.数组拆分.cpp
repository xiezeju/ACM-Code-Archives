/*
 * @lc app=leetcode.cn id=561 lang=cpp
 *
 * [561] 数组拆分
 *
 * https://leetcode.cn/problems/array-partition/description/
 *
 * algorithms
 * Easy (78.49%)
 * Likes:    357
 * Dislikes: 0
 * Total Accepted:    145.1K
 * Total Submissions: 185.1K
 * Testcase Example:  '[1,4,3,2]'
 *
 * 给定长度为 2n 的整数数组 nums ，你的任务是将这些数分成 n 对, 例如 (a1, b1),
 * (a2, b2), ..., (an, bn) ，使得从 1 到 n 的 min(ai, bi) 总和最大。
 *
 * 返回该 最大总和 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,4,3,2]
 * 输出：4
 * 解释：所有可能的分法（忽略元素顺序）为：
 * 1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
 * 2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
 * 3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
 * 所以最大总和为 4
 *
 * 示例 2：
 *
 *
 * 输入：nums = [6,2,6,5,1,2]
 * 输出：9
 * 解释：最优的分法为 (2, 1), (2, 5), (6, 6). min(2, 1) + min(2, 5) + min(6, 6)
 * = 1 + 2
 * + 6 = 9
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 10^4
 * nums.length == 2 * n
 * -10^4 <= nums[i] <= 10^4
 *
 *
 */

// @lc code=start
class Solution {
    public:
        void radix_sort(vector<int>& a) {
            int n = a.size();
            int _max = *max_element(a.begin(), a.end());
            int max_len = 0;

            while (_max) {
                max_len++;
                _max /= 10;
            }

            int         dev = 1;
            vector<int> cnt(19), t(n);

            for (int k = 0; k < max_len; k++) {
                for (auto& val : a) {
                    int x = val / dev % 10 + 9;
                    cnt[x]++;
                }

                for (int i = 1; i < cnt.size(); i++) {
                    cnt[i] += cnt[i - 1];
                }

                for (int i = n - 1; i >= 0; i--) {
                    int x = a[i] / dev % 10 + 9;
                    t[--cnt[x]] = a[i];
                }

                a = t;
                cnt = vector<int>(19);
                dev *= 10;
            }
        }

        int arrayPairSum(vector<int>& nums) {
            int n = nums.size();
            radix_sort(nums);
            int sum = 0;
            for (int i = 0; i < n; i += 2) {
                sum += nums[i];
            }
            return sum;
        }
};

// @lc code=end
