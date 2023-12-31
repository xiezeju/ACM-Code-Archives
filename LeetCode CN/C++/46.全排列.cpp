/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode.cn/problems/permutations/description/
 *
 * algorithms
 * Medium (78.96%)
 * Likes:    2721
 * Dislikes: 0
 * Total Accepted:    942.9K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,1]
 * 输出：[[0,1],[1,0]]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1]
 * 输出：[[1]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 6
 * -10 <= nums[i] <= 10
 * nums 中的所有整数 互不相同
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool dfs(vector<vector<int>>& a,vector<int>& nums,vector<int>& b,int x,int n,vector<bool>& vis){
        if(x==n){
            a.push_back(b);
            return true;
        }
        
        for(int i=0;i<n;i++){
            if(b[x]==100&&!vis[i]){
                b[x] = nums[i];
                vis[i] = true;
                dfs(a,nums,b,x+1,n,vis);
                b[x] = 100;
                vis[i] = false;
            }
        }

        return false;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> a;
        vector<int> b(n,100);
        vector<bool> vis(n);
        
        dfs(a,nums,b,0,n,vis);
        
        return a;
    }
};
// @lc code=end

