/*
 * @lc app=leetcode.cn id=993 lang=cpp
 *
 * [993] 二叉树的堂兄弟节点
 *
 * https://leetcode.cn/problems/cousins-in-binary-tree/description/
 *
 * algorithms
 * Easy (55.88%)
 * Likes:    304
 * Dislikes: 0
 * Total Accepted:    66.2K
 * Total Submissions: 118.4K
 * Testcase Example:  '[1,2,3,4]\n4\n3'
 *
 * 在二叉树中，根节点位于深度 0 处，每个深度为 k 的节点的子节点位于深度 k+1 处。
 *
 * 如果二叉树的两个节点深度相同，但 父节点不同 ，则它们是一对堂兄弟节点。
 *
 * 我们给出了具有唯一值的二叉树的根节点 root ，以及树中两个不同节点的值 x 和 y
 * 。
 *
 * 只有与值 x 和 y 对应的节点是堂兄弟节点时，才返回 true 。否则，返回 false。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：root = [1,2,3,4], x = 4, y = 3
 * 输出：false
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：root = [1,2,3,null,4,null,5], x = 5, y = 4
 * 输出：true
 *
 *
 * 示例 3：
 *
 *
 *
 *
 * 输入：root = [1,2,3,null,4], x = 2, y = 3
 * 输出：false
 *
 *
 *
 * 提示：
 *
 *
 * 二叉树的节点数介于 2 到 100 之间。
 * 每个节点的值都是唯一的、范围为 1 到 100 的整数。
 *
 *
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
        bool isCousins(TreeNode* root, int x, int y) {
            unordered_map<int, pair<int, int>> m;

            queue<TreeNode*> q;
            q.emplace(root);
            m[root->val] = {0, -1};

            int deep = 0;

            while (!q.empty()) {
                int t = q.size();
                while (t--) {
                    TreeNode* u = q.front();
                    q.pop();

                    if (u->left) {
                        m[u->left->val] = {deep + 1, u->val};
                        q.emplace(u->left);
                    }
                    if (u->right) {
                        m[u->right->val] = {deep + 1, u->val};
                        q.emplace(u->right);
                    }
                }
                deep++;
            }

            auto [deep_x, parent_x] = m[x];
            auto [deep_y, parent_y] = m[y];
            if (deep_x == deep_y && parent_x != parent_y) {
                return true;
            }
            return false;
        }
};

// @lc code=end
