/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
 *
 * https://leetcode.cn/problems/binary-tree-cameras/description/
 *
 * algorithms
 * Hard (52.33%)
 * Likes:    673
 * Dislikes: 0
 * Total Accepted:    68.1K
 * Total Submissions: 130.1K
 * Testcase Example:  '[0,0,null,0,0]'
 *
 * 给定一个二叉树，我们在树的节点上安装摄像头。
 *
 * 节点上的每个摄影头都可以监视其父对象、自身及其直接子对象。
 *
 * 计算监控树的所有节点所需的最小摄像头数量。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：[0,0,null,0,0]
 * 输出：1
 * 解释：如图所示，一台摄像头足以监控所有节点。
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：[0,0,null,0,null,0,null,null,0]
 * 输出：2
 * 解释：需要至少两个摄像头来监视树的所有节点。
 * 上图显示了摄像头放置的有效位置之一。
 *
 *
 *
 * 提示：
 *
 *
 * 给定树的节点数的范围是 [1, 1000]。
 * 每个节点的值都是 0。
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
        const int inf = 0x3f3f3f3f;

        tuple<int, int, int> dfs(TreeNode* p) {
            if (p == nullptr) {
                return {inf, 0, 0};
            }
            // a代表该节点装摄像头，b代表该节点不装摄像头但是让父节点装，c代表该节点不装摄像头但是让子节点装
            auto [al, bl, cl] = dfs(p->left);
            auto [ar, br, cr] = dfs(p->right);

            return {min(al, min(bl, cl)) + min(ar, min(br, cr)) + 1,
                    min(al, cl) + min(ar, cr),
                    min(al + cr, min(ar + cl, al + ar))};
        }

        int minCameraCover(TreeNode* root) {
            auto [a, b, c] = dfs(root);

            return min(a, c);
        }
};

// @lc code=end
