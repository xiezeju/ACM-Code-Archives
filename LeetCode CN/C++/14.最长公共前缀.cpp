/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode.cn/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (43.52%)
 * Likes:    2947
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 2.7M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：strs = ["flower","flow","flight"]
 * 输出："fl"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：strs = ["dog","racecar","car"]
 * 输出：""
 * 解释：输入不存在公共前缀。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= strs.length <= 200
 * 0 <= strs[i].length <= 200
 * strs[i] 仅由小写英文字母组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(!n) return "";
        int length = strs[0].size();
        for(int i=0;i<length;i++){
            char c = strs[0][i];
            for(int j=0;j<n;j++){
                if(i==strs[j].size()||strs[j][i]!=c)
                    return strs[0].substr(0,i);
            }
        }
        return strs[0];
    }
};
// @lc code=end

