/*
 * @lc app=leetcode.cn id=524 lang=cpp
 *
 * [524] 通过删除字母匹配到字典里最长单词
 *
 * https://leetcode.cn/problems/longest-word-in-dictionary-through-deleting/description/
 *
 * algorithms
 * Medium (50.09%)
 * Likes:    351
 * Dislikes: 0
 * Total Accepted:    103.8K
 * Total Submissions: 207.2K
 * Testcase Example:  '"abpcplea"\n["ale","apple","monkey","plea"]'
 *
 * 给你一个字符串 s 和一个字符串数组 dictionary ，找出并返回 dictionary 中最长的字符串，该字符串可以通过删除 s
 * 中的某些字符得到。
 * 
 * 如果答案不止一个，返回长度最长且字母序最小的字符串。如果答案不存在，则返回空字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
 * 输出："apple"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "abpcplea", dictionary = ["a","b","c"]
 * 输出："a"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 1000
 * 1 <= dictionary.length <= 1000
 * 1 <= dictionary[i].length <= 1000
 * s 和 dictionary[i] 仅由小写英文字母组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(26,0));
        for(int i=0;i<26;i++){
            dp[n][i] = n;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<26;j++){
                if(s[i]-'a'==j){
                    dp[i][j] = i;
                }else{
                    dp[i][j] = dp[i+1][j];
                }
            }
        }
        vector<string> ans;
        int length = 0;
        for(int i=0;i<dictionary.size();i++){
            int pos = 0;
            bool ok = true;
            for(int j=0;j<dictionary[i].size();j++){
                if(dp[pos][dictionary[i][j]-'a']==n){
                    ok = false;
                    break;
                }
                pos = dp[pos][dictionary[i][j]-'a'] + 1;
            }
            if(ok==false||dictionary[i].size()<length) continue;
            if(dictionary[i].size()>length){
                length = dictionary[i].size();
                ans.clear();
            }
            ans.push_back(dictionary[i]);
        }
        sort(ans.begin(),ans.end());
        if(!ans.size()) return "";
        return ans[0];
    }
};
// @lc code=end

