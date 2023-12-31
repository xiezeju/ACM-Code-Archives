/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 *
 * https://leetcode.cn/problems/word-break/description/
 *
 * algorithms
 * Medium (54.48%)
 * Likes:    2317
 * Dislikes: 0
 * Total Accepted:    494.5K
 * Total Submissions: 906.9K
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * 给你一个字符串 s 和一个字符串列表 wordDict
 * 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。
 *
 * 注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入: s = "leetcode", wordDict = ["leet", "code"]
 * 输出: true
 * 解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。
 *
 *
 * 示例 2：
 *
 *
 * 输入: s = "applepenapple", wordDict = ["apple", "pen"]
 * 输出: true
 * 解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
 * 注意，你可以重复使用字典中的单词。
 *
 *
 * 示例 3：
 *
 *
 * 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * 输出: false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 300
 * 1 <= wordDict.length <= 1000
 * 1 <= wordDict[i].length <= 20
 * s 和 wordDict[i] 仅由小写英文字母组成
 * wordDict 中的所有字符串 互不相同
 *
 *
 */

// @lc code=start
class Solution {
    public:
        bool wordBreak(string s, vector<string>& wordDict) {
            int n = s.size();

            // dp[i]表示当前长度能否匹配
            vector<bool> dp(n + 1);
            dp[0] = 1;
            for (int lenght = 1; lenght <= n; lenght++) {
                for (int i = 0; i < wordDict.size(); i++) {
                    string ss = wordDict[i];
                    if (ss.size() > lenght) {
                        continue;
                    }
                    // 切割字符串并尝试匹配
                    if (ss == s.substr(lenght - ss.size(), ss.size())) {
                        dp[lenght] = dp[lenght - ss.size()];
                    }
                    // 当前长度已经匹配，直接进行下一个长度的匹配
                    if (dp[lenght] == true) {
                        break;
                    }
                }
            }
            return dp[n];
        }
};

// @lc code=end
