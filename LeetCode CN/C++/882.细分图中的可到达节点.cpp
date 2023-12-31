/*
 * @lc app=leetcode.cn id=882 lang=cpp
 *
 * [882] 细分图中的可到达节点
 *
 * https://leetcode.cn/problems/reachable-nodes-in-subdivided-graph/description/
 *
 * algorithms
 * Hard (63.80%)
 * Likes:    159
 * Dislikes: 0
 * Total Accepted:    15.9K
 * Total Submissions: 25K
 * Testcase Example:  '[[0,1,10],[0,2,1],[1,2,2]]\n6\n3'
 *
 * 给你一个无向图（原始图），图中有 n 个节点，编号从 0 到 n - 1
 * 。你决定将图中的每条边 细分 为一条节点链，每条边之间的新节点数各不相同。
 *
 * 图用由边组成的二维数组 edges 表示，其中 edges[i] = [ui, vi, cnti]
 * 表示原始图中节点 ui 和 vi 之间存在一条边，cnti 是将边 细分
 * 后的新节点总数。注意，cnti == 0 表示边不可细分。
 *
 * 要 细分 边 [ui, vi] ，需要将其替换为 (cnti + 1) 条新边，和 cnti
 * 个新节点。新节点为 x1, x2, ..., xcnti ，新边为 [ui, x1], [x1, x2], [x2, x3],
 * ..., [xcnti-1, xcnti], [xcnti, vi] 。
 *
 * 现在得到一个 新的细分图 ，请你计算从节点 0
 * 出发，可以到达多少个节点？如果节点间距离是 maxMoves 或更少，则视为 可以到达
 * 。
 *
 * 给你原始图和 maxMoves ，返回 新的细分图中从节点 0 出发 可到达的节点数 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：edges = [[0,1,10],[0,2,1],[1,2,2]], maxMoves = 6, n = 3
 * 输出：13
 * 解释：边的细分情况如上图所示。
 * 可以到达的节点已经用黄色标注出来。
 *
 *
 * 示例 2：
 *
 *
 * 输入：edges = [[0,1,4],[1,2,6],[0,2,8],[1,3,1]], maxMoves = 10, n = 4
 * 输出：23
 *
 *
 * 示例 3：
 *
 *
 * 输入：edges = [[1,2,4],[1,4,5],[1,3,1],[2,3,4],[3,4,5]], maxMoves = 17, n = 5
 * 输出：1
 * 解释：节点 0 与图的其余部分没有连通，所以只有节点 0 可以到达。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= edges.length <= min(n * (n - 1) / 2, 10^4)
 * edges[i].length == 3
 * 0 <= ui < vi < n
 * 图中 不存在平行边
 * 0 <= cnti <= 10^4
 * 0 <= maxMoves <= 10^9
 * 1 <= n <= 3000
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {

            struct Node {
                    int to, d;
            };

            vector<vector<Node>> g(n);
            for (auto& e : edges) {
                g[e[0]].emplace_back(Node{e[1], e[2] + 1});
                g[e[1]].emplace_back(Node{e[0], e[2] + 1});
            }

            vector<int> dis(n, 0x3f3f3f3f);
            dis[0] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>,
                           greater<pair<int, int>>>
                q;
            q.push({0, 0});
            while (!q.empty()) {
                auto [d, x] = q.top();
                q.pop();
                if (dis[x] < d || d > maxMoves) {
                    continue;
                }

                dis[x] = d;

                for (auto& e : g[x]) {
                    int y = e.to;
                    if (dis[y] > dis[x] + e.d) {
                        dis[y] = dis[x] + e.d;
                        q.push({dis[y], y});
                    }
                }
            }
            int ans = 0;
            // 先统计能直接到达的端点的总数
            for (int i = 0; i < n; i++) {
                if (dis[i] <= maxMoves) {
                    ans++;
                }
            }

            // 再统计能到达的细分点的总数
            for (auto& e : edges) {
                // 分别统计从左端点出发可达细分点的数量和从右端点出发可达细分点的数量
                int left = max(0, maxMoves - dis[e[0]]);
                int right = max(0, maxMoves - dis[e[1]]);
                // left和right可能会有重合，最多不能超过当前左右端点间细分点的数量
                ans += min(e[2], left + right);
            }

            return ans;
        }
};

// @lc code=end
