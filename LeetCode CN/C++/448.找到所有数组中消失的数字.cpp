/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 *
 * https://leetcode.cn/problems/find-all-numbers-disappeared-in-an-array/description/
 *
 * algorithms
 * Easy (65.78%)
 * Likes:    1270
 * Dislikes: 0
 * Total Accepted:    294.8K
 * Total Submissions: 448.1K
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * 给你一个含 n 个整数的数组 nums ，其中 nums[i] 在区间 [1, n] 内。请你找出所有在 [1, n] 范围内但没有出现在 nums
 * 中的数字，并以数组的形式返回结果。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [4,3,2,7,8,2,3,1]
 * 输出：[5,6]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,1]
 * 输出：[2]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == nums.length
 * 1 
 * 1 
 * 
 * 
 * 进阶：你能在不使用额外空间且时间复杂度为 O(n) 的情况下解决这个问题吗? 你可以假定返回的数组不算在额外空间内。
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& a) {
        int n = a.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            int idx = (a[i]-1) % n; //还原被加过的下标
            a[idx] += n; //对应位置+n
        }
        for(int i=0;i<n;i++)
            if(a[i]<=n) ans.push_back(i+1); //发现此位置没+n，说明i+1没出现过
        
        return ans;

    }
};
// @lc code=end

