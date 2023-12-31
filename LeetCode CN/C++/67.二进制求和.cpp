/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode.cn/problems/add-binary/description/
 *
 * algorithms
 * Easy (52.90%)
 * Likes:    1109
 * Dislikes: 0
 * Total Accepted:    349.4K
 * Total Submissions: 660.6K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给你两个二进制字符串 a 和 b ，以二进制字符串的形式返回它们的和。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入:a = "11", b = "1"
 * 输出："100"
 * 
 * 示例 2：
 * 
 * 
 * 输入：a = "1010", b = "1011"
 * 输出："10101"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= a.length, b.length <= 10^4
 * a 和 b 仅由字符 '0' 或 '1' 组成
 * 字符串如果不是 "0" ，就不含前导零
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size()<b.size()) swap(a,b);
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int n = a.size();
        int t = 0;
        string s ="";
        for(int i=0;i<n;i++){
            int x1 = a[i]-'0';
            int x2 = i>=b.size()?0:b[i]-'0';
            int sum = x1+x2+t;
            t = sum/2;
            sum%=2;
            s+=to_string(sum);
            if(i==n-1&&t)
                s+="1";
        }
        reverse(s.begin(),s.end());
        return s;
    }
};
// @lc code=end

