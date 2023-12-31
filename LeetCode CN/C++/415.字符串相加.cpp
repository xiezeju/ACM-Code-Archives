/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 *
 * https://leetcode.cn/problems/add-strings/description/
 *
 * algorithms
 * Easy (54.70%)
 * Likes:    796
 * Dislikes: 0
 * Total Accepted:    303.6K
 * Total Submissions: 555.1K
 * Testcase Example:  '"11"\n"123"'
 *
 * 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。
 * 
 * 你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：num1 = "11", num2 = "123"
 * 输出："134"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：num1 = "456", num2 = "77"
 * 输出："533"
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：num1 = "0", num2 = "0"
 * 输出："0"
 * 
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= num1.length, num2.length <= 10^4
 * num1 和num2 都只包含数字 0-9
 * num1 和num2 都不包含任何前导零
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string addStrings(string a, string b) {
        if(a.size()<b.size()) swap(a,b);
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int t = 0;
        string s = "";
        for(int i=0;i<a.size();i++){
            int x1 = a[i] - '0';
            int x2 = i>=b.size()? 0:b[i]-'0';
            int sum = x1 + x2 + t;
            t = sum/10;
            sum%=10;
            s+=to_string(sum);
            if(i==a.size()-1&&t){
                s+="1";
            }
        } 
        reverse(s.begin(),s.end());
        return s;
    }
};
// @lc code=end

