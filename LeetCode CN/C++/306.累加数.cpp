/*
 * @lc app=leetcode.cn id=306 lang=cpp
 *
 * [306] 累加数
 *
 * https://leetcode.cn/problems/additive-number/description/
 *
 * algorithms
 * Medium (37.78%)
 * Likes:    426
 * Dislikes: 0
 * Total Accepted:    50.5K
 * Total Submissions: 133.6K
 * Testcase Example:  '"112358"'
 *
 * 累加数 是一个字符串，组成它的数字可以形成累加序列。
 * 
 * 一个有效的 累加序列 必须 至少 包含 3 个数。除了最开始的两个数以外，序列中的每个后续数字必须是它之前两个数字之和。
 * 
 * 给你一个只包含数字 '0'-'9' 的字符串，编写一个算法来判断给定输入是否是 累加数 。如果是，返回 true ；否则，返回 false 。
 * 
 * 说明：累加序列里的数，除数字 0 之外，不会 以 0 开头，所以不会出现 1, 2, 03 或者 1, 02, 3 的情况。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入："112358"
 * 输出：true 
 * 解释：累加序列为: 1, 1, 2, 3, 5, 8 。1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入："199100199"
 * 输出：true 
 * 解释：累加序列为: 1, 99, 100, 199。1 + 99 = 100, 99 + 100 = 199
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= num.length <= 35
 * num 仅由数字（0 - 9）组成
 * 
 * 
 * 
 * 
 * 进阶：你计划如何处理由过大的整数输入导致的溢出?
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> tmp;
    string add(string a,string b){
        int i=a.size()-1,j=b.size()-1;
        int sum=0;
        int t=0;
        string s="";
        while(i>=0||j>=0||t!=0){
            int x1 = i<0 ? 0 : a[i]-'0';
            int x2 = j<0 ? 0 : b[j]-'0';
            sum=x1+x2+t;
            t=sum/10;
            sum%=10;
            s+=to_string(sum);
            --i,--j;
        }
        reverse(s.begin(),s.end());
        return s;
    }

    bool dfs(string& num,int idx){
        int n = tmp.size();
        if(tmp.size()>=3&&add(tmp[n-3],tmp[n-2])!=tmp[n-1]){
            return false;
        } 
        if(idx==num.size()){
            if(n<3) return false;
            return true;
        }
        for(int i=1;i<=num.size()-idx;i++){
            string cur = num.substr(idx,i);
            if(i!=1&&cur[0]=='0') return false;
            tmp.push_back(cur);
            if(dfs(num,idx+i))return true;
            tmp.pop_back();
        }
        return false;
    }

    bool isAdditiveNumber(string num) {
        if(num.size()<3) return false;
        return dfs(num,0);
    }
};
// @lc code=end

