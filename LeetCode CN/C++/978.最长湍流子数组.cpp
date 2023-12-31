/*
 * @lc app=leetcode.cn id=978 lang=cpp
 *
 * [978] 最长湍流子数组
 *
 * https://leetcode.cn/problems/longest-turbulent-subarray/description/
 *
 * algorithms
 * Medium (47.60%)
 * Likes:    240
 * Dislikes: 0
 * Total Accepted:    53.8K
 * Total Submissions: 112.8K
 * Testcase Example:  '[9,4,2,10,7,8,8,1,9]'
 *
 * 给定一个整数数组 arr ，返回 arr 的 最大湍流子数组的长度 。
 *
 * 如果比较符号在子数组中的每个相邻元素对之间翻转，则该子数组是 湍流子数组 。
 *
 * 更正式地来说，当 arr 的子数组 A[i], A[i+1], ...,
 * A[j] 满足仅满足下列条件时，我们称其为湍流子数组：
 *
 *
 * 若 i <= k < j ：
 *
 *
 * 当 k 为奇数时， A[k] > A[k+1]，且
 * 当 k 为偶数时，A[k] < A[k+1]；
 *
 *
 * 或 若 i <= k < j ：
 *
 * 当 k 为偶数时，A[k] > A[k+1] ，且
 * 当 k 为奇数时， A[k] < A[k+1]。
 *
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：arr = [9,4,2,10,7,8,8,1,9]
 * 输出：5
 * 解释：arr[1] > arr[2] < arr[3] > arr[4] < arr[5]
 *
 * 示例 2：
 *
 *
 * 输入：arr = [4,8,12,16]
 * 输出：2
 *
 *
 * 示例 3：
 *
 *
 * 输入：arr = [100]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= arr.length <= 4 * 10^4
 * 0 <= arr[i] <= 10^9
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int maxTurbulenceSize(vector<int>& arr) {
            int n = arr.size();
            if (n == 1)
                return 1;
            int l = 0, r = 0;
            int ans = 1;
            while (r < n - 1) {
                if (l == r) {
                    if (arr[l] == arr[l + 1]) {
                        l++;
                    }
                    r++;
                } else {
                    if (arr[r - 1] < arr[r] && arr[r] > arr[r + 1])
                        r++;
                    else if (arr[r - 1] > arr[r] && arr[r] < arr[r + 1])
                        r++;
                    else
                        l = r;
                }
                ans = max(ans, r - l + 1);
            }
            return ans;
        }
};

// @lc code=end
