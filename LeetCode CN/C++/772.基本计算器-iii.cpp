/*
 * @lc app=leetcode.cn id=772 lang=cpp
 *
 * [772] 基本计算器 III
 *
 * https://leetcode.cn/problems/basic-calculator-iii/description/
 *
 * algorithms
 * Hard (53.29%)
 * Likes:    156
 * Dislikes: 0
 * Total Accepted:    14.1K
 * Total Submissions: 26.4K
 * Testcase Example:  '"1+1"'
 *
 * 实现一个基本的计算器来计算简单的表达式字符串。
 * 
 * 表达式字符串只包含非负整数，算符 +、-、*、/ ，左括号 ( 和右括号 ) 。整数除法需要 向下截断 。
 * 
 * 你可以假定给定的表达式总是有效的。所有的中间结果的范围均满足 [-2^31, 2^31 - 1] 。
 * 
 * 注意：你不能使用任何将字符串作为表达式求值的内置函数，比如 eval() 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "1+1"
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "6-4/2"
 * 输出：4
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "2*(5+5*2)/3+(6/2+8)"
 * 输出：21
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s <= 10^4
 * s 由整数、'+'、'-'、'*'、'/'、'(' 和 ')' 组成
 * s 是一个 有效的 表达式
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int i = 0;
    string str;
    int ca(){
        vector<int> tmp;
        char presign = '+';
        int num = 0;
        while(str[i]!=')'){
            if(isdigit(str[i])){
                num = num*10+str[i]-'0';
            }
            if(str[i]=='('){
                ++i;
                num = ca();
            }
            if(!isdigit(str[i])&&str[i]!='('||str[i+1]==')'){
                if(presign=='+'){
                    tmp.push_back(num);
                }
                else if(presign=='-'){
                    tmp.push_back(-num);
                }
                else if(presign=='*'){
                    tmp.back()*=num;
                }
                else if(presign=='/'){
                    tmp.back()/=num;
                }
                presign = str[i];
                num = 0;
            }
            i++;
        }
        
        return accumulate(tmp.begin(),tmp.end(),0);
    }

    int calculate(string s) {
        int n=s.size();
        str = s;
        vector<int> tmp;
        char presign = '+';
        int num = 0;
        while(i<n){
            if(isdigit(str[i])){
                num = num*10+str[i]-'0';
            }
            if(str[i]=='('){
                ++i;
                num = ca();
            }
            if(!isdigit(str[i])&&str[i]!='('||i==n-1){
                if(presign=='+'){
                    tmp.push_back(num);
                }
                else if(presign=='-'){
                    tmp.push_back(-num);
                }
                else if(presign=='*'){
                    tmp.back()*=num;
                }
                else if(presign=='/'){
                    tmp.back()/=num;
                }
                presign = str[i];
                num = 0;
            }
            i++;        
        }
        return accumulate(tmp.begin(),tmp.end(),0);
    }
};
// @lc code=end

