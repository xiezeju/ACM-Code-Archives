/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N 皇后 II
 *
 * https://leetcode.cn/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (82.38%)
 * Likes:    474
 * Dislikes: 0
 * Total Accepted:    130.6K
 * Total Submissions: 158.5K
 * Testcase Example:  '4'
 *
 * n 皇后问题 研究的是如何将 n 个皇后放置在 n × n
 * 的棋盘上，并且使皇后彼此之间不能相互攻击。
 *
 * 给你一个整数 n ，返回 n 皇后问题 不同的解决方案的数量。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 4
 * 输出：2
 * 解释：如上图所示，4 皇后问题存在两个不同的解法。
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 1
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 9
 *
 *
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int ans = 0;

        vector<bool> c, conner1, conner2;

        void dfs(int x, int n) {

            if (x == n) {
                ans++;
                return;
            }

            for (int i = 0; i < n; i++) {
                if (!c[i] && !conner1[x - i + n - 1] && !conner2[x + i]) {
                    c[i] = true;
                    conner1[x - i + n - 1] = true;
                    conner2[x + i] = true;
                    dfs(x + 1, n);
                    c[i] = false;
                    conner1[x - i + n - 1] = false;
                    conner2[x + i] = false;
                }
            }
        }

        int totalNQueens(int n) {

            c.resize(n);
            conner1.resize(2 * n - 1);
            conner2.resize(2 * n - 1);

            dfs(0, n);
            return ans;
        }
};

// @lc code=end
