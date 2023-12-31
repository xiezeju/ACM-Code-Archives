--
-- @lc app=leetcode.cn id=550 lang=mysql
--
-- [550] 游戏玩法分析 IV
--
-- https://leetcode.cn/problems/game-play-analysis-iv/description/
--
-- database
-- Medium (41.79%)
-- Likes:    170
-- Dislikes: 0
-- Total Accepted:    42.4K
-- Total Submissions: 101.7K
-- Testcase Example:  '{"headers":{"Activity":["player_id","device_id","event_date","games_played"]},"rows":{"Activity":[[1,2,"2016-03-01",5],[1,2,"2016-03-02",6],[2,3,"2017-06-25",1],[3,1,"2016-03-02",0],[3,4,"2018-07-03",5]]}}'
--
-- Table: Activity
-- 
-- 
-- +--------------+---------+
-- | Column Name  | Type    |
-- +--------------+---------+
-- | player_id    | int     |
-- | device_id    | int     |
-- | event_date   | date    |
-- | games_played | int     |
-- +--------------+---------+
-- （player_id，event_date）是此表的主键（具有唯一值的列的组合）。
-- 这张表显示了某些游戏的玩家的活动情况。
-- 每一行是一个玩家的记录，他在某一天使用某个设备注销之前登录并玩了很多游戏（可能是 0）。
-- 
-- 
-- 
-- 
-- 编写解决方案，报告在首次登录的第二天再次登录的玩家的
-- 比率，四舍五入到小数点后两位。换句话说，你需要计算从首次登录日期开始至少连续两天登录的玩家的数量，然后除以玩家总数。
-- 
-- 结果格式如下所示：
-- 
-- 
-- 
-- 示例 1：
-- 
-- 
-- 输入：
-- Activity table:
-- +-----------+-----------+------------+--------------+
-- | player_id | device_id | event_date | games_played |
-- +-----------+-----------+------------+--------------+
-- | 1         | 2         | 2016-03-01 | 5            |
-- | 1         | 2         | 2016-03-02 | 6            |
-- | 2         | 3         | 2017-06-25 | 1            |
-- | 3         | 1         | 2016-03-02 | 0            |
-- | 3         | 4         | 2018-07-03 | 5            |
-- +-----------+-----------+------------+--------------+
-- 输出：
-- +-----------+
-- | fraction  |
-- +-----------+
-- | 0.33      |
-- +-----------+
-- 解释：
-- 只有 ID 为 1 的玩家在第一天登录后才重新登录，所以答案是 1/3 = 0.33
-- 
-- 
--

-- @lc code=start
# Write your MySQL query statement below
SELECT ROUND(AVG(a2.event_date IS NOT NULL),2) AS fraction
FROM (
    SELECT player_id,MIN(event_date) as event_date
    FROM Activity
    GROUP BY player_id
) a1 LEFT JOIN Activity a2
ON a1.player_id = a2.player_id AND TIMESTAMPDIFF(day,a1.event_date,a2.event_date)=1

-- @lc code=end

