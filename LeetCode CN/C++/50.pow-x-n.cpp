/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *
 * https://leetcode.cn/problems/powx-n/description/
 *
 * algorithms
 * Medium (38.00%)
 * Likes:    1276
 * Dislikes: 0
 * Total Accepted:    409.8K
 * Total Submissions: 1.1M
 * Testcase Example:  '2.00000\n10'
 *
 * 实现 pow(x, n) ，即计算 x 的整数 n 次幂函数（即，x^n^ ）。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：x = 2.00000, n = 10
 * 输出：1024.00000
 *
 *
 * 示例 2：
 *
 *
 * 输入：x = 2.10000, n = 3
 * 输出：9.26100
 *
 *
 * 示例 3：
 *
 *
 * 输入：x = 2.00000, n = -2
 * 输出：0.25000
 * 解释：2^-2 = 1/2^2 = 1/4 = 0.25
 *
 *
 *
 *
 * 提示：
 *
 *
 * -100.0 < x < 100.0
 * -2^31 <= n <= 2^31-1
 * n 是一个整数
 * 要么 x 不为零，要么 n > 0 。
 * -10^4 <= x^n <= 10^4
 *
 *
 */

// @lc code=start
class Solution {
    public:
        double quickPower(double x, long long n) {
            double ans = 1.0;
            double c = x;
            while (n > 0) {
                if (n & 1) {
                    ans *= c;
                }
                c *= c;
                n >>= 1;
            }
            return ans;
        }

        double myPow(double x, long long n) {
            return n >= 0 ? quickPower(x, n) : 1 / quickPower(x, -n);
        }
};

// @lc code=end
