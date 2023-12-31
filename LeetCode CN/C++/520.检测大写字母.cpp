/*
 * @lc app=leetcode.cn id=520 lang=cpp
 *
 * [520] 检测大写字母
 *
 * https://leetcode.cn/problems/detect-capital/description/
 *
 * algorithms
 * Easy (56.66%)
 * Likes:    254
 * Dislikes: 0
 * Total Accepted:    92K
 * Total Submissions: 162.3K
 * Testcase Example:  '"USA"'
 *
 * 我们定义，在以下情况时，单词的大写用法是正确的：
 * 
 * 
 * 全部字母都是大写，比如 "USA" 。
 * 单词中所有字母都不是大写，比如 "leetcode" 。
 * 如果单词不只含有一个字母，只有首字母大写， 比如 "Google" 。
 * 
 * 
 * 给你一个字符串 word 。如果大写用法正确，返回 true ；否则，返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：word = "USA"
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：word = "FlaG"
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= word.length <= 100
 * word 由小写和大写英文字母组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool detectCapitalUse(string word) {
        unordered_map<string,int> s;
        int n = word.size();
        string p1 ,p2 ,p3;
        for(int i=0;i<n;i++){
            p1.push_back(toupper(word[i]));
            p2.push_back(tolower(word[i]));
        }
        p3 = p2;
        p3[0] = toupper(p3[0]);
        s[p1]++,s[p2]++,s[p3]++;
        return s.count(word);
    }
};
// @lc code=end

