/*
 * @lc app=leetcode.cn id=987 lang=cpp
 *
 * [987] 二叉树的垂序遍历
 *
 * https://leetcode.cn/problems/vertical-order-traversal-of-a-binary-tree/description/
 *
 * algorithms
 * Hard (53.83%)
 * Likes:    249
 * Dislikes: 0
 * Total Accepted:    33.1K
 * Total Submissions: 61.4K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给你二叉树的根结点 root ，请你设计算法计算二叉树的 垂序遍历 序列。
 *
 * 对位于 (row, col) 的每个结点而言，其左右子结点分别位于 (row + 1, col -
 * 1) 和 (row + 1, col + 1) 。树的根结点位于 (0, 0) 。
 *
 * 二叉树的 垂序遍历
 * 从最左边的列开始直到最右边的列结束，按列索引每一列上的所有结点，形成一个按出现位置从上到下排序的有序列表。如果同行同列上有多个结点，则按结点的值从小到大进行排序。
 *
 * 返回二叉树的 垂序遍历 序列。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：[[9],[3,15],[20],[7]]
 * 解释：
 * 列 -1 ：只有结点 9 在此列中。
 * 列  0 ：只有结点 3 和 15 在此列中，按从上到下顺序。
 * 列  1 ：只有结点 20 在此列中。
 * 列  2 ：只有结点 7 在此列中。
 *
 * 示例 2：
 *
 *
 * 输入：root = [1,2,3,4,5,6,7]
 * 输出：[[4],[2],[1,5,6],[3],[7]]
 * 解释：
 * 列 -2 ：只有结点 4 在此列中。
 * 列 -1 ：只有结点 2 在此列中。
 * 列  0 ：结点 1 、5 和 6 都在此列中。
 * ⁠         1 在上面，所以它出现在前面。
 * ⁠         5 和 6 位置都是 (2, 0) ，所以按值从小到大排序，5
 * 在 6 的前面。 列  1 ：只有结点 3 在此列中。 列  2 ：只有结点 7 在此列中。
 *
 *
 * 示例 3：
 *
 *
 * 输入：root = [1,2,3,4,6,5,7]
 * 输出：[[4],[2],[1,5,6],[3],[7]]
 * 解释：
 * 这个示例实际上与示例 2 完全相同，只是结点 5 和 6 在树中的位置发生了交换。
 * 因为 5 和 6 的位置仍然相同，所以答案保持不变，仍然按值从小到大排序。
 *
 *
 *
 * 提示：
 *
 *
 * 树中结点数目总数在范围 [1, 1000] 内
 * 0
 *
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    public:
        vector<vector<int>>   ans;
        map<int, vector<int>> m;

        vector<vector<int>> verticalTraversal(TreeNode* root) {
            if (root == nullptr) {
                return {};
            }
            queue<pair<TreeNode*, int>> q;
            q.emplace(root, 0);
            while (!q.empty()) {
                int t = q.size();
                unordered_map<int,
                              priority_queue<int, vector<int>, greater<int>>>
                    a;
                for (int i = 0; i < t; i++) {
                    auto [u, side] = q.front();
                    q.pop();
                    a[side].emplace(u->val);
                    if (u->left) {
                        q.emplace(u->left, side - 1);
                    }
                    if (u->right) {
                        q.emplace(u->right, side + 1);
                    }
                }
                for (auto [k, v] : a) {
                    while (!v.empty()) {
                        m[k].emplace_back(v.top());
                        v.pop();
                    }
                }
            }

            for (auto [k, v] : m) {
                ans.emplace_back(v);
            }

            return ans;
        }
};

// @lc code=end
