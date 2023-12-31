/*
 * @lc app=leetcode.cn id=743 lang=cpp
 *
 * [743] 网络延迟时间
 *
 * https://leetcode.cn/problems/network-delay-time/description/
 *
 * algorithms
 * Medium (55.79%)
 * Likes:    697
 * Dislikes: 0
 * Total Accepted:    115.9K
 * Total Submissions: 207.8K
 * Testcase Example:  '[[2,1,1],[2,3,1],[3,4,1]]\n4\n2'
 *
 * 有 n 个网络节点，标记为 1 到 n。
 *
 * 给你一个列表 times，表示信号经过 有向 边的传递时间。 times[i] = (ui, vi,
 * wi)，其中 ui 是源节点，vi 是目标节点，
 * wi 是一个信号从源节点传递到目标节点的时间。
 *
 * 现在，从某个节点 K 发出一个信号。需要多久才能使所有节点都收到信号？如果不能使所有节点收到信号，返回 -1
 * 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
 * 输出：2
 *
 *
 * 示例 2：
 *
 *
 * 输入：times = [[1,2,1]], n = 2, k = 1
 * 输出：1
 *
 *
 * 示例 3：
 *
 *
 * 输入：times = [[1,2,1]], n = 2, k = 2
 * 输出：-1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= k <= n <= 100
 * 1 <= times.length <= 6000
 * times[i].length == 3
 * 1 <= ui, vi <= n
 * ui != vi
 * 0 <= wi <= 100
 * 所有 (ui, vi) 对都 互不相同（即，不含重复边）
 *
 *
 */

// @lc code=start

// 朴素Dijkstra
/*
class Solution {
    public:
        int dijkstra(vector<vector<int>>& g, vector<bool>& vis,
                     vector<int>& dis, int k, int n) {
            dis[k] = 0;
            for (int i = 1; i < n; i++) {
                int x = 0;
                for (int y = 1; y <= n; y++) {
                    if (!vis[y] && (x == 0 || dis[y] < dis[x])) {
                        x = y;
                    }
                }
                vis[x] = true;
                for (int y = 1; y <= n; y++) {
                    dis[y] = min(dis[y], dis[x] + g[x][y]);
                }
            }

            int ans = *max_element(dis.begin() + 1, dis.end());
            return ans == INT_MAX / 2 ? -1 : ans;
        }

        int networkDelayTime(vector<vector<int>>& times, int n, int k) {

            vector<vector<int>> g(n + 1, vector<int>(n + 1, INT_MAX / 2));

            vector<bool> vis(n + 1);
            vector<int>  dis(n + 1, INT_MAX / 2);

            // for (int i = 0; i < n; i++) {
            //     g[i][i] = 0;
            // }
            for (int i = 0; i < times.size(); i++) {
                auto e = times[i];
                g[e[0]][e[1]] = e[2];
            }

            return dijkstra(g, vis, dis, k, n);
        }
};
*/

class Solution {
    public:
        int networkDelayTime(vector<vector<int>>& times, int n, int k) {

            struct Node {
                    int id, t;
            };

            vector<vector<Node>> g(n + 1);
            vector<int>          dis(n + 1, 0x3f3f3f3f);

            for (auto& time : times) {
                g[time[0]].emplace_back(Node{time[1], time[2]});
            }

            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
            dis[k] = 0;
            q.push({0, k});

            while (!q.empty()) {
                int u = q.top().second;
                int time = q.top().first;
                q.pop();

                if (dis[u] < time) {
                    continue;
                }

                for (auto& node : g[u]) {
                    int ID = node.id, T = node.t;
                    if (dis[ID] > dis[u] + T) {
                        dis[ID] = dis[u] + T;
                        q.push({dis[ID], ID});
                    }
                }
            }

            int ans = *max_element(dis.begin() + 1, dis.end());
            return ans == 0x3f3f3f3f ? -1 : ans;
        }
};

// @lc code=end
