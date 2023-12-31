/*
 * @lc app=leetcode.cn id=1081 lang=cpp
 *
 * [1081] 不同字符的最小子序列
 *
 * https://leetcode.cn/problems/smallest-subsequence-of-distinct-characters/description/
 *
 * algorithms
 * Medium (58.56%)
 * Likes:    199
 * Dislikes: 0
 * Total Accepted:    27.7K
 * Total Submissions: 47.2K
 * Testcase Example:  '"bcabc"'
 *
 * 返回 s 字典序最小的子序列，该子序列包含 s 的所有不同字符，且只包含一次。
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
 * 1 <= s.length <= 1000
 * s 由小写英文字母组成
 * 
 * 
 * 
 * 
 * 注意：该题与 316 https://leetcode.cn/problems/remove-duplicate-letters/ 相同
 * 
 */

// @lc code=start
class Solution {
public:
    string smallestSubsequence(string s) {
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

