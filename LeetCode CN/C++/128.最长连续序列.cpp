/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 *
 * https://leetcode.cn/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Medium (53.75%)
 * Likes:    1843
 * Dislikes: 0
 * Total Accepted:    457.5K
 * Total Submissions: 851.8K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
 * 
 * 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [100,4,200,1,3,2]
 * 输出：4
 * 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,3,7,2,5,8,4,6,0,1]
 * 输出：9
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * -10^9 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        int maxs = 0;
        unordered_map<int,int> s;
        for(int i=0;i<a.size();i++) s[a[i]]++;
        for(int i=0;i<a.size();i++){
            int sum = 1;
            int t = a[i];
            if(s[t+1]) continue; //重要优化，不写会超时
            while(s[--t]) ++sum;
            maxs = max(maxs,sum);
        }
        return maxs;
    }
};
// @lc code=end

