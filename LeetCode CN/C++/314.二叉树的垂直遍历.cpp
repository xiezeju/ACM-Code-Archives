/*
 * @lc app=leetcode.cn id=314 lang=cpp
 *
 * [314] 二叉树的垂直遍历
 *
 * https://leetcode.cn/problems/binary-tree-vertical-order-traversal/description/
 *
 * algorithms
 * Medium (56.05%)
 * Likes:    215
 * Dislikes: 0
 * Total Accepted:    11.5K
 * Total Submissions: 20.4K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给你一个二叉树的根结点，返回其结点按 垂直方向（从上到下，逐列）遍历的结果。
 *
 * 如果两个结点在同一行和列，那么顺序则为 从左到右。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：[[9],[3,15],[20],[7]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [3,9,8,4,0,1,7]
 * 输出：[[4],[9],[3,0,1],[8],[7]]
 *
 *
 * 示例 3：
 *
 *
 * 输入：root = [3,9,8,4,0,1,7,null,null,null,2,5]
 * 输出：[[4],[9,5],[3,0,1],[8,2],[7]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中结点的数目在范围 [0, 100] 内
 * -100 <= Node.val <= 100
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
        vector<vector<int>>   a;
        map<int, vector<int>> m;

        vector<vector<int>> verticalOrder(TreeNode* root) {
            if (root == nullptr) {
                return {};
            }

            queue<pair<TreeNode*, int>> q;
            q.emplace(root, 0);
            while (!q.empty()) {
                int t = q.size();
                while (t--) {
                    auto [u, side] = q.front();
                    q.pop();
                    m[side].emplace_back(u->val);
                    if (u->left) {
                        q.emplace(u->left, side - 1);
                    }
                    if (u->right) {
                        q.emplace(u->right, side + 1);
                    }
                }
            }

            for (auto [k, v] : m) {
                a.emplace_back(v);
            }

            return a;
        }
};

// @lc code=end
