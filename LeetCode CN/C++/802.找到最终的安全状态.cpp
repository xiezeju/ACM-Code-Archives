/*
 * @lc app=leetcode.cn id=802 lang=cpp
 *
 * [802] 找到最终的安全状态
 *
 * https://leetcode.cn/problems/find-eventual-safe-states/description/
 *
 * algorithms
 * Medium (59.14%)
 * Likes:    419
 * Dislikes: 0
 * Total Accepted:    46.8K
 * Total Submissions: 79.1K
 * Testcase Example:  '[[1,2],[2,3],[5],[0],[5],[],[]]'
 *
 * 有一个有 n 个节点的有向图，节点按 0 到 n - 1 编号。图由一个 索引从 0 开始 的
 * 2D 整数数组 graph表示， graph[i]是与节点 i
 * 相邻的节点的整数数组，这意味着从节点 i 到 graph[i]中的每个节点都有一条边。
 *
 * 如果一个节点没有连出的有向边，则该节点是 终端节点
 * 。如果从该节点开始的所有可能路径都通向 终端节点 ，则该节点为 安全节点 。
 *
 * 返回一个由图中所有 安全节点 组成的数组作为答案。答案数组中的元素应当按 升序
 * 排列。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：graph = [[1,2],[2,3],[5],[0],[5],[],[]]
 * 输出：[2,4,5,6]
 * 解释：示意图如上。
 * 节点 5 和节点 6 是终端节点，因为它们都没有出边。
 * 从节点 2、4、5 和 6 开始的所有路径都指向节点 5 或 6 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
 * 输出：[4]
 * 解释:
 * 只有节点 4 是终端节点，从节点 4 开始的所有路径都通向节点 4 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == graph.length
 * 1 <= n <= 10^4
 * 0 <= graph[i].length <= n
 * 0 <= graph[i][j] <= n - 1
 * graph[i] 按严格递增顺序排列。
 * 图中可能包含自环。
 * 图中边的数目在范围 [1, 4 * 10^4] 内。
 *
 *
 */

// @lc code=start
class Solution {
    public:
        vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
            int n = graph.size();

            vector<vector<int>> g(n);
            vector<int>         Indegee(n);

            for (int i = 0; i < n; i++) {
                for (int x : graph[i]) {
                    g[x].push_back(i);
                }
                Indegee[i] = graph[i].size();
            }

            queue<int> q;

            for (int i = 0; i < n; i++) {
                if (!Indegee[i]) {
                    q.push(i);
                }
            }

            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int x : g[u]) {
                    --Indegee[x];
                    if (!Indegee[x]) {
                        q.push(x);
                    }
                }
            }

            vector<int> ans;
            for (int i = 0; i < n; i++) {
                if (!Indegee[i]) {
                    ans.emplace_back(i);
                }
            }
            return ans;
        }
};

// @lc code=end
