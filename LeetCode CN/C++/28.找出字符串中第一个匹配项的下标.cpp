/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 *
 * https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
 *
 * algorithms
 * Easy (42.82%)
 * Likes:    2035
 * Dislikes: 0
 * Total Accepted:    924.9K
 * Total Submissions: 2.2M
 * Testcase Example:  '"sadbutsad"\n"sad"'
 *
 * 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0
 * 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：haystack = "sadbutsad", needle = "sad"
 * 输出：0
 * 解释："sad" 在下标 0 和 6 处匹配。
 * 第一个匹配项的下标是 0 ，所以返回 0 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：haystack = "leetcode", needle = "leeto"
 * 输出：-1
 * 解释："leeto" 没有在 "leetcode" 中出现，所以返回 -1 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= haystack.length, needle.length <= 10^4
 * haystack 和 needle 仅由小写英文字符组成
 * 
 * 
 */

// @lc code=start

//暴力解法
class Solution {
public:
    int strStr(string s, string p) {
        int n = s.size(), m = p.size();
        for(int i = 0; i <= n - m; i++){
            int j = i, k = 0; 
            while(k < m and s[j] == p[k]){
                j++;
                k++;
            }
            if(k == m) return i;
        }
        return -1;
    }
};
//API解法
class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};


// @lc code=end

