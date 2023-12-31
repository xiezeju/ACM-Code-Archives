/*
 * @lc app=leetcode.cn id=1483 lang=cpp
 *
 * [1483] 树节点的第 K 个祖先
 *
 * https://leetcode.cn/problems/kth-ancestor-of-a-tree-node/description/
 *
 * algorithms
 * Hard (45.67%)
 * Likes:    212
 * Dislikes: 0
 * Total Accepted:    16.1K
 * Total Submissions: 35.3K
 * Testcase Example:
 '["TreeAncestor","getKthAncestor","getKthAncestor","getKthAncestor"]\n' +
  '[[7,[-1,0,0,1,1,2,2]],[3,1],[5,2],[6,3]]'
 *
 * 给你一棵树，树上有 n 个节点，按从 0 到 n-1
 编号。树以父节点数组的形式给出，其中 parent[i] 是节点 i
 的父节点。树的根节点是编号为
 * 0 的节点。
 *
 * 树节点的第 k 个祖先节点是从该节点到根节点路径上的第 k 个节点。
 *
 * 实现 TreeAncestor 类：
 *
 *
 * TreeAncestor（int n， int[] parent） 对树和父数组中的节点数初始化对象。
 * getKthAncestor(int node, int k) 返回节点 node 的第 k
 个祖先节点。如果不存在这样的祖先节点，返回 -1
 * 。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：
 * ["TreeAncestor","getKthAncestor","getKthAncestor","getKthAncestor"]
 * [[7,[-1,0,0,1,1,2,2]],[3,1],[5,2],[6,3]]
 *
 * 输出：
 * [null,1,0,-1]
 *
 * 解释：
 * TreeAncestor treeAncestor = new TreeAncestor(7, [-1, 0, 0, 1, 1, 2, 2]);
 *
 * treeAncestor.getKthAncestor(3, 1);  // 返回 1 ，它是 3 的父节点
 * treeAncestor.getKthAncestor(5, 2);  // 返回 0 ，它是 5 的祖父节点
 * treeAncestor.getKthAncestor(6, 3);  // 返回 -1 因为不存在满足要求的祖先节点
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= k <= n <= 5 * 10^4
 * parent[0] == -1 表示编号为 0 的节点是根节点。
 * 对于所有的 0 < i < n ，0 <= parent[i] < n 总成立
 * 0 <= node < n
 * 至多查询 5 * 10^4 次
 *
 *
 */

// @lc code=start

// 树上倍增算法
class TreeAncestor {
    public:
        int deep = 16;

        vector<vector<int>> f;

        TreeAncestor(int n, vector<int>& parent) {
            // f[i][j]代表以编号i为起点，跳2^j个单位所到达的节点，f的值全部设置成-1
            f.resize(n, vector<int>(deep, -1));

            // f[i][0]初始化为当前节点i的父节点
            for (int i = 0; i < n; i++) {
                f[i][0] = parent[i];
            }

            for (int j = 1; j < deep; j++) {
                for (int i = 0; i < n; i++) {
                    // 当前节点的上一跳[2^(j-1)个单位]有效，则继续更新
                    if (f[i][j - 1] != -1) {
                        f[i][j] = f[f[i][j - 1]][j - 1];
                    }
                }
            }
        }

        int getKthAncestor(int node, int k) {

            int x = node;
            for (int i = deep - 1; i >= 0; i--) {
                // 逐个检查k的二进制数中的每一位，如果为1，就向上跳2^(i-1)个单位
                if (k & (1 << i)) {
                    x = f[x][i];
                }
                // x为-1说明不能向上跳了，退出循环
                if (x == -1) {
                    break;
                }
            }
            return x;
        }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
// @lc code=end
