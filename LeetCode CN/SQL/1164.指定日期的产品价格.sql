--
-- @lc app=leetcode.cn id=1164 lang=mysql
--
-- [1164] 指定日期的产品价格
--
-- https://leetcode.cn/problems/product-price-at-a-given-date/description/
--
-- database
-- Medium (56.54%)
-- Likes:    138
-- Dislikes: 0
-- Total Accepted:    22.7K
-- Total Submissions: 40.3K
-- Testcase Example:  '{"headers":{"Products":["product_id","new_price","change_date"]},"rows":{"Products":[[1,20,"2019-08-14"],[2,50,"2019-08-14"],[1,30,"2019-08-15"],[1,35,"2019-08-16"],[2,65,"2019-08-17"],[3,20,"2019-08-18"]]}}'
--
-- 产品数据表: Products
-- 
-- 
-- +---------------+---------+
-- | Column Name   | Type    |
-- +---------------+---------+
-- | product_id    | int     |
-- | new_price     | int     |
-- | change_date   | date    |
-- +---------------+---------+
-- (product_id, change_date) 是此表的主键（具有唯一值的列组合）。
-- 这张表的每一行分别记录了 某产品 在某个日期 更改后 的新价格。
-- 
-- 
-- 
-- 编写一个解决方案，找出在 2019-08-16 时全部产品的价格，假设所有产品在修改前的价格都是 10 。
-- 
-- 以 任意顺序 返回结果表。
-- 
-- 结果格式如下例所示。
-- 
-- 
-- 
-- 示例 1:
-- 
-- 
-- 输入：
-- Products 表:
-- +------------+-----------+-------------+
-- | product_id | new_price | change_date |
-- +------------+-----------+-------------+
-- | 1          | 20        | 2019-08-14  |
-- | 2          | 50        | 2019-08-14  |
-- | 1          | 30        | 2019-08-15  |
-- | 1          | 35        | 2019-08-16  |
-- | 2          | 65        | 2019-08-17  |
-- | 3          | 20        | 2019-08-18  |
-- +------------+-----------+-------------+
-- 输出：
-- +------------+-------+
-- | product_id | price |
-- +------------+-------+
-- | 2          | 50    |
-- | 1          | 35    |
-- | 3          | 10    |
-- +------------+-------+
-- 
--

-- @lc code=start
# Write your MySQL query statement below
SELECT p1.product_id, IFNULL(p2.new_price,10) as price 
FROM (
    SELECT DISTINCT product_id
    FROM Products
) p1
LEFT JOIN(
    SELECT product_id, new_price 
    FROM Products 
    WHERE (product_id,change_date) in (
        SELECT product_id, MAX(change_date)
        FROM Products
        WHERE TIMESTAMPDIFF(day,change_date,'2019-08-16')>=0
        GROUP BY product_id
    )
) p2
ON p1.product_id = p2.product_id
-- @lc code=end

