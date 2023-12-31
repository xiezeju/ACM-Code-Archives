/*
 * @lc app=leetcode.cn id=901 lang=cpp
 *
 * [901] 股票价格跨度
 *
 * https://leetcode.cn/problems/online-stock-span/description/
 *
 * algorithms
 * Medium (62.16%)
 * Likes:    426
 * Dislikes: 0
 * Total Accepted:    82.6K
 * Total Submissions: 128.6K
 * Testcase Example:  '["StockSpanner","next","next","next","next","next","next","next"]\n' +
  '[[],[100],[80],[60],[70],[60],[75],[85]]'
 *
 * 设计一个算法收集某些股票的每日报价，并返回该股票当日价格的 跨度 。
 * 
 * 当日股票价格的 跨度 被定义为股票价格小于或等于今天价格的最大连续日数（从今天开始往回数，包括今天）。
 * 
 * 
 * 
 * 例如，如果未来 7 天股票的价格是 [100,80,60,70,60,75,85]，那么股票跨度将是 [1,1,1,2,1,4,6] 。
 * 
 * 
 * 
 * 实现 StockSpanner 类：
 * 
 * 
 * StockSpanner() 初始化类对象。
 * int next(int price) 给出今天的股价 price ，返回该股票当日价格的 跨度 。
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：
 * ["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
 * [[], [100], [80], [60], [70], [60], [75], [85]]
 * 输出：
 * [null, 1, 1, 1, 2, 1, 4, 6]
 * 
 * 解释：
 * StockSpanner stockSpanner = new StockSpanner();
 * stockSpanner.next(100); // 返回 1
 * stockSpanner.next(80);  // 返回 1
 * stockSpanner.next(60);  // 返回 1
 * stockSpanner.next(70);  // 返回 2
 * stockSpanner.next(60);  // 返回 1
 * stockSpanner.next(75);  // 返回 4 ，因为截至今天的最后 4 个股价 (包括今天的股价 75) 都小于或等于今天的股价。
 * stockSpanner.next(85);  // 返回 6
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= price <= 10^5
 * 最多调用 next 方法 10^4 次
 * 
 * 
 */

// @lc code=start
class StockSpanner {
public:
    StockSpanner() {
        this->day = 0;
    }
    
    int next(int price) {
        a.push_back(price);
        int x;
        while(!s.empty()&&a[s.top()]<=price){
            s.pop();
        }
        x = s.empty()?day+1:day-s.top();
        s.push(day++);

        return x;
    }
private:
    stack<int> s;
    vector<int> a;
    int day;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end

