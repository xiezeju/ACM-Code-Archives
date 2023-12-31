/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 *
 * https://leetcode.cn/problems/number-of-segments-in-a-string/description/
 *
 * algorithms
 * Easy (38.44%)
 * Likes:    217
 * Dislikes: 0
 * Total Accepted:    95.2K
 * Total Submissions: 247.7K
 * Testcase Example:  '"Hello, my name is John"'
 *
 * 统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。
 * 
 * 请注意，你可以假定字符串里不包括任何不可打印的字符。
 * 
 * 示例:
 * 
 * 输入: "Hello, my name is John"
 * 输出: 5
 * 解释: 这里的单词是指连续的不是空格的字符，所以 "Hello," 算作 1 个单词。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int countSegments(string s) {
        int n = s.size();
        int i = 0;
        s += ' ';
        int ans = 0;
        while(i<n){
            if(s[i]!=' '&&s[i+1]==' '){
                ans++;
            }
            i++;
        }
        return ans;
    }
};
// @lc code=end

