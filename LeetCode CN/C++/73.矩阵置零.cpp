/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 *
 * https://leetcode.cn/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (64.04%)
 * Likes:    951
 * Dislikes: 0
 * Total Accepted:    280.4K
 * Total Submissions: 437.7K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * 给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
 * 输出：[[1,0,1],[0,0,0],[1,0,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
 * 输出：[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[0].length
 * 1 <= m, n <= 200
 * -2^31 <= matrix[i][j] <= 2^31 - 1
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 一个直观的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
 * 一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
 * 你能想出一个仅使用常量空间的解决方案吗？
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        struct node{
            int x,y;
        };
        vector<node> a;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(mat[i][j]==0)
                    a.push_back({i,j});

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    for(int k=0;k<a.size();k++)
                        if(a[k].x==i&&a[k].y==j){
                            int x = i,y = j;
                            while(x-1>=0) mat[--x][y]=0; x=i;
                            while(x+1<m) mat[++x][y]=0; x=i;
                            while(y-1>=0) mat[x][--y]=0; y=j;
                            while(y+1<n) mat[x][++y]=0; y=j;
                        }
                }
            }
        }
    }
};

//更好的解法，利用第一行和第一列来记录该列/行是否需要置0，在此之前需要先看一下第一行和第一列里面是不是本身已经含有0，如果本身含有0的话最后需要对第一行或者第一列进行置0操作
//LeetCode官方题解
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int flag_col0 = false, flag_row0 = false;
        for (int i = 0; i < m; i++) {
            if (!matrix[i][0]) {
                flag_col0 = true;
            }
        }
        for (int j = 0; j < n; j++) {
            if (!matrix[0][j]) {
                flag_row0 = true;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (!matrix[i][j]) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (!matrix[i][0] || !matrix[0][j]) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (flag_col0) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
        if (flag_row0) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
    }
};
// @lc code=end

