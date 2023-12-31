/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 *
 * https://leetcode.cn/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (75.50%)
 * Likes:    1071
 * Dislikes: 0
 * Total Accepted:    446.3K
 * Total Submissions: 591.1K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
 * 
 * 在「杨辉三角」中，每个数是它左上方和右上方的数的和。
 * 
 * 
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: numRows = 5
 * 输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: numRows = 1
 * 输出: [[1]]
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> a(n);
        a[0].push_back(1);
        for(int i=1;i<n;i++){
            a[i].push_back(1);
            for(int j=1;j<i;j++)
                a[i].push_back(a[i-1][j]+a[i-1][j-1]);
            a[i].push_back(1);
        }
        return a;
    }
};
// @lc code=end

