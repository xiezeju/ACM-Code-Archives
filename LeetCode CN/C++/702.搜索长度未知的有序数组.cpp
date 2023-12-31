/*
 * @lc app=leetcode.cn id=702 lang=cpp
 *
 * [702] 搜索长度未知的有序数组
 *
 * https://leetcode.cn/problems/search-in-a-sorted-array-of-unknown-size/description/
 *
 * algorithms
 * Medium (74.74%)
 * Likes:    66
 * Dislikes: 0
 * Total Accepted:    8.5K
 * Total Submissions: 11.4K
 * Testcase Example:  '[-1,0,3,5,9,12]\n9'
 *
 * 这是一个交互问题。
 *
 * 您有一个升序整数数组，其长度未知。您没有访问数组的权限，但是可以使用 ArrayReader 接口访问它。你可以调用
 * ArrayReader.get(i):
 *
 *
 *
 * 返回数组第i^th个索引(0-indexed)处的值(即secret[i])，或者
 *
 *
 * 如果 i  超出了数组的边界，则返回 2^31 - 1
 *
 *
 *
 * 你也会得到一个整数 target。
 *
 * 如果存在secret[k] == target，请返回索引 k 的值；否则返回 -1
 *
 * 你必须写一个时间复杂度为 O(log n) 的算法。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入: secret = [-1,0,3,5,9,12], target = 9
 * 输出: 4
 * 解释: 9 存在在 nums 中，下标为 4
 *
 *
 * 示例 2：
 *
 *
 * 输入: secret = [-1,0,3,5,9,12], target = 2
 * 输出: -1
 * 解释: 2 不在数组中所以返回 -1
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= secret.length <= 10^4
 * -10^4 <= secret[i], target <= 10^4
 * secret 严格递增
 *
 *
 */

// @lc code=start
/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
    public:
        int search(const ArrayReader& reader, int target) {
            int l = 0, r = 1e4 + 10;
            while (l < r) {
                int mid = l + r >> 1;
                if (target <= reader.get(mid)) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (reader.get(l) == target) {
                return l;
            }
            return -1;
        }
};

// @lc code=end
