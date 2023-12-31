/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 *
 * https://leetcode.cn/problems/find-the-difference/description/
 *
 * algorithms
 * Easy (66.18%)
 * Likes:    426
 * Dislikes: 0
 * Total Accepted:    175.6K
 * Total Submissions: 265.4K
 * Testcase Example:  '"abcd"\n"abcde"'
 *
 * 给定两个字符串 s 和 t ，它们只包含小写字母。
 * 
 * 字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。
 * 
 * 请找出在 t 中被添加的字母。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "abcd", t = "abcde"
 * 输出："e"
 * 解释：'e' 是那个被添加的字母。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "", t = "y"
 * 输出："y"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= s.length <= 1000
 * t.length == s.length + 1
 * s 和 t 只包含小写字母
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int>cnt1(26),cnt2(26);
        int n = s.size();
        for(int i=0;i<n;i++){
            cnt1[s[i]-'a']++;
        }
        for(int i=0;i<n+1;i++){
            cnt2[t[i]-'a']++;
            if(cnt2[t[i]-'a']>cnt1[t[i]-'a']) return t[i];
        }
        return 'a';
    }
};
// @lc code=end

