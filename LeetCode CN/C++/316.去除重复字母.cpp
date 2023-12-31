/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 *
 * https://leetcode.cn/problems/remove-duplicate-letters/description/
 *
 * algorithms
 * Medium (48.50%)
 * Likes:    992
 * Dislikes: 0
 * Total Accepted:    124.7K
 * Total Submissions: 257.2K
 * Testcase Example:  '"bcabc"'
 *
 * 给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "bcabc"
 * 输出："abc"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "cbacdcbc"
 * 输出："acdb"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^4
 * s 由小写英文字母组成
 * 
 * 
 * 
 * 
 * 注意：该题与 1081
 * https://leetcode-cn.com/problems/smallest-subsequence-of-distinct-characters
 * 相同
 * 
 */

// @lc code=start
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        vector<int> inStack(26), lastIndex(26);
        string st = "";
        for(int i=0;i<n;i++){
            lastIndex[s[i]-'a'] = i;
        }
        for(int i=0;i<n;i++){

            if(inStack[s[i]-'a']) {
               continue; 
            }
            while(!st.empty()&& st.back()>s[i] &&lastIndex[st.back()-'a']>i){
                inStack[st.back()-'a']=0;
                st.pop_back();
            }
            st.push_back(s[i]);
            inStack[s[i]-'a']=1;
        } 

        return st;
    }
};
// @lc code=end

