/*
 * @lc app=leetcode.cn id=265 lang=cpp
 *
 * [265] 粉刷房子 II
 *
 * https://leetcode.cn/problems/paint-house-ii/description/
 *
 * algorithms
 * Hard (63.84%)
 * Likes:    155
 * Dislikes: 0
 * Total Accepted:    14.7K
 * Total Submissions: 23K
 * Testcase Example:  '[[1,5,3],[2,9,4]]'
 *
 * 假如有一排房子共有 n 幢，每个房子可以被粉刷成 k
 * 种颜色中的一种。房子粉刷成不同颜色的花费成本也是不同的。你需要粉刷所有的房子并且使其相邻的两个房子颜色不能相同。
 *
 * 每个房子粉刷成不同颜色的花费以一个 n x k 的矩阵表示。
 *
 *
 * 例如，costs[0][0] 表示第 0 幢房子粉刷成 0 号颜色的成本；costs[1][2] 表示第 1
 * 幢房子粉刷成 2 号颜色的成本，以此类推。
 *
 *
 * 返回 粉刷完所有房子的最低成本 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入: costs = [[1,5,3],[2,9,4]]
 * 输出: 5
 * 解释:
 * 将房子 0 刷成 0 号颜色，房子 1 刷成 2 号颜色。花费: 1 + 4 = 5;
 * 或者将 房子 0 刷成 2 号颜色，房子 1 刷成 0 号颜色。花费: 3 + 2 = 5.
 *
 * 示例 2:
 *
 *
 * 输入: costs = [[1,3],[2,4]]
 * 输出: 5
 *
 *
 *
 *
 * 提示：
 *
 *
 * costs.length == n
 * costs[i].length == k
 * 1 <= n <= 100
 * 2 <= k <= 20
 * 1 <= costs[i][j] <= 20
 *
 *
 *
 *
 * 进阶：您能否在 O(nk) 的时间复杂度下解决此问题？
 *
 */

// @lc code=start
// O(n^2 k)解法
/*
class Solution {
    public:
        int minCostII(vector<vector<int>>& costs) {
            int n = costs.size();
            int k = costs[0].size();

            vector<vector<int>> dp(n, vector<int>(k));

            for (int i = 0; i < k; i++) {
                dp[0][i] = costs[0][i];
            }

            for (int i = 1; i < n; i++) {
                for (int j = 0; j < k; j++) {
                    int tmp = INT_MAX;
                    for (int p = 0; p < k; p++) {
                        if (p == j)
                            continue;
                        tmp = min(tmp, dp[i - 1][p]);
                    }
                    dp[i][j] = costs[i][j] + tmp;
                }
            }

            return *min_element(dp[n - 1].begin(), dp[n - 1].end());
        }
};
*/
// O(nk)解法
class Solution {
    public:
        int minCostII(vector<vector<int>>& costs) {
            int n = costs.size();
            int k = costs[0].size();

            vector<vector<int>> dp(n, vector<int>(k));

            for (int i = 0; i < k; i++) {
                dp[0][i] = costs[0][i];
            }

            for (int i = 1; i < n; i++) {

                // 寻找上一行的最小值和次最小值
                int mins = 0, second_mins = 1;
                for (int j = 1; j < k; j++) {
                    if (dp[i - 1][j] < dp[i - 1][mins]) {
                        second_mins = mins;
                        mins = j;
                    } else if (dp[i - 1][j] < dp[i - 1][second_mins]) {
                        second_mins = j;
                    }
                }

                for (int j = 0; j < k; j++) {
                    dp[i][j] = costs[i][j] + (j == mins ? dp[i - 1][second_mins]
                                                        : dp[i - 1][mins]);
                }
            }

            return *min_element(dp[n - 1].begin(), dp[n - 1].end());
        }
};

// @lc code=end
