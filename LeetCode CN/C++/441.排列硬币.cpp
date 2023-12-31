/*
 * @lc app=leetcode.cn id=441 lang=cpp
 *
 * [441] 排列硬币
 *
 * https://leetcode.cn/problems/arranging-coins/description/
 *
 * algorithms
 * Easy (45.16%)
 * Likes:    288
 * Dislikes: 0
 * Total Accepted:    127.2K
 * Total Submissions: 282K
 * Testcase Example:  '5'
 *
 * 你总共有 n 枚硬币，并计划将它们按阶梯状排列。对于一个由 k 行组成的阶梯，其第
 * i 行必须正好有 i 枚硬币。阶梯的最后一行 可能 是不完整的。
 *
 * 给你一个数字 n ，计算并返回可形成 完整阶梯行 的总行数。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 5
 * 输出：2
 * 解释：因为第三行不完整，所以返回 2 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 8
 * 输出：3
 * 解释：因为第四行不完整，所以返回 3 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 2^31 - 1
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int arrangeCoins(long long n) {
            n <<= 1;
            long long l = 0, r = sqrt(n);
            while (l < r) {
                long long mid = l + r + 1 >> 1;
                if (n < mid * (mid + 1)) {
                    r = mid - 1;
                } else {
                    l = mid;
                }
            }
            return l;
        }
};

// @lc code=end
