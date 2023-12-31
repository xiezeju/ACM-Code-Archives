/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 *
 * https://leetcode.cn/problems/is-subsequence/description/
 *
 * algorithms
 * Easy (52.37%)
 * Likes:    953
 * Dislikes: 0
 * Total Accepted:    347K
 * Total Submissions: 662.7K
 * Testcase Example:  '"abc"\n"ahbgdc"'
 *
 * 给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
 * 
 * 
 * 字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
 * 
 * 进阶：
 * 
 * 如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T
 * 的子序列。在这种情况下，你会怎样改变代码？
 * 
 * 致谢：
 * 
 * 特别感谢 @pbrother 添加此问题并且创建所有测试用例。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "abc", t = "ahbgdc"
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "axc", t = "ahbgdc"
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * 0 
 * 两个字符串都只由小写字符组成。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = t.size();
        //dp[i][j]代表从位置i到字符j第一次出现的位置
        vector<vector<int>> dp(n+1,vector<int>(26,0));
        //从后向前转移，转移到n就出界，如果转移时直接跳到n说明转移失败
        for(int i=0;i<26;i++){
            dp[n][i] = n;
        }
        //由于dp[i][j]=dp[i+1][j]，所以需要从后向前转移
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<26;j++){
                //当前位置的字符最后一次出现的位置肯定为当前位置
                if(t[i]-'a'==j){
                    dp[i][j] = i;
                }
                else{
                    dp[i][j] = dp[i+1][j];
                }
            }
        }
        //开始转移，起始位置为0
        int pos = 0;
        for(int i=0;i<s.size();i++){
            //中途转移时出界，转移失败
            if(dp[pos][s[i]-'a']==n){
                return false;
            }
            //转移成功后光标还要往后跳一个单位
            pos = dp[pos][s[i]-'a']+1;
        }
        //没有中途出界，说明完成了整个转移过程，转移结束
        return true;
    }
};
// @lc code=end

