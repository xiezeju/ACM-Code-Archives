// [LCP 64] 二叉树灯饰
//
// https://leetcode.cn/problems/U7WvvU/description/
//
// 「力扣嘉年华」的中心广场放置了一个巨型的二叉树形状的装饰树。每个节点上均有一盏灯和三个开关。节点值为
// 0 表示灯处于「关闭」状态，节点值为 1
// 表示灯处于「开启」状态。每个节点上的三个开关各自功能如下：
//
// 开关 1：切换当前节点的灯的状态；
// 开关 2：切换 以当前节点为根 的子树中，所有节点上的灯的状态；
// 开关 3：切换 当前节点及其左右子节点（若存在的话） 上的灯的状态；
// 给定该装饰的初始状态
// root，请返回最少需要操作多少次开关，可以关闭所有节点的灯。
//
// 示例 1：
// 输入：root = [1,1,0,null,null,null,1]
// 输出：2
//
// 示例 2：
// 输入：root = [1,1,1,1,null,null,1]
// 输出：1
//
// 示例 3：
// 输入：root = [0,null,0]
// 输出：0
// 解释：无需操作开关，当前所有节点上的灯均已关闭
//
// 提示：
// 1 <= 节点个数 <= 10^5
// 0 <= Node.val <= 1
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    public:
        int Min(int a, int b, int c, int d) {
            return min(a, min(b, min(c, d)));
        }

        vector<int> dfs(TreeNode* p) {
            if (p == nullptr) {
                return {0, 0, 0, 0};
            }
            vector<int> dp(4);

            auto l = dfs(p->left);
            auto r = dfs(p->right);
            int  x = p->val;
            // dp[i]
            // i:0-3分别对应以当前节点为根节点的子树全亮、全灭、仅根亮、仅根灭
            dp[0] = Min(l[0] + r[0] + (x ? 0 : 1), l[1] + r[1] + (x ? 2 : 1),
                        l[2] + r[2] + (x ? 2 : 3), l[3] + r[3] + (x ? 2 : 1));
            dp[1] = Min(l[0] + r[0] + (x ? 1 : 2), l[1] + r[1] + (x ? 1 : 0),
                        l[2] + r[2] + (x ? 1 : 2), l[3] + r[3] + (x ? 3 : 2));
            dp[2] = Min(l[0] + r[0] + (x ? 2 : 1), l[1] + r[1] + (x ? 0 : 1),
                        l[2] + r[2] + (x ? 2 : 1), l[3] + r[3] + (x ? 2 : 3));
            dp[3] = Min(l[0] + r[0] + (x ? 1 : 0), l[1] + r[1] + (x ? 1 : 2),
                        l[2] + r[2] + (x ? 3 : 2), l[3] + r[3] + (x ? 1 : 2));

            return dp;
        }

        int closeLampInTree(TreeNode* root) {
            auto dp = dfs(root);
            return dp[1];
        }
};