--
-- @lc app=leetcode.cn id=1193 lang=mysql
--
-- [1193] 每月交易 I
--
-- https://leetcode.cn/problems/monthly-transactions-i/description/
--
-- database
-- Medium (61.14%)
-- Likes:    82
-- Dislikes: 0
-- Total Accepted:    26.2K
-- Total Submissions: 42.9K
-- Testcase Example:  '{"headers":{"Transactions":["id","country","state","amount","trans_date"]},"rows":{"Transactions":[[121,"US","approved",1000,"2018-12-18"],[122,"US","declined",2000,"2018-12-19"],[123,"US","approved",2000,"2019-01-01"],[124,"DE","approved",2000,"2019-01-07"]]}}'
--
-- 表：Transactions
-- 
-- 
-- +---------------+---------+
-- | Column Name   | Type    |
-- +---------------+---------+
-- | id            | int     |
-- | country       | varchar |
-- | state         | enum    |
-- | amount        | int     |
-- | trans_date    | date    |
-- +---------------+---------+
-- id 是这个表的主键。
-- 该表包含有关传入事务的信息。
-- state 列类型为 ["approved", "declined"] 之一。
-- 
-- 
-- 
-- 
-- 编写一个 sql 查询来查找每个月和每个国家/地区的事务数及其总金额、已批准的事务数及其总金额。
-- 
-- 以 任意顺序 返回结果表。
-- 
-- 查询结果格式如下所示。
-- 
-- 
-- 
-- 示例 1:
-- 
-- 
-- 输入：
-- Transactions table:
-- +------+---------+----------+--------+------------+
-- | id   | country | state    | amount | trans_date |
-- +------+---------+----------+--------+------------+
-- | 121  | US      | approved | 1000   | 2018-12-18 |
-- | 122  | US      | declined | 2000   | 2018-12-19 |
-- | 123  | US      | approved | 2000   | 2019-01-01 |
-- | 124  | DE      | approved | 2000   | 2019-01-07 |
-- +------+---------+----------+--------+------------+
-- 输出：
-- 
-- +----------+---------+-------------+----------------+--------------------+-----------------------+
-- | month    | country | trans_count | approved_count | trans_total_amount |
-- approved_total_amount |
-- 
-- +----------+---------+-------------+----------------+--------------------+-----------------------+
-- | 2018-12  | US      | 2           | 1              | 3000               |
-- 1000                  |
-- | 2019-01  | US      | 1           | 1              | 2000               |
-- 2000                  |
-- | 2019-01  | DE      | 1           | 1              | 2000               |
-- 2000                  |
-- 
-- +----------+---------+-------------+----------------+--------------------+-----------------------+
-- 
--

-- @lc code=start
# Write your MySQL query statement below
SELECT DATE_FORMAT(trans_date,'%Y-%m')AS month,
          country,
          COUNT(id) AS trans_count,
          COUNT(CASE WHEN state='approved' THEN id END) AS approved_count,
          SUM(amount) AS trans_total_amount,
          SUM(CASE WHEN state='approved' THEN amount Else 0 END) AS approved_total_amount
FROM Transactions
GROUP BY month,country
-- @lc code=end

