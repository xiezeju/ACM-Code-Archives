/*
 * @lc app=leetcode.cn id=1857 lang=cpp
 *
 * [1857] 有向图中最大颜色值
 *
 * https://leetcode.cn/problems/largest-color-value-in-a-directed-graph/description/
 *
 * algorithms
 * Hard (49.13%)
 * Likes:    50
 * Dislikes: 0
 * Total Accepted:    4.7K
 * Total Submissions: 9.5K
 * Testcase Example:  '"abaca"\n[[0,1],[0,2],[2,3],[3,4]]'
 *
 * 给你一个 有向图 ，它含有 n 个节点和 m 条边。节点编号从 0 到 n - 1 。
 *
 * 给你一个字符串 colors ，其中 colors[i] 是小写英文字母，表示图中第 i 个节点的
 * 颜色 （下标从 0 开始）。同时给你一个二维数组 edges ，其中 edges[j] = [aj,
 * bj] 表示从节点 aj 到节点 bj 有一条 有向边 。
 *
 * 图中一条有效 路径 是一个点序列 x1 -> x2 -> x3 -> ... -> xk ，对于所有 1 <= i
 * < k ，从 xi 到 xi+1 在图中有一条有向边。路径的 颜色值 是路径中 出现次数最多
 * 颜色的节点数目。
 *
 * 请你返回给定图中有效路径里面的 最大颜色值 。如果图中含有环，请返回 -1 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
 * 输出：3
 * 解释：路径 0 -> 2 -> 3 -> 4 含有 3 个颜色为 "a" 的节点（上图中的红色节点）。
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：colors = "a", edges = [[0,0]]
 * 输出：-1
 * 解释：从 0 到 0 有一个环。
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == colors.length
 * m == edges.length
 * 1 <= n <= 10^5
 * 0 <= m <= 10^5
 * colors 只含有小写英文字母。
 * 0 <= aj, bj < n
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int largestPathValue(string colors, vector<vector<int>>& edges) {
            int                 n = colors.size();
            vector<vector<int>> g(n), f(n, vector<int>(26));
            vector<int>         indegree(n);

            for (auto& e : edges) {
                g[e[0]].emplace_back(e[1]);
                indegree[e[1]]++;
            }

            queue<int> q;

            for (int i = 0; i < n; i++) {
                if (!indegree[i]) {
                    q.push(i);
                }
            }

            int cnt = 0;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                cnt++;

                f[u][colors[u] - 'a']++;
                for (int& x : g[u]) {
                    indegree[x]--;
                    for (int c = 0; c < 26; c++) {
                        f[x][c] = max(f[x][c], f[u][c]);
                    }
                    if (!indegree[x]) {
                        q.push(x);
                    }
                }
            }

            if (cnt != n) {
                return -1;
            }

            int ans = 0;
            for (int i = 0; i < n; i++) {
                for (int c = 0; c < 26; c++) {
                    ans = max(ans, f[i][c]);
                }
            }
            return ans;
        }
};

// @lc code=end
