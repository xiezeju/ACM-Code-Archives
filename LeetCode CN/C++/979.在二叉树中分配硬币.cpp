/*
 * @lc app=leetcode.cn id=979 lang=cpp
 *
 * [979] 在二叉树中分配硬币
 *
 * https://leetcode.cn/problems/distribute-coins-in-binary-tree/description/
 *
 * algorithms
 * Medium (76.05%)
 * Likes:    510
 * Dislikes: 0
 * Total Accepted:    29.4K
 * Total Submissions: 38.6K
 * Testcase Example:  '[3,0,0]'
 *
 * 给你一个有 n 个结点的二叉树的根结点 root ，其中树中每个结点 node 都对应有
 * node.val 枚硬币。整棵树上一共有 n 枚硬币。
 *
 * 在一次移动中，我们可以选择两个相邻的结点，然后将一枚硬币从其中一个结点移动到另一个结点。移动可以是从父结点到子结点，或者从子结点移动到父结点。
 *
 * 返回使每个结点上 只有 一枚硬币所需的 最少 移动次数。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [3,0,0]
 * 输出：2
 * 解释：一枚硬币从根结点移动到左子结点，一枚硬币从根结点移动到右子结点。
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [0,3,0]
 * 输出：3
 * 解释：将两枚硬币从根结点的左子结点移动到根结点（两次移动）。然后，将一枚硬币从根结点移动到右子结点。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点的数目为 n
 * 1 <= n <= 100
 * 0 <= Node.val <= n
 * 所有 Node.val 的值之和是 n
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
        int ans = 0;

        // 计算当前节点p的父节点需要从以p为根节点的子树中拿走多少硬币
        int dfs(TreeNode* p) {
            int l = 0, r = 0;
            if (p == nullptr) {
                return 0;
            }

            if (p->left) {
                l = dfs(p->left);
            }

            if (p->right) {
                r = dfs(p->right);
            }

            ans += abs(l) + abs(r);
            return l + r + p->val - 1;
        }

        int distributeCoins(TreeNode* root) {
            dfs(root);

            return ans;
        }
};

// @lc code=end
