/*
 * @lc app=leetcode.cn id=1584 lang=cpp
 *
 * [1584] 连接所有点的最小费用
 *
 * https://leetcode.cn/problems/min-cost-to-connect-all-points/description/
 *
 * algorithms
 * Medium (65.47%)
 * Likes:    299
 * Dislikes: 0
 * Total Accepted:    54.6K
 * Total Submissions: 83.4K
 * Testcase Example:  '[[0,0],[2,2],[3,10],[5,2],[7,0]]'
 *
 * 给你一个points 数组，表示 2D 平面上的一些点，其中 points[i] = [xi, yi] 。
 *
 * 连接点 [xi, yi] 和点 [xj, yj] 的费用为它们之间的 曼哈顿距离 ：|xi - xj| + |yi
 * - yj| ，其中 |val| 表示 val 的绝对值。
 *
 * 请你返回将所有点连接的最小总费用。只有任意两点之间
 * 有且仅有 一条简单路径时，才认为所有点都已连接。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
 * 输出：20
 * 解释：
 *
 * 我们可以按照上图所示连接所有点得到最小总费用，总费用为 20 。
 * 注意到任意两个点之间只有唯一一条路径互相到达。
 *
 *
 * 示例 2：
 *
 *
 * 输入：points = [[3,12],[-2,5],[-4,1]]
 * 输出：18
 *
 *
 * 示例 3：
 *
 *
 * 输入：points = [[0,0],[1,1],[1,0],[-1,1]]
 * 输出：4
 *
 *
 * 示例 4：
 *
 *
 * 输入：points = [[-1000000,-1000000],[1000000,1000000]]
 * 输出：4000000
 *
 *
 * 示例 5：
 *
 *
 * 输入：points = [[0,0]]
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= points.length <= 1000
 * -10^6 <= xi, yi <= 10^6
 * 所有点 (xi, yi) 两两不同。
 *
 *
 */

// @lc code=start
// 堆优化Prim
/*
class Solution {
    public:
        int minCostConnectPoints(vector<vector<int>>& p) {

            int n = p.size();
            int m = n * (n - 1) / 2;

            struct Node {
                    int to, dist;
            };

            vector<vector<Node>> g(n);
            vector<int>          dis(n, 0x3f3f3f3f);
            vector<bool>         vis(n);

            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    int dist = abs(p[i][0] - p[j][0]) + abs(p[i][1] - p[j][1]);
                    g[i].emplace_back(Node{j, dist});
                    g[j].emplace_back(Node{i, dist});
                }
            }

            priority_queue<pair<int, int>, vector<pair<int, int>>,
                           greater<pair<int, int>>>
                q;
            q.push({0, 0});
            dis[0] = 0;

            int ans = 0;

            while (!q.empty()) {
                auto [d, x] = q.top();
                q.pop();
                if (vis[x]) {
                    continue;
                }

                ans += d;
                vis[x] = true;

                for (Node& node : g[x]) {
                    int y = node.to;
                    if (!vis[y] && dis[y] > node.dist) {
                        dis[y] = node.dist;
                        q.push({dis[y], y});
                    }
                }
            }
            return ans;
        }
};
*/

class Solution {
        class edge {
            public:
                int x, y, d;

                bool operator<(const edge& a) const { return d < a.d; }
        };

    public:
        vector<int> p;

        int find(int x) { return p[x] == x ? x : find(p[x]); }

        int minCostConnectPoints(vector<vector<int>>& po) {

            int n = po.size();
            int m = n * (n - 1) / 2;

            p.resize(n);
            iota(p.begin(), p.end(), 0);

            vector<edge> e(m);
            int          idx = 0;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    int sum =
                        abs(po[i][0] - po[j][0]) + abs(po[i][1] - po[j][1]);
                    e[idx++] = {i, j, sum};
                }
            }
            sort(e.begin(), e.end());

            int ans = 0;
            for (int i = 0; i < m; i++) {
                int x = find(e[i].x);
                int y = find(e[i].y);
                if (x == y) {
                    continue;
                }
                p[x] = y;
                ans += e[i].d;
            }

            return ans;
        }
};

// @lc code=end
