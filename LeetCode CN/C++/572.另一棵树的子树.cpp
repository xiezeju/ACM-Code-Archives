/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
 *
 * https://leetcode.cn/problems/subtree-of-another-tree/description/
 *
 * algorithms
 * Easy (47.47%)
 * Likes:    973
 * Dislikes: 0
 * Total Accepted:    185.8K
 * Total Submissions: 391.5K
 * Testcase Example:  '[3,4,5,1,2]\n[4,1,2]'
 *
 * 
 * 
 * 给你两棵二叉树 root 和 subRoot 。检验 root 中是否包含和 subRoot 具有相同结构和节点值的子树。如果存在，返回 true
 * ；否则，返回 false 。
 * 
 * 二叉树 tree 的一棵子树包括 tree 的某个节点和这个节点的所有后代节点。tree 也可以看做它自身的一棵子树。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [3,4,5,1,2], subRoot = [4,1,2]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * root 树上的节点数量范围是 [1, 2000]
 * subRoot 树上的节点数量范围是 [1, 1000]
 * -10^4 
 * -10^4 
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int subRootVal;
    bool find = false;
    void findSubRoot(TreeNode* p,TreeNode* subRoot){
        if(p==nullptr) return;
        if(p->val==subRootVal){
            bool tmp = dfs(p,subRoot);
            if(tmp==true){
               find = true;
            }
        }
        findSubRoot(p->left,subRoot);
        findSubRoot(p->right,subRoot);
    }

    bool dfs(TreeNode* p, TreeNode* q){
        if(p==nullptr&&q==nullptr){
            return true;
        }
        else if(p==nullptr||q==nullptr){
            return false;
        }
        else if(p->val!=q->val){
            return false;
        }
        return dfs(p->left,q->left) && dfs(p->right,q->right);
        
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        subRootVal = subRoot->val;
        findSubRoot(root,subRoot);
        return find;
    }
};
// @lc code=end

