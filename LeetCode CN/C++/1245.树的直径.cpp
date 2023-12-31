/*
 * @lc app=leetcode.cn id=1245 lang=cpp
 *
 * [1245] 树的直径
 *
 * https://leetcode.cn/problems/tree-diameter/description/
 *
 * algorithms
 * Medium (54.66%)
 * Likes:    110
 * Dislikes: 0
 * Total Accepted:    6.6K
 * Total Submissions: 12K
 * Testcase Example:  '[[0,1],[0,2]]'
 *
 * 给你这棵「无向树」，请你测算并返回它的「直径」：这棵树上最长简单路径的 边数。
 *
 * 我们用一个由所有「边」组成的数组 edges 来表示一棵无向树，其中 edges[i] = [u,
 * v] 表示节点 u 和 v 之间的双向边。
 *
 * 树上的节点都已经用 {0, 1, ...,
 * edges.length} 中的数做了标记，每个节点上的标记都是独一无二的。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：edges = [[0,1],[0,2]]
 * 输出：2
 * 解释：
 * 这棵树上最长的路径是 1 - 0 - 2，边数为 2。
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：edges = [[0,1],[1,2],[2,3],[1,4],[4,5]]
 * 输出：4
 * 解释：
 * 这棵树上最长的路径是 3 - 2 - 1 - 4 - 5，边数为 4。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= edges.length < 10^4
 * edges[i][0] != edges[i][1]
 * 0 <= edges[i][j] <= edges.length
 * edges 会形成一棵无向树
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int         ans = 0;
        vector<int> d1, d2;

        void dfs(vector<vector<int>>& g, int x, int fa) {

            for (auto& y : g[x]) {
                if (y == fa)
                    continue;

                dfs(g, y, x);

                int d = 1 + d1[y];

                if (d1[x] < d) {
                    d2[x] = d1[x];
                    d1[x] = d;
                } else if (d2[x] < d) {
                    d2[x] = d;
                }
            }
        }

        int treeDiameter(vector<vector<int>>& edges) {
            int                 n = edges.size();
            vector<vector<int>> g(n + 1);

            d1.resize(n + 1);
            d2.resize(n + 1);

            for (auto& e : edges) {
                g[e[0]].emplace_back(e[1]);
                g[e[1]].emplace_back(e[0]);
            }

            dfs(g, 0, -1);

            for (int i = 0; i <= n; i++) {
                ans = max(ans, d1[i] + d2[i]);
            }

            return ans;
        }
};

// @lc code=end
