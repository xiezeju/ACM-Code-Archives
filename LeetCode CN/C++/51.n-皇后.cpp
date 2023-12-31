/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 *
 * https://leetcode.cn/problems/n-queens/description/
 *
 * algorithms
 * Hard (74.00%)
 * Likes:    1929
 * Dislikes: 0
 * Total Accepted:    339.5K
 * Total Submissions: 459K
 * Testcase Example:  '4'
 *
 * 按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。
 * 
 * n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
 * 
 * 
 * 
 * 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 4
 * 输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 * 解释：如上图所示，4 皇后问题存在两个不同的解法。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：[["Q"]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 9
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> a;
    vector<bool> vis,attack_main,attack_sub;
    
    void dfs(vector<string>& queen,int x,int n){
        if(x==n){
            a.push_back(queen); 
            return;
        }
        for(int i=0;i<n;i++){
            if(queen[x][i]=='.'&&!vis[i]&&!attack_main[x-i+n-1]&&!attack_sub[x+i]){
                queen[x][i] = 'Q';
                vis[i] = true;
                attack_main[x-i+n-1] = true;
                attack_sub[x+i] = true;
                dfs(queen,x+1,n);
                queen[x][i] = '.';
                vis[i] = false;
                attack_main[x-i+n-1] = false;
                attack_sub[x+i] = false;
            }  
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> queen(n,string(n,'.'));
        vis.resize(n);
        attack_main.resize(2*n-1);
        attack_sub.resize(2*n-1);
        dfs(queen,0,n);
        return a;
    }
};
// @lc code=end

