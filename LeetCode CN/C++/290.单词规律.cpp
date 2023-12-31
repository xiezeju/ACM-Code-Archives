/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 *
 * https://leetcode.cn/problems/word-pattern/description/
 *
 * algorithms
 * Easy (44.51%)
 * Likes:    606
 * Dislikes: 0
 * Total Accepted:    146.1K
 * Total Submissions: 328.2K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * 给定一种规律 pattern 和一个字符串 s ，判断 s 是否遵循相同的规律。
 * 
 * 这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 s 中的每个非空单词之间存在着双向连接的对应规律。
 * 
 * 
 * 
 * 示例1:
 * 
 * 
 * 输入: pattern = "abba", s = "dog cat cat dog"
 * 输出: true
 * 
 * 示例 2:
 * 
 * 
 * 输入:pattern = "abba", s = "dog cat cat fish"
 * 输出: false
 * 
 * 示例 3:
 * 
 * 
 * 输入: pattern = "aaaa", s = "dog cat cat dog"
 * 输出: false
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= pattern.length <= 300
 * pattern 只包含小写英文字母
 * 1 <= s.length <= 3000
 * s 只包含小写英文字母和 ' '
 * s 不包含 任何前导或尾随对空格
 * s 中每个单词都被 单个空格 分隔
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool wordPattern(string p, string s) {
        s = s + " ";
        unordered_map<char,string> c2s;
        unordered_map<string,char> s2c;
        string tmp;
        int n = s.size();
        int i = 0;
        for(auto ch:p){
            tmp = "";
            if(i>=n) return false;
            int j = i;
            while(j<n&&s[j]!=' ') tmp=tmp+s[j++];
            
            if(s2c.count(tmp)&&s2c[tmp]!=ch) return false;
            if(c2s.count(ch)&&c2s[ch]!=tmp) return false;
            s2c[tmp]=ch;
            c2s[ch]=tmp;
            
            i = j + 1;
        }
        return i>=n;
    }
};
// @lc code=end

