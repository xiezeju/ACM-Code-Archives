/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 *
 * https://leetcode.cn/problems/count-complete-tree-nodes/description/
 *
 * algorithms
 * Medium (81.09%)
 * Likes:    1038
 * Dislikes: 0
 * Total Accepted:    323.8K
 * Total Submissions: 399.3K
 * Testcase Example:  '[1,2,3,4,5,6]'
 *
 * 给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。
 * 
 * 完全二叉树
 * 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h
 * 层，则该层包含 1~ 2^h 个节点。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,2,3,4,5,6]
 * 输出：6
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = []
 * 输出：0
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = [1]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点的数目范围是[0, 5 * 10^4]
 * 0 
 * 题目数据保证输入的树是 完全二叉树
 * 
 * 
 * 
 * 
 * 进阶：遍历树来统计节点是一种时间复杂度为 O(n) 的简单解决方案。你可以设计一个更快的算法吗？
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
    bool check(TreeNode* root,int deep,int k){
        int mask = 1 << (deep - 1);        
        TreeNode* p = root;
        while(p&&mask>0){
            if(!(mask&k)){
                p = p->left;
            }
            else{
                p = p->right;
            }
            mask>>=1;
        }
        return p!=nullptr;
    }

    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        int deep=0;
        TreeNode* p = root;
        while(p->left){
            p = p->left;
            deep++;
        }
        int left = 1<<deep , right = (1<<(deep+1))-1;
        while(left<right){
            int mid = (right - left + 1 ) / 2 + left;
            if(check(root,deep,mid)){
                left = mid;
            }
            else{
                right = mid-1;
            }
        }
        return left;
    }
};
// @lc code=end

