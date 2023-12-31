/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 *
 * https://leetcode.cn/problems/word-search/description/
 *
 * algorithms
 * Medium (46.35%)
 * Likes:    1698
 * Dislikes: 0
 * Total Accepted:    459.8K
 * Total Submissions: 991.8K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false
 * 。
 * 
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
 * "ABCCED"
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
 * "SEE"
 * 输出：true
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
 * "ABCB"
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == board.length
 * n = board[i].length
 * 1 
 * 1 
 * board 和 word 仅由大小写英文字母组成
 * 
 * 
 * 
 * 
 * 进阶：你可以使用搜索剪枝的技术来优化解决方案，使其在 board 更大的情况下可以更快解决问题？
 * 
 */

// @lc code=start
class Solution {
public:

    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};

    bool dfs(int m,int n,vector<vector<char>>& board,string& word,vector<vector<bool>>& vis,int x,int y,string& s){
        
        if(s==word){
            return true;
        }

        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<0||ny<0||nx>=m||ny>=n||vis[nx][ny]) continue;
            if(s.size()+1>word.size()||board[nx][ny]!=word[s.size()]) continue;
            s.push_back(board[nx][ny]);
            vis[nx][ny] = true;
            if(dfs(m,n,board,word,vis,nx,ny,s)){
                return true;
            }
            s.pop_back();
            vis[nx][ny] = false;
        }
        
        return false;

    }

    bool exist(vector<vector<char>>& board, string word) {
        string s ="";
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    s.push_back(word[0]);
                    vis[i][j] = true;
                    if(dfs(m,n,board,word,vis,i,j,s)){
                        return true;
                    }
                    s.pop_back();
                    vis[i][j] = false;
                }
            }
        }
        return false;
    }
};
// @lc code=end

