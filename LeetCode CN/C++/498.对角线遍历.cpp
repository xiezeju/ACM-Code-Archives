/*
 * @lc app=leetcode.cn id=498 lang=cpp
 *
 * [498] 对角线遍历
 *
 * https://leetcode.cn/problems/diagonal-traverse/description/
 *
 * algorithms
 * Medium (55.86%)
 * Likes:    466
 * Dislikes: 0
 * Total Accepted:    114.8K
 * Total Submissions: 205.5K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给你一个大小为 m x n 的矩阵 mat ，请以对角线遍历的顺序，用一个数组返回这个矩阵中的所有元素。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：mat = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[1,2,4,7,5,3,6,8,9]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：mat = [[1,2],[3,4]]
 * 输出：[1,2,3,4]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 10^4
 * 1 <= m * n <= 10^4
 * -10^5 <= mat[i][j] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> a;
        a.push_back(mat[0][0]);
        int cnt=1;
        int i=0,j=0;
        while(cnt<n*m){
            //向右上方走的时候，走到尽头优先往右走，右边没路再往下走
            while(i-1>=0&&j+1<n) a.push_back(mat[--i][++j]),++cnt;
            if(j+1<n) a.push_back(mat[i][++j]),++cnt;
            else if(i+1<m) a.push_back(mat[++i][j]),++cnt;

            //往左方走的时候，走到尽头优先往下走，下边没路再往右走
            while(i+1<m&&j-1>=0) a.push_back(mat[++i][--j]),++cnt;
            if(i+1<m) a.push_back(mat[++i][j]),++cnt;
            else if(j+1<n) a.push_back(mat[i][++j]),++cnt;
            
        }
        return a;
    }
};
// @lc code=end

