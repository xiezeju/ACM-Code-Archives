/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 *
 * https://leetcode.cn/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (65.99%)
 * Likes:    853
 * Dislikes: 0
 * Total Accepted:    665.2K
 * Total Submissions: 1M
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
 * 
 * 注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: s = "anagram", t = "nagaram"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "rat", t = "car"
 * 输出: false
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 
 * s 和 t 仅包含小写字母
 * 
 * 
 * 
 * 
 * 进阶: 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
 * 
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> cnt(26);
        for(int i=0;i<s.size();i++)
            cnt[s[i]-'a']++;
        for(int i=0;i<t.size();i++)
            cnt[t[i]-'a']--;
        for(int i=0;i<26;i++){
            if(cnt[i]) return false;
        }
        return true;
    }
};
// @lc code=end

