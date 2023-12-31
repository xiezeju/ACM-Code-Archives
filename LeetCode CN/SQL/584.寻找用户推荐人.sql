--
-- @lc app=leetcode.cn id=584 lang=mysql
--
-- [584] 寻找用户推荐人
--
-- https://leetcode.cn/problems/find-customer-referee/description/
--
-- database
-- Easy (65.66%)
-- Likes:    234
-- Dislikes: 0
-- Total Accepted:    177.3K
-- Total Submissions: 270K
-- Testcase Example:  '{"headers":{"Customer":["id","name","referee_id"]},"rows":{"Customer":[[1,"Will",null],[2,"Jane",null],[3,"Alex",2],[4,"Bill",null],[5,"Zack",1],[6,"Mark",2]]}}'
--
-- 表: Customer
-- 
-- 
-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | id          | int     |
-- | name        | varchar |
-- | referee_id  | int     |
-- +-------------+---------+
-- 在 SQL 中，id 是该表的主键列。
-- 该表的每一行表示一个客户的 id、姓名以及推荐他们的客户的 id。
-- 
-- 找出那些 没有被 id = 2 的客户 推荐 的客户的姓名。
-- 
-- 以 任意顺序 返回结果表。
-- 
-- 结果格式如下所示。
-- 
-- 
-- 
-- 示例 1：
-- 
-- 
-- 输入： 
-- Customer 表:
-- +----+------+------------+
-- | id | name | referee_id |
-- +----+------+------------+
-- | 1  | Will | null       |
-- | 2  | Jane | null       |
-- | 3  | Alex | 2          |
-- | 4  | Bill | null       |
-- | 5  | Zack | 1          |
-- | 6  | Mark | 2          |
-- +----+------+------------+
-- 输出：
-- +------+
-- | name |
-- +------+
-- | Will |
-- | Jane |
-- | Bill |
-- | Zack |
-- +------+
-- 
--

-- @lc code=start
# Write your MySQL query statement below
SELECT name
FROM Customer
WHERE referee_id IS NULL OR referee_id <> 2

-- @lc code=end

