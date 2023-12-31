/*
 * @lc app=leetcode.cn id=658 lang=cpp
 *
 * [658] 找到 K 个最接近的元素
 *
 * https://leetcode.cn/problems/find-k-closest-elements/description/
 *
 * algorithms
 * Medium (47.89%)
 * Likes:    517
 * Dislikes: 0
 * Total Accepted:    94.1K
 * Total Submissions: 196.4K
 * Testcase Example:  '[1,2,3,4,5]\n4\n3'
 *
 * 给定一个 排序好 的数组 arr ，两个整数 k 和 x ，从数组中找到最靠近
 * x（两数之差最小）的 k 个数。返回的结果必须要是按升序排好的。
 *
 * 整数 a 比整数 b 更接近 x 需要满足：
 *
 *
 * |a - x| < |b - x| 或者
 * |a - x| == |b - x| 且 a < b
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：arr = [1,2,3,4,5], k = 4, x = 3
 * 输出：[1,2,3,4]
 *
 *
 * 示例 2：
 *
 *
 * 输入：arr = [1,2,3,4,5], k = 4, x = -1
 * 输出：[1,2,3,4]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= k <= arr.length
 * 1 <= arr.length <= 10^4
 * arr 按 升序 排列
 * -10^4 <= arr[i], x <= 10^4
 *
 *
 */

// @lc code=start
class Solution {
    public:
        vector<int> findClosestElements(vector<int>& arr, int k, int x) {
            int n = arr.size();
            int l = 0, r = n - k;

            while (l < r) {
                int mid = l + (r - l >> 1);
                if (x - arr[mid] <= arr[mid + k] - x) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            return vector<int>(arr.begin() + l, arr.begin() + l + k);
        }
};

// @lc code=end
