
// [LCP 34] 二叉树染色
//
// https://leetcode.cn/problems/er-cha-shu-ran-se-UGC/description/
//
// 小扣有一个根结点为 root
// 的二叉树模型，初始所有结点均为白色，可以用蓝色染料给模型结点染色，模型的每个结点有一个
// val
// 价值。小扣出于美观考虑，希望最后二叉树上每个蓝色相连部分的结点个数不能超过 k
// 个，求所有染成蓝色的结点价值总和最大是多少？
//
// 示例 1：
//
// 输入：root = [5,2,3,4], k = 2
// 输出：12
// 解释：结点 5、3、4 染成蓝色，获得最大的价值 5+3+4=12
//
// 示例 2：
// 输入：root = [4,1,3,9,null,null,2], k = 2
// 输出：16
// 解释：结点 4、3、9 染成蓝色，获得最大的价值 4+3+9=16image.png
//
// 提示：
// 1 <= k <= 10
// 1 <= val <= 10000
// 1 <= 结点数量 <= 10000

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 树形dp
class Solution {
    public:
        vector<int> dfs(TreeNode* p, int k) {
            vector<int> f(k + 1, 0);
            if (p == nullptr) {
                return f;
            }
            auto l = dfs(p->left, k);
            auto r = dfs(p->right, k);
            f[0] = *max_element(l.begin(), l.end()) +
                   *max_element(r.begin(), r.end());

            for (int i = 1; i <= k; i++) {
                for (int j = 0; j < i; j++) {
                    f[i] = max(f[i], p->val + l[j] + r[i - j - 1]);
                }
            }
            return f;
        }

        int maxValue(TreeNode* root, int k) {
            auto f = dfs(root, k);
            return *max_element(f.begin(), f.end());
        }
};