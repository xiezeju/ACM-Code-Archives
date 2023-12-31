/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 *
 * https://leetcode.cn/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (63.09%)
 * Likes:    4770
 * Dislikes: 0
 * Total Accepted:    784.6K
 * Total Submissions: 1.2M
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出：6
 * 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：height = [4,2,0,3,2,5]
 * 输出：9
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == height.length
 * 1 <= n <= 2 * 10^4
 * 0 <= height[i] <= 10^5
 * 
 * 
 */

// @lc code=start
//单调栈解法

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int sum = 0;
        stack<int> s;
        for(int i=0;i<n;i++){
            while(!s.empty()&&height[i]>height[s.top()]){
                int bottom = s.top();
                s.pop();
                if(s.empty()) break;
                int left = s.top();
                int width = i-left-1;
                sum+=width*(min(height[i],height[s.top()])-height[bottom]);
            }
            s.push(i);
        }

        return sum;
        
    }
};

//动态规划解法
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n),rightMax(n);
        leftMax[0] = height[0];
        rightMax[n-1] = height[n-1];
        for(int i=1;i<n;i++){
            leftMax[i] = max(height[i],leftMax[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            rightMax[i] = max(height[i],rightMax[i+1]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += min(leftMax[i],rightMax[i])-height[i];
        }
        return ans;
    }
};

// @lc code=end

