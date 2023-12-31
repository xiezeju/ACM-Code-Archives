/*
 * @lc app=leetcode.cn id=834 lang=cpp
 *
 * [834] 树中距离之和
 *
 * https://leetcode.cn/problems/sum-of-distances-in-tree/description/
 *
 * algorithms
 * Hard (60.37%)
 * Likes:    481
 * Dislikes: 0
 * Total Accepted:    27.2K
 * Total Submissions: 45.1K
 * Testcase Example:  '6\n[[0,1],[0,2],[2,3],[2,4],[2,5]]'
 *
 * 给定一个无向、连通的树。树中有 n 个标记为 0...n-1 的节点以及 n-1 条边 。
 *
 * 给定整数 n 和数组 edges ， edges[i] = [ai,
 * bi]表示树中的节点 ai 和 bi 之间有一条边。
 *
 * 返回长度为 n 的数组 answer ，其中 answer[i] 是树中第 i
 * 个节点与所有其他节点之间的距离之和。
 *
 *
 *
 * 示例 1:
 *
 *
 *
 *
 * 输入: n = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
 * 输出: [8,12,6,10,10,10]
 * 解释: 树如图所示。
 * 我们可以计算出 dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
 * 也就是 1 + 1 + 2 + 2 + 2 = 8。 因此，answer[0] = 8，以此类推。
 *
 *
 * 示例 2:
 *
 *
 * 输入: n = 1, edges = []
 * 输出: [0]
 *
 *
 * 示例 3:
 *
 *
 * 输入: n = 2, edges = [[1,0]]
 * 输出: [1,1]
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= n <= 3 * 10^4
 * edges.length == n - 1
 * edges[i].length == 2
 * 0 <= ai, bi < n
 * ai != bi
 * 给定的输入保证为有效的树
 *
 *
 */

// @lc code=start
class Solution {
    public:
        vector<int> dp, size;

        void dfs(vector<vector<int>>& g, int x, int fa, int step) {
            dp[0] += step;
            for (auto& y : g[x]) {
                if (y != fa) {
                    dfs(g, y, x, step + 1);
                    size[x] += size[y];
                }
            }
        }

        void changeRoot(vector<vector<int>>& g, int n, int x, int fa) {
            for (auto& y : g[x]) {
                if (y != fa) {
                    dp[y] = dp[x] + n - 2 * size[y];
                    changeRoot(g, n, y, x);
                }
            }
        }

        vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
            if (n == 1) {
                return {0};
            }
            int m = edges.size();

            vector<vector<int>> g(n);
            dp.resize(n);
            size.resize(n, 1);

            for (int i = 0; i < m; i++) {
                int x = edges[i][0];
                int y = edges[i][1];
                g[x].emplace_back(y);
                g[y].emplace_back(x);
            }

            dfs(g, 0, -1, 0);
            changeRoot(g, n, 0, -1);

            return dp;
        }
};

// @lc code=end
