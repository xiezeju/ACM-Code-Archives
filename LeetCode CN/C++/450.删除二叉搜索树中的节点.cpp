/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
 *
 * https://leetcode.cn/problems/delete-node-in-a-bst/description/
 *
 * algorithms
 * Medium (52.36%)
 * Likes:    1262
 * Dislikes: 0
 * Total Accepted:    232.1K
 * Total Submissions: 443.5K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n3'
 *
 * 给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key
 * 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。
 *
 * 一般来说，删除节点可分为两个步骤：
 *
 *
 * 首先找到需要删除的节点；
 * 如果找到了，删除它。
 *
 *
 *
 *
 * 示例 1:
 *
 *
 *
 *
 * 输入：root = [5,3,6,2,4,null,7], key = 3
 * 输出：[5,4,6,2,null,null,7]
 * 解释：给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。
 * 一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。
 * 另一个正确答案是 [5,2,6,null,4,null,7]。
 *
 *
 *
 *
 * 示例 2:
 *
 *
 * 输入: root = [5,3,6,2,4,null,7], key = 0
 * 输出: [5,3,6,2,4,null,7]
 * 解释: 二叉树不包含值为 0 的节点
 *
 *
 * 示例 3:
 *
 *
 * 输入: root = [], key = 0
 * 输出: []
 *
 *
 *
 * 提示:
 *
 *
 * 节点数的范围 [0, 10^4].
 * -10^5 <= Node.val <= 10^5
 * 节点值唯一
 * root 是合法的二叉搜索树
 * -10^5 <= key <= 10^5
 *
 *
 *
 *
 * 进阶： 要求算法时间复杂度为 O(h)，h 为树的高度。
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
        void insert(TreeNode* parent, TreeNode* t, int key) {
            if (key < parent->val)
                parent->left = t;
            else if (key > parent->val)
                parent->right = t;
        }

        void dfs(TreeNode* parent, TreeNode* cur, int key) {
            if (cur == nullptr) {
                return;
            }
            if (key == cur->val) {
                if (!cur->left || !cur->right) {
                    // 只有左孩子
                    if (cur->left) {
                        insert(parent, cur->left, key);
                    } else if (cur->right) { // 只有右孩子
                        insert(parent, cur->right, key);
                    } else { // 无左右孩子
                        insert(parent, nullptr, key);
                    }
                } else {
                    // 左右节点都不为空时，找到右子树的最左节点，将值交换，同时最左节点的父节点的left指向最左节点的右节点（如果有）
                    TreeNode* search_parent = cur;
                    TreeNode* search_left = cur->right;
                    while (search_left->left) {
                        search_parent = search_left;
                        search_left = search_left->left;
                    }

                    int tmp = search_left->val;
                    insert(search_parent, search_left->right, search_left->val);

                    cur->val = tmp;
                }
            }
            if (key < cur->val) {
                dfs(cur, cur->left, key);
            }
            if (key > cur->val) {
                dfs(cur, cur->right, key);
            }
        }

        TreeNode* deleteNode(TreeNode* root, int key) {
            if (root == nullptr) {
                return nullptr;
            }
            if (root->val == key) {
                if (!root->left && !root->right) {
                    return nullptr;
                } else if (!root->left) {
                    return root->right;
                } else if (!root->right) {
                    return root->left;
                }
            }
            dfs(nullptr, root, key);
            return root;
        }
};

// @lc code=end
