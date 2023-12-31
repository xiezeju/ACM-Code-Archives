/*
 * @lc app=leetcode.cn id=261 lang=cpp
 *
 * [261] 以图判树
 *
 * https://leetcode.cn/problems/graph-valid-tree/description/
 *
 * algorithms
 * Medium (51.11%)
 * Likes:    230
 * Dislikes: 0
 * Total Accepted:    19K
 * Total Submissions: 37.1K
 * Testcase Example:  '5\n[[0,1],[0,2],[0,3],[1,4]]'
 *
 * 给定编号从 0 到 n - 1 的 n
 * 个结点。给定一个整数 n 和一个 edges 列表，其中 edges[i] = [ai,
 * bi] 表示图中节点 ai 和 bi 之间存在一条无向边。
 *
 * 如果这些边能够形成一个合法有效的树结构，则返回 true ，否则返回 false 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入: n = 5, edges = [[0,1],[0,2],[0,3],[1,4]]
 * 输出: true
 *
 * 示例 2:
 *
 *
 *
 *
 * 输入: n = 5, edges = [[0,1],[1,2],[2,3],[1,3],[1,4]]
 * 输出: false
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 2000
 * 0 <= edges.length <= 5000
 * edges[i].length == 2
 * 0 <= ai, bi < n
 * ai != bi
 * 不存在自循环或重复的边
 *
 *
 */

// @lc code=start

class UnionSet {
    public:
        vector<int> p;

    public:
        UnionSet(int n) {
            p.resize(n);
            iota(p.begin(), p.end(), 0);
        }

        int find(int x) { return p[x] == x ? x : find(p[x]); }

        bool merge(int i, int j) {
            int x = find(i);
            int y = find(j);
            if (x == y) {
                return false;
            }
            p[y] = x;

            return true;
        }
};

class Solution {
    public:
        bool validTree(int n, vector<vector<int>>& edges) {

            if (edges.size() != n - 1) {
                return false;
            }
            UnionSet a(n);
            for (auto& e : edges) {
                if (!a.merge(e[0], e[1])) {
                    return false;
                }
            }
            return true;
        }
};

// @lc code=end
