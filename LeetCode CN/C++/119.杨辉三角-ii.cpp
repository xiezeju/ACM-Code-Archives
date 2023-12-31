/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 *
 * https://leetcode.cn/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (68.92%)
 * Likes:    511
 * Dislikes: 0
 * Total Accepted:    284.3K
 * Total Submissions: 412.5K
 * Testcase Example:  '3'
 *
 * 给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。
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
 * 输入: rowIndex = 3
 * 输出: [1,3,3,1]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: rowIndex = 0
 * 输出: [1]
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: rowIndex = 1
 * 输出: [1,1]
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 0 
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 你可以优化你的算法到 O(rowIndex) 空间复杂度吗？
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> getRow(int n) {
        vector<int> a;
        a.push_back(1);
        if(n==0) return a;
        a.push_back(1);
        for(int k=2;k<=n;k++){
            a.resize(k+1);
            a[k] = 1;
            for(int i=k-1;i>0;i--)
                a[i] += a[i-1];   
        }
        return a;
    }
};
// @lc code=end

