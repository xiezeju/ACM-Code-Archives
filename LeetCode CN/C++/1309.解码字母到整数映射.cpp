/*
 * @lc app=leetcode.cn id=1309 lang=cpp
 *
 * [1309] 解码字母到整数映射
 *
 * https://leetcode.cn/problems/decrypt-string-from-alphabet-to-integer-mapping/description/
 *
 * algorithms
 * Easy (76.72%)
 * Likes:    85
 * Dislikes: 0
 * Total Accepted:    28.7K
 * Total Submissions: 37.4K
 * Testcase Example:  '"10#11#12"'
 *
 * 给你一个字符串 s，它由数字（'0' -
 * '9'）和 '#' 组成。我们希望按下述规则将 s 映射为一些小写英文字符：
 *
 *
 * 字符（'a' - 'i'）分别用（'1' - '9'）表示。
 * 字符（'j' - 'z'）分别用（'10#' - '26#'）表示。 
 *
 *
 * 返回映射之后形成的新字符串。
 *
 * 题目数据保证映射始终唯一。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "10#11#12"
 * 输出："jkab"
 * 解释："j" -> "10#" , "k" -> "11#" , "a" -> "1" , "b" -> "2".
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "1326#"
 * 输出："acz"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 1000
 * s[i] 只包含数字（'0'-'9'）和 '#' 字符。
 * s 是映射始终存在的有效字符串。
 *
 *
 */

// @lc code=start
class Solution {
    public:
        string freqAlphabets(string s) {
            string     a = "";
            stack<int> st;
            int        n = s.size();
            for (int i = n - 1; i >= 0;) {
                if (s[i] == '#') {
                    i -= 2;
                    int t = (s[i] - '0') * 10 + s[i + 1] - '0';
                    st.push(t);
                    i--;
                } else {
                    st.push(s[i] - '0');
                    i--;
                }
            }
            while (!st.empty()) {
                a += (char)(st.top() + 'a' - 1);
                st.pop();
            }

            return a;
        }
};

// @lc code=end
