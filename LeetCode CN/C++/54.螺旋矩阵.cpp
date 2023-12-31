/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 *
 * https://leetcode.cn/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (49.69%)
 * Likes:    1504
 * Dislikes: 0
 * Total Accepted:    413K
 * Total Submissions: 830.9K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[1,2,3,6,9,8,7,4,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * 输出：[1,2,3,4,8,12,11,10,9,5,6,7]
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
 * -100 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& M) {
        int m = M.size();
        int n = M[0].size();
        vector<int> a;
        a.push_back(M[0][0]);
        M[0][0]=101;
        int cnt = 1;
        int i=0,j=0;
        while(cnt!=n*m){
            while(j+1<n&&M[i][j+1]!=101) a.push_back(M[i][++j]),cnt++,M[i][j]=101;
            while(i+1<m&&M[i+1][j]!=101) a.push_back(M[++i][j]),cnt++,M[i][j]=101;
            while(j-1>=0&&M[i][j-1]!=101) a.push_back(M[i][--j]),cnt++,M[i][j]=101;
            while(i-1>=0&&M[i-1][j]!=101) a.push_back(M[--i][j]),cnt++,M[i][j]=101;
        }
    
        return a;
    }
};
// @lc code=end

