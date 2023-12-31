/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
 *
 * https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (57.75%)
 * Likes:    823
 * Dislikes: 0
 * Total Accepted:    325.4K
 * Total Submissions: 563.4K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历 。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：[[3],[20,9],[15,7]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1]
 * 输出：[[1]]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = []
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目在范围 [0, 2000] 内
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> a;
        if(root==nullptr){
          return a;
        }

        queue<TreeNode*> q;
        bool l2r = true;
        q.push(root);
        while(!q.empty()){
            deque<int> b;
            int n = q.size();

            for(int i=0;i<n;i++){
                TreeNode *u = q.front(); q.pop();
                if(!l2r){
                    b.push_front(u->val);                    
                }
                else{
                    b.push_back(u->val);
                }
                if(u->left){
                    q.push(u->left);
                }      
                if(u->right){
                    q.push(u->right);
                }
                        
            }
            a.push_back(vector<int>{b.begin(),b.end()});
           
            l2r^=1;
            
        }
        
        return a;
         
    }
};
// @lc code=end

