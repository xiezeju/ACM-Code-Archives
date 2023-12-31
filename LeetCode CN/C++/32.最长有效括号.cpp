/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 *
 * https://leetcode.cn/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (37.40%)
 * Likes:    2375
 * Dislikes: 0
 * Total Accepted:    400.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '"(()"'
 *
 * 给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "(()"
 * 输出：2
 * 解释：最长有效括号子串是 "()"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = ")()())"
 * 输出：4
 * 解释：最长有效括号子串是 "()()"
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = ""
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * s[i] 为 '(' 或 ')'
 * 
 * 
 * 
 * 
 */

// @lc code=start
//动态规划解法
class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        int n = s.size();
        vector<int> dp(n,0);
        for(int i=1;i<n;i++){
            if(s[i]==')'){
                /*case 1: 形如 ...() 需要检查(前面一个位置i-2的dp值，
                如果位置有效并且dp值不为0说明(前含有连续匹配值，需要加上dp[i-2]*/
                if(s[i-1]=='(') 
                    dp[i] = 2 + (i-2>=0? dp[i-2] : 0);
                /*case 2: 形如 .(.)) 需要检查(前面一个位置i-dp[i-1]-2的dp值，
                如果位置有效并且dp值不为0说明(前含有连续匹配值,需要加上dp[i-dp[i-1]-2]*/
                else if(i-dp[i-1]-1>=0&&s[i-dp[i-1]-1]=='(')
                    dp[i] = 2 + dp[i-1] + (i-dp[i-1]-2>=0 ? dp[i-dp[i-1]-2] : 0);
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};
//栈解法
class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        int n = s.size();
        stack<int> st;
        st.push(-1);
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(i);
            else{
                st.pop();
                if(!st.empty()){
                    ans = max(ans,i-st.top());
                }
                else{
                    st.push(i);
                }
                    
            }
        }
        return ans;
    }
};
// @lc code=end

