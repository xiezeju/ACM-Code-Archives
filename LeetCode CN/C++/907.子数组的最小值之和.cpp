/*
 * @lc app=leetcode.cn id=907 lang=cpp
 *
 * [907] 子数组的最小值之和
 *
 * https://leetcode.cn/problems/sum-of-subarray-minimums/description/
 *
 * algorithms
 * Medium (38.44%)
 * Likes:    692
 * Dislikes: 0
 * Total Accepted:    50.2K
 * Total Submissions: 129.4K
 * Testcase Example:  '[3,1,2,4]'
 *
 * 给定一个整数数组 arr，找到 min(b) 的总和，其中 b 的范围为 arr
 * 的每个（连续）子数组。
 *
 * 由于答案可能很大，因此 返回答案模 10^9 + 7 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：arr = [3,1,2,4]
 * 输出：17
 * 解释：
 * 子数组为
 * [3]，[1]，[2]，[4]，[3,1]，[1,2]，[2,4]，[3,1,2]，[1,2,4]，[3,1,2,4]。
 * 最小值为 3，1，2，4，1，1，2，1，1，1，和为 17。
 *
 * 示例 2：
 *
 *
 * 输入：arr = [11,81,94,43,3]
 * 输出：444
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 1
 *
 *
 *
 *
 */

// @lc code=start
// 精简答案版本
/*
class Solution {
    public:
        const int mod = 1e9 + 7;

        int sumSubarrayMins(vector<int>& a) {
            int n = a.size();

            stack<int>  s;
            vector<int> dp(n);

            int ans = 0;
            for (int i = 0; i < n; i++) {
                while (!s.empty() && a[s.top()] >= a[i])
                    s.pop();
                if (!s.empty()) {
                    int x = s.top();
                    dp[i] = ((((i - x) * a[i]) % mod) + dp[x]) % mod;
                } else
                    dp[i] = (i + 1) * a[i];
                s.push(i);
                ans = (ans + dp[i]) % mod;
            }
            return ans;
        }
};
*/
/*
class Solution {
    public:
        const int mod = 1e9 + 7;

        int sumSubarrayMins(vector<int>& a) {
            int n = a.size();

            stack<int>  s;
            // dp[i]代表序列[0...i]的min(b)总和
            // dp[i]由下面两个部分的和构成：
            // 1. 以a[i]为最小值能够成的子序列的min(b)总和
            // 2. 以左边第一个比a[i]小的数为最小值能构成的子序列的min(b)总和
            vector<int> dp(n);

            int ans = 0;
            for (int i = 0; i < n; i++) {
                int l = -1;
                // 找到左边第一个比当前数小的数
                while (!s.empty() && a[s.top()] >= a[i]) {
                    s.pop();
                }
                // 如果有，记录该小数下标
                if (!s.empty()) {
                    l = s.top();
                }

                s.push(i);

                //
由于该小数是左边第一个比当前数小的数，那么该小数后面的数全都比当前数要大
                // 所以区间 (小数,当前数] 以当前数为最小值
                // 计算以当前数为最小值能构成子序列的min(b)总和作为对答案的贡献
                dp[i] = ((i - l) * a[i]) % mod;

                //
还要加上左边第一个比当前数小的数为最小值能构成的子序列个数对答案的贡献
                // 两者贡献相加就是dp[i]
                if (l != -1)
                    dp[i] = (dp[l] + dp[i]) % mod;

                ans = (ans + dp[i]) % mod;
            }
            return ans;
        }
};
*/
// 单调栈维护左右起点数 计算以当前数为最小值能构成的子序列个数
// 以此计算对答案的贡献（常数大，不如上面的解法高效）
class Solution {
    public:
        const int mod = 1e9 + 7;

        int sumSubarrayMins(vector<int>& a) {
            int n = a.size();

            stack<int>  s;
            vector<int> l(n), r(n);

            // 找到左边第一个比当前数小的数的下标
            for (int i = 0; i < n; i++) {
                while (!s.empty() && a[s.top()] >= a[i]) {
                    s.pop();
                }
                l[i] = i - (s.empty() ? -1 : s.top());
                s.push(i);
            }
            s = stack<int>();
            // 找到右边第一个大于等于当前数的数的下标
            for (int i = n - 1; i >= 0; i--) {
                while (!s.empty() && a[s.top()] > a[i]) {
                    s.pop();
                }

                r[i] = (s.empty() ? n : s.top()) - i;
                s.push(i);
            }

            int ans = 0;
            for (int i = 0; i < n; i++) {
                // l[i]代表以当前数为最小数的区间 起点可选择的数量
                // r[i]代表以当前数为最小数的区间 终点可选择的数量
                // l[i] * r[i] * a[i]即对答案的贡献
                ans = (ans + ((1ll) * l[i] * r[i] * a[i]) % mod) % mod;
            }

            return ans;
        }
};

// @lc code=end
