/*
 * @lc app=leetcode.cn id=1539 lang=cpp
 *
 * [1539] 第 k 个缺失的正整数
 *
 * https://leetcode.cn/problems/kth-missing-positive-number/description/
 *
 * algorithms
 * Easy (54.08%)
 * Likes:    221
 * Dislikes: 0
 * Total Accepted:    44.4K
 * Total Submissions: 82K
 * Testcase Example:  '[2,3,4,7,11]\n5'
 *
 * 给你一个 严格升序排列 的正整数数组 arr 和一个整数 k 。
 *
 * 请你找到这个数组里第 k 个缺失的正整数。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：arr = [2,3,4,7,11], k = 5
 * 输出：9
 * 解释：缺失的正整数包括 [1,5,6,8,9,10,12,13,...] 。第 5 个缺失的正整数为 9 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：arr = [1,2,3,4], k = 2
 * 输出：6
 * 解释：缺失的正整数包括 [5,6,7,...] 。第 2 个缺失的正整数为 6 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= arr.length <= 1000
 * 1 <= arr[i] <= 1000
 * 1 <= k <= 1000
 * 对于所有 1 <= i < j <= arr.length 的 i 和 j 满足 arr[i] < arr[j] 
 *
 *
 *
 *
 * 进阶：
 *
 * 你可以设计一个时间复杂度小于 O(n) 的算法解决此问题吗？
 *
 */

// @lc code=start
class Solution {
    public:
        int findKthPositive(vector<int>& arr, int k) {
            if (arr[0] > k) {
                return k;
            }

            int n = arr.size();
            int l = 0, r = n;
            while (l < r) {
                int mid = l + r >> 1;
                if (arr[mid] - mid - 1 >= k) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }

            return arr[l - 1] + k - (arr[l - 1] - (l - 1) - 1);
        }
};

// @lc code=end
