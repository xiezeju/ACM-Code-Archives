/*
 * @lc app=leetcode.cn id=1192 lang=cpp
 *
 * [1192] 查找集群内的关键连接
 *
 * https://leetcode.cn/problems/critical-connections-in-a-network/description/
 *
 * algorithms
 * Hard (55.22%)
 * Likes:    252
 * Dislikes: 0
 * Total Accepted:    9.1K
 * Total Submissions: 16.4K
 * Testcase Example:  '4\n[[0,1],[1,2],[2,0],[1,3]]'
 *
 * 力扣数据中心有 n 台服务器，分别按从 0 到 n-1 的方式进行了编号。它们之间以
 * 服务器到服务器 的形式相互连接组成了一个内部集群，连接是无向的。用
 *  connections 表示集群网络，connections[i] = [a, b] 表示服务器 a 和
 * b 之间形成连接。任何服务器都可以直接或者间接地通过网络到达任何其他服务器。
 *
 * 关键连接
 * 是在该集群中的重要连接，假如我们将它移除，便会导致某些服务器无法访问其他服务器。
 *
 * 请你以任意顺序返回该集群内的所有 关键连接 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
 * 输出：[[1,3]]
 * 解释：[[3,1]] 也是正确的。
 *
 * 示例 2:
 *
 *
 * 输入：n = 2, connections = [[0,1]]
 * 输出：[[0,1]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= n <= 10^5
 * n - 1 <= connections.length <= 10^5
 * 0 <= ai, bi <= n - 1
 * ai != bi
 * 不存在重复的连接
 *
 *
 */

// @lc code=start
class Solution {
    public:
        // 代表访问节点的时间
        int num = 0;

        // dfn记录访问时间，low为追溯值
        vector<int>         dfn, low;
        vector<vector<int>> g, ans;

        // u代表当前节点，f代表上一个节点
        void Tarjan(int u, int f) {
            // 访问新的节点时先记录一下dfn和low
            dfn[u] = low[u] = ++num;
            for (int& x : g[u]) {
                // 要往后走，刚从f过来，别着急回去
                if (x == f)
                    continue;
                if (!dfn[x]) {
                    // 下个点没有被访问过就一直往后面走
                    Tarjan(x, u);
                    // 开始返回，逆向更新追溯值
                    low[u] = min(low[u], low[x]);
                    // 如果在同一个强连通分量里面，返回时追溯值应该都是一样的，如果出现桥的话这个点的访问时间要早于强连通分量里面的追溯值
                    if (dfn[u] < low[x]) {
                        ans.emplace_back(vector<int>{u, x});
                    }
                } else {
                    // 发现能走到之前访问过的点，更新追溯值
                    low[u] = min(low[u], dfn[x]);
                }
            }
        }

        vector<vector<int>>
        criticalConnections(int n, vector<vector<int>>& connections) {
            dfn.resize(n);
            low.resize(n);
            g.resize(n);
            for (auto& e : connections) {
                g[e[0]].emplace_back(e[1]);
                g[e[1]].emplace_back(e[0]);
            }

            for (int u = 0; u < n; u++) {
                // 当前节点没访问过就去访问一下
                if (!dfn[u])
                    Tarjan(u, -1);
            }
            return ans;
        }
};

// @lc code=end
