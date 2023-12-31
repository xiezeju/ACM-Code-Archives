/*
 * @lc app=leetcode.cn id=1129 lang=cpp
 *
 * [1129] 颜色交替的最短路径
 *
 * https://leetcode.cn/problems/shortest-path-with-alternating-colors/description/
 *
 * algorithms
 * Medium (48.39%)
 * Likes:    290
 * Dislikes: 0
 * Total Accepted:    29.6K
 * Total Submissions: 61.3K
 * Testcase Example:  '3\n[[0,1],[1,2]]\n[]'
 *
 * 给定一个整数 n，即有向图中的节点数，其中节点标记为 0 到 n -
 * 1。图中的每条边为红色或者蓝色，并且可能存在自环或平行边。
 *
 * 给定两个数组 redEdges 和 blueEdges，其中：
 *
 *
 * redEdges[i] = [ai, bi] 表示图中存在一条从节点 ai 到节点 bi 的红色有向边，
 * blueEdges[j] = [uj, vj] 表示图中存在一条从节点 uj 到节点 vj 的蓝色有向边。
 *
 *
 * 返回长度为 n 的数组 answer，其中 answer[X] 是从节点 0 到节点 X
 * 的红色边和蓝色边交替出现的最短路径的长度。如果不存在这样的路径，那么
 * answer[x] = -1。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 3, red_edges = [[0,1],[1,2]], blue_edges = []
 * 输出：[0,1,-1]
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 3, red_edges = [[0,1]], blue_edges = [[2,1]]
 * 输出：[0,1,-1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 100
 * 0 <= redEdges.length, blueEdges.length <= 400
 * redEdges[i].length == blueEdges[j].length == 2
 * 0 <= ai, bi, uj, vj < n
 *
 *
 */

// @lc code=start
class Solution {
    public:
        vector<int> shortestAlternatingPaths(int                  n,
                                             vector<vector<int>>& redEdges,
                                             vector<vector<int>>& blueEdges) {

            struct Node {
                    int next;
                    int color;
            };

            vector<vector<Node>> g(n);

            for (int i = 0; i < redEdges.size(); i++) {
                auto red = redEdges[i];
                g[red[0]].emplace_back(Node{red[1], 0});
            }
            for (int i = 0; i < blueEdges.size(); i++) {
                auto blue = blueEdges[i];
                g[blue[0]].emplace_back(Node{blue[1], 1});
            }

            queue<Node> q;

            vector<int> a(n, INT_MAX);

            // 本题核心，要标记不同的颜色是否走过，以避免一直在相同环路内循环
            vector<vector<bool>> vis(2, vector<bool>(n));
            a[0] = 0;
            vis[0][0] = vis[1][0] = true;

            for (int i = 0; i < g[0].size(); i++) {
                Node u = g[0][i];
                vis[u.color][u.next] = true;
                a[u.next] = min(a[u.next], 1);
                q.push(u);
            }

            int step = 2;

            while (!q.empty()) {
                int t = q.size();
                while (t--) {
                    Node u = q.front();
                    q.pop();
                    for (Node& node : g[u.next]) {
                        if (node.color == (u.color ^ 1) &&
                            !vis[node.color][node.next]) {

                            vis[node.color][node.next] = true;
                            a[node.next] = min(a[node.next], step);

                            q.push(node);
                        }
                    }
                }
                step++;
            }
            for (int& i : a) {
                if (i == INT_MAX) {
                    i = -1;
                }
            }

            return a;
        }
};

// @lc code=end
