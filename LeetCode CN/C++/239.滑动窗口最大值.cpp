/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 *
 * https://leetcode.cn/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (49.36%)
 * Likes:    2551
 * Dislikes: 0
 * Total Accepted:    498.4K
 * Total Submissions: 1M
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k
 * 个数字。滑动窗口每次只向右移动一位。
 * 
 * 返回 滑动窗口中的最大值 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
 * 输出：[3,3,5,5,6,7]
 * 解释：
 * 滑动窗口的位置                最大值
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1], k = 1
 * 输出：[1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 1 <= k <= nums.length
 * 
 * 
 */

// @lc code=start
//优先队列解法 O(nlogn)
/*
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        priority_queue<pair<int,int>> q;
        for(int i=0;i<k;i++){
            q.emplace(nums[i],i);
        }
        ans.push_back(q.top().first);
        for(int i=k;i<n;i++){
            q.emplace(nums[i],i);
            while(q.top().second<=i-k){
                q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;
    }
};

//单调队列解法
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> q;
        for(int i=0;i<k;i++){
            while(!q.empty()&&nums[q.back()]<=nums[i]){
                q.pop_back();
            }
            q.push_back(i);
        }
        ans.push_back(nums[q.front()]);
        for(int i=k;i<n;i++){
            while(!q.empty()&&nums[q.back()]<=nums[i]){
                q.pop_back();
            }

            while(!q.empty()&&q.front()<=i-k){
                q.pop_front();
            }
            q.push_back(i);
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};
*/
//分块预处理做法
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        vector<int> pre(n),suff(n);
        for(int i=0;i<n;i++){
            if(i%k==0){
                pre[i] = nums[i];
            }
            else{
                pre[i] = max(pre[i-1],nums[i]);
            }
        }
        for(int i=n-1;i>=0;i--){
            if(i==n-1||(i+1)%k==0){
                suff[i] = nums[i];
            }
            else{
                suff[i] = max(suff[i+1],nums[i]);
            }
        }
        for(int i=0;i<=n-k;i++){
            ans.push_back(max(suff[i],pre[i+k-1]));
        }

        
        return ans;
    }
};

// @lc code=end

