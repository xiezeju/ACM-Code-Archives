/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 *
 * https://leetcode.cn/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (43.41%)
 * Likes:    1947
 * Dislikes: 0
 * Total Accepted:    322.6K
 * Total Submissions: 743.1K
 * Testcase Example:  '[1,2,0]'
 *
 * 给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
 * 请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,0]
 * 输出：3
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [3,4,-1,1]
 * 输出：2
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [7,8,9,11,12]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -2^31 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& a) {
        int ans = 1;
        int n = a.size();
        for(auto& i:a)
            if(i<=0) i = n+1; //给负数打上n+1的标记，排除负数对[1,n]内的数的影响
        
        for(int i=0;i<n;i++){
            int x = abs(a[i]);
            if(x<=n) //将所有出现在[1,n]内的数，将它们数组对应位置打上负数标记
                a[x-1] = -abs(a[x-1]); 
        }
            
        
        for(int i=0;i<n;i++) /*所有数组中出现过的[1,n]内数的位置已经是负数了，如果有数没有出现过，那么它对应位置上既没有n+1标记，也没有负数标记，那么位置+1就是该最小正数*/
            if(a[i]>0) return i+1;

        return n+1; //如果[1,n]内的数都被打了负数标记，那没出现的最小正数只能是n+1
    }
};

class Solution {
public:
    int firstMissingPositive(vector<int>& a) {
        int n = a.size();
        for(int i=0;i<n;i++)
            while(a[i]>0&&a[i]<=n&&a[a[i]-1]!=a[i]) //将[1,n]内的数交换到对应的位置上去，同时避免两个位置上的数相等使交换陷入死循环
                swap(a[a[i]-1],a[i]);
        for(int i=0;i<n;i++) //全部处理完之后开始遍历数组，对应位置上的数不为i+1就找到了缺失的最小正数
            if(a[i]!=i+1) return i+1;
        
        return n+1;
    }
};

// @lc code=end

