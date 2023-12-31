/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 *
 * https://leetcode.cn/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (71.98%)
 * Likes:    1177
 * Dislikes: 0
 * Total Accepted:    357K
 * Total Submissions: 495.9K
 * Testcase Example:  '3'
 *
 * 给你一个正整数 n ，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 3
 * 输出：[[1,2,3],[8,9,4],[7,6,5]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：[[1]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> a(n,vector<int>(n));
        int cnt=1;
        int i=0,j=0;
        a[i][j]=1;
        while(cnt!=n*n){
            while(j+1<n&&!a[i][j+1]) ++cnt,a[i][++j]=cnt;
            while(i+1<n&&!a[i+1][j]) ++cnt,a[++i][j]=cnt;
            while(j-1>=0&&!a[i][j-1]) ++cnt,a[i][--j]=cnt;
            while(i-1>=0&&!a[i-1][j]) ++cnt,a[--i][j]=cnt;
        }
        return a;
    }
};
// @lc code=end

