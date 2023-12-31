/*
 * @lc app=leetcode.cn id=1135 lang=cpp
 *
 * [1135] 最低成本联通所有城市
 *
 * https://leetcode.cn/problems/connecting-cities-with-minimum-cost/description/
 *
 * algorithms
 * Medium (58.09%)
 * Likes:    112
 * Dislikes: 0
 * Total Accepted:    13.9K
 * Total Submissions: 23.9K
 * Testcase Example:  '3\n[[1,2,5],[1,3,6],[2,3,1]]'
 *
 * 想象一下你是个城市基建规划者，地图上有 n 座城市，它们按以 1 到 n 的次序编号。
 *
 * 给你整数 n 和一个数组 conections，其中 connections[i] = [xi, yi,
 * costi] 表示将城市 xi 和城市 yi 连接所要的costi（连接是双向的）。
 *
 * 返回连接所有城市的最低成本，每对城市之间至少有一条路径。如果无法连接所有
 * n 个城市，返回 -1
 *
 * 该 最小成本 应该是所用全部连接成本的总和。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：n = 3, conections = [[1,2,5],[1,3,6],[2,3,1]]
 * 输出：6
 * 解释：选出任意 2 条边都可以连接所有城市，我们从中选取成本最小的 2 条。
 *
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入：n = 4, conections = [[1,2,3],[3,4,4]]
 * 输出：-1
 * 解释：即使连通所有的边，也无法连接所有城市。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 10^4
 * 1 <= connections.length <= 10^4
 * connections[i].length == 3
 * 1 <= xi, yi <= n
 * xi != yi
 * 0 <= costi <= 10^5
 *
 *
 */

// @lc code=start

// Kurskal算法
/*
class Solution {
        class edge {
            public:
                int x, y, cost;

                bool operator<(const edge& a) const { return cost < a.cost; }
        };

    public:
        vector<int> p;

        int find(int x) { return p[x] == x ? x : find(p[x]); }

        int minimumCost(int n, vector<vector<int>>& connections) {
            int m = connections.size();
            p.resize(n + 1);
            iota(p.begin(), p.end(), 0);

            vector<edge> e(m + 1);
            for (int i = 1; i <= m; i++) {
                auto c = connections[i - 1];
                e[i] = {c[0], c[1], c[2]};
            }

            sort(e.begin() + 1, e.end());
            int ans = 0;
            int cnt = 0;
            for (int i = 1; i <= m; i++) {
                int x = find(e[i].x);
                int y = find(e[i].y);
                if (x == y) {
                    continue;
                }
                ans += e[i].cost;
                cnt++;
                p[x] = y;
            }

            if (cnt != n - 1) {
                return -1;
            }
            return ans;
        }
};
*/
// 堆优化Prim
class Solution {
    public:
        int minimumCost(int n, vector<vector<int>>& connections) {
            int m = connections.size();

            struct Node {
                    int to, cost;
            };

            vector<int>          dis(n + 1, 0x3f3f3f3f);
            vector<bool>         vis(n + 1);
            vector<vector<Node>> g(n + 1);

            for (int i = 0; i < m; i++) {
                auto e = connections[i];
                g[e[0]].emplace_back(Node{e[1], e[2]});
                g[e[1]].emplace_back(Node{e[0], e[2]});
            }

            int ans = 0;
            int cnt = 0;

            typedef pair<int, int> ii;

            priority_queue<ii, vector<ii>, greater<ii>> q;
            q.push({0, 1});
            dis[1] = 0;

            while (!q.empty()) {
                auto [cost, x] = q.top();
                q.pop();
                if (vis[x]) {
                    continue;
                }
                vis[x] = true;
                cnt++;
                ans += cost;
                for (Node& node : g[x]) {
                    int y = node.to;
                    if (!vis[y] && dis[y] > node.cost) {
                        dis[y] = node.cost;
                        q.push({dis[y], y});
                    }
                }
            }

            if (cnt != n) {
                return -1;
            }
            return ans;
        }
};

// @lc code=end
