/*
 * @lc app=leetcode.cn id=655 lang=cpp
 *
 * [655] 输出二叉树
 *
 * https://leetcode.cn/problems/print-binary-tree/description/
 *
 * algorithms
 * Medium (69.69%)
 * Likes:    214
 * Dislikes: 0
 * Total Accepted:    36.5K
 * Total Submissions: 52.4K
 * Testcase Example:  '[1,2]'
 *
 * 给你一棵二叉树的根节点 root ，请你构造一个下标从 0 开始、大小为 m x n 的字符串矩阵 res ，用以表示树的 格式化布局
 * 。构造此格式化布局矩阵需要遵循以下规则：
 * 
 * 
 * 树的 高度 为 height ，矩阵的行数 m 应该等于 height + 1 。
 * 矩阵的列数 n 应该等于 2^height+1 - 1 。
 * 根节点 需要放置在 顶行 的 正中间 ，对应位置为 res[0][(n-1)/2] 。
 * 对于放置在矩阵中的每个节点，设对应位置为 res[r][c] ，将其左子节点放置在 res[r+1][c-2^height-r-1] ，右子节点放置在
 * res[r+1][c+2^height-r-1] 。
 * 继续这一过程，直到树中的所有节点都妥善放置。
 * 任意空单元格都应该包含空字符串 "" 。
 * 
 * 
 * 返回构造得到的矩阵 res 。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,2]
 * 输出：
 * [["","1",""],
 * ["2","",""]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1,2,3,null,4]
 * 输出：
 * [["","","","1","","",""],
 * ["","2","","","","3",""],
 * ["","","4","","","",""]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数在范围 [1, 2^10] 内
 * -99 <= Node.val <= 99
 * 树的深度在范围 [1, 10] 内
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
    int height = 0;
    bool put = false;
    void dfs(TreeNode* p,int deep,vector<vector<string>>& a,int x,int y){
        if(p==nullptr){
            return;
        }
        if(put==false){
            height = max(height,deep);
        }
        if(put==true){
            a[x][y] = to_string(p->val);
        }
        dfs(p->left,deep+1,a,x+1,y-(1<<max(0,height-x-1)));
        dfs(p->right,deep+1,a,x+1,y+(1<<max(0,height-x-1)));
    }

    vector<vector<string>> printTree(TreeNode* root) {
        vector<vector<string>> a;
        dfs(root,0,a,0,0);
        int m = height+1;
        int n = (1<<(height+1)) - 1;
        put = true;
        a.resize(m,vector<string>(n));
        dfs(root,0,a,0,(n-1)/2);
        return a;        
    }
};
// @lc code=end

