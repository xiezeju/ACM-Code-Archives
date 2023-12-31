/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 *
 * https://leetcode.cn/problems/longest-increasing-path-in-a-matrix/description/
 *
 * algorithms
 * Hard (51.87%)
 * Likes:    797
 * Dislikes: 0
 * Total Accepted:    101.5K
 * Total Submissions: 195.7K
 * Testcase Example:  '[[9,9,4],[6,6,8],[2,1,1]]'
 *
 * 给定一个 m x n 整数矩阵 matrix ，找出其中 最长递增路径 的长度。
 * 
 * 对于每个单元格，你可以往上，下，左，右四个方向移动。 你 不能 在 对角线 方向上移动或移动到 边界外（即不允许环绕）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[9,9,4],[6,6,8],[2,1,1]]
 * 输出：4 
 * 解释：最长递增路径为 [1, 2, 6, 9]。
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [[3,4,5],[3,2,6],[2,2,1]]
 * 输出：4 
 * 解释：最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：matrix = [[1]]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 
 * 0 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int ans = 1;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int dfs(int m,int n,vector<vector<int>>& matrix,int x,int y,vector<vector<int>>& vis){
        if(vis[x][y]!=0){
            return vis[x][y];
        }
        
        vis[x][y]++;

        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<0||nx>=m||ny<0||ny>=n||matrix[nx][ny]<=matrix[x][y]){
                continue;
            }
            vis[x][y] = max(vis[x][y],dfs(m,n,matrix,nx,ny,vis)+1);
            
        }
        
        return vis[x][y];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        if(m==0||n==0) return 0;
        vector<vector<int>> vis(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               ans = max(ans,dfs(m,n,matrix,i,j,vis));
            }
        }
        return ans;
        
    }
};
// @lc code=end

