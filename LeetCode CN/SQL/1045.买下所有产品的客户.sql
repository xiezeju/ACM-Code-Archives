--
-- @lc app=leetcode.cn id=1045 lang=mysql
--
-- [1045] 买下所有产品的客户
--
-- https://leetcode.cn/problems/customers-who-bought-all-products/description/
--
-- database
-- Medium (60.04%)
-- Likes:    92
-- Dislikes: 0
-- Total Accepted:    30.6K
-- Total Submissions: 51.3K
-- Testcase Example:  '{"headers":{"Customer":["customer_id","product_key"],"Product":["product_key"]},"rows":{"Customer":[[1,5],[2,6],[3,5],[3,6],[1,6]],"Product":[[5],[6]]}}'
--
-- Customer 表：
-- 
-- 
-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | customer_id | int     |
-- | product_key | int     |
-- +-------------+---------+
-- 该表可能包含重复的行。
-- customer_id 不为 NULL。
-- product_key 是 Product 表的外键(reference 列)。
-- 
-- 
-- Product 表：
-- 
-- 
-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | product_key | int     |
-- +-------------+---------+
-- product_key 是这张表的主键（具有唯一值的列）。
-- 
-- 
-- 
-- 
-- 编写解决方案，报告 Customer 表中购买了 Product 表中所有产品的客户的 id。
-- 
-- 返回结果表 无顺序要求 。
-- 
-- 返回结果格式如下所示。
-- 
-- 
-- 
-- 示例 1：
-- 
-- 
-- 输入：
-- Customer 表：
-- +-------------+-------------+
-- | customer_id | product_key |
-- +-------------+-------------+
-- | 1           | 5           |
-- | 2           | 6           |
-- | 3           | 5           |
-- | 3           | 6           |
-- | 1           | 6           |
-- +-------------+-------------+
-- Product 表：
-- +-------------+
-- | product_key |
-- +-------------+
-- | 5           |
-- | 6           |
-- +-------------+
-- 输出：
-- +-------------+
-- | customer_id |
-- +-------------+
-- | 1           |
-- | 3           |
-- +-------------+
-- 解释：
-- 购买了所有产品（5 和 6）的客户的 id 是 1 和 3 。
-- 
-- 
--

-- @lc code=start
# Write your MySQL query statement below
SELECT customer_id
FROM (
  SELECT customer_id, product_key
  FROM Customer
  GROUP BY customer_id,product_key
) m
GROUP BY customer_id
HAVING COUNT(product_key) = (SELECT COUNT(*) FROM Product)
-- @lc code=end

