/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode.cn/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (43.93%)
 * Likes:    4198
 * Dislikes: 0
 * Total Accepted:    1.6M
 * Total Submissions: 3.7M
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 每个右括号都有一个对应的相同类型的左括号。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "()"
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "()[]{}"
 * 输出：true
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "(]"
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^4
 * s 仅由括号 '()[]{}' 组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        unordered_map<char,char> m;
        m['('] = ')';
        m['['] = ']';
        m['{'] = '}';
        int n = s.size();
        for(int i=0;i<n;i++){
            if(m.count(s[i])) st.push(s[i]);
            else{
                if(!st.empty()&&s[i]==m[st.top()])
                    st.pop();
                else if(st.empty()||!st.empty()&&s[i]!=m[st.top()]) return false;
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};
// @lc code=end

