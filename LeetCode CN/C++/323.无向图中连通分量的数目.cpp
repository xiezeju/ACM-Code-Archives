/*
 * @lc app=leetcode.cn id=323 lang=cpp
 *
 * [323] 无向图中连通分量的数目
 *
 * https://leetcode.cn/problems/number-of-connected-components-in-an-undirected-graph/description/
 *
 * algorithms
 * Medium (65.50%)
 * Likes:    182
 * Dislikes: 0
 * Total Accepted:    25.6K
 * Total Submissions: 39K
 * Testcase Example:  '5\n[[0,1],[1,2],[3,4]]'
 *
 * 你有一个包含 n 个节点的图。给定一个整数 n 和一个数组 edges ，其中 edges[i] = [ai, bi] 表示图中 ai 和 bi
 * 之间有一条边。
 * 
 * 返回 图中已连接分量的数目 。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 
 * 
 * 输入: n = 5, edges = [[0, 1], [1, 2], [3, 4]]
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 
 * 
 * 
 * 输入: n = 5, edges = [[0,1], [1,2], [2,3], [3,4]]
 * 输出:  1
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 2000
 * 1 <= edges.length <= 5000
 * edges[i].length == 2
 * 0 <= ai <= bi < n
 * ai != bi
 * edges 中不会出现重复的边
 * 
 * 
 */

// @lc code=start
class Solution {
        class UnionSet {
            public:
                vector<int> p;

                UnionSet(int n) {
                    p.resize(n + 1);
                    iota(p.begin(), p.end(), 0);
                }

                int find(int x) { return p[x] == x ? x : find(p[x]); }

                void merge(int i, int j) {
                    int x = find(i);
                    int y = find(j);
                    if (x == y)
                        return;
                    p[y] = x;
                }
        };

    public:
        int countComponents(int n, vector<vector<int>>& edges) {
            UnionSet a(n);
            for (auto& e : edges) {
                a.merge(e[0], e[1]);
            }
            int ans = 0;
            for (int i = 0; i < n; i++) {
                if (a.find(i) == i)
                    ans++;
            }
            return ans;
        }
};
// @lc code=end

