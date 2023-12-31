/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 *
 * https://leetcode.cn/problems/reverse-words-in-a-string-iii/description/
 *
 * algorithms
 * Easy (73.70%)
 * Likes:    566
 * Dislikes: 0
 * Total Accepted:    313.7K
 * Total Submissions: 425.7K
 * Testcase Example:  `"Let's take LeetCode contest"`
 *
 * 给定一个字符串 s ，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "Let's take LeetCode contest"
 * 输出："s'teL ekat edoCteeL tsetnoc"
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入： s = "God Ding"
 * 输出："doG gniD"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 5 * 10^4
 * s 包含可打印的 ASCII 字符。
 * s 不包含任何开头或结尾空格。
 * s 里 至少 有一个词。
 * s 中的所有单词都用一个空格隔开。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        s=' '+s;
        s=s+' ';
        int n = s.size();
        int l,r;
        for(int i=1;i<n;i++){
            if(s[i]!=' '&&s[i-1]==' ') l = i;
            else if(s[i]==' '&&s[i-1]!=' '){
                r = i;
                reverse(s.begin()+l,s.begin()+r);
            }
        }
        s.erase(s.begin());
        s.erase(s.end()-1);
        return s;
    }
};
// @lc code=end

