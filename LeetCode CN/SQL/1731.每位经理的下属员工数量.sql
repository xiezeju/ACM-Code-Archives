--
-- @lc app=leetcode.cn id=1731 lang=mysql
--
-- [1731] 每位经理的下属员工数量
--
-- https://leetcode.cn/problems/the-number-of-employees-which-report-to-each-employee/description/
--
-- database
-- Easy (46.72%)
-- Likes:    43
-- Dislikes: 0
-- Total Accepted:    16.9K
-- Total Submissions: 36.3K
-- Testcase Example:  '{"headers":{"Employees":["employee_id","name","reports_to","age"]},"rows":{"Employees":[[9,"Hercy",null,43],[6,"Alice",9,41],[4,"Bob",9,36],[2,"Winston",null,37]]}}'
--
-- Table: Employees
-- 
-- +-------------+----------+
-- | Column Name | Type     |
-- +-------------+----------+
-- | employee_id | int      |
-- | name        | varchar  |
-- | reports_to  | int      |
-- | age         | int      |
-- +-------------+----------+
-- employee_id 是这个表的主键.
-- 该表包含员工以及需要听取他们汇报的上级经理的ID的信息。 有些员工不需要向任何人汇报（reports_to 为空）。
-- 
-- 
-- 
-- 
-- 对于此问题，我们将至少有一个其他员工需要向他汇报的员工，视为一个经理。
-- 
-- 编写SQL查询需要听取汇报的所有经理的ID、名称、直接向该经理汇报的员工人数，以及这些员工的平均年龄，其中该平均年龄需要四舍五入到最接近的整数。
-- 
-- 返回的结果集需要按照 employee_id 进行排序。
-- 
-- 查询结果的格式如下：
-- 
-- 
-- 
-- Employees table:
-- +-------------+---------+------------+-----+
-- | employee_id | name    | reports_to | age |
-- +-------------+---------+------------+-----+
-- | 9           | Hercy   | null       | 43  |
-- | 6           | Alice   | 9          | 41  |
-- | 4           | Bob     | 9          | 36  |
-- | 2           | Winston | null       | 37  |
-- +-------------+---------+------------+-----+
-- 
-- Result table:
-- +-------------+-------+---------------+-------------+
-- | employee_id | name  | reports_count | average_age |
-- +-------------+-------+---------------+-------------+
-- | 9           | Hercy | 2             | 39          |
-- +-------------+-------+---------------+-------------+
-- Hercy 有两个需要向他汇报的员工, 他们是 Alice and Bob. 他们的平均年龄是 (41+36)/2 = 38.5, 四舍五入的结果是
-- 39.
-- 
-- 
--

-- @lc code=start
# Write your MySQL query statement below
SELECT a.employee_id,a.name,COUNT(*) AS reports_count,ROUND(AVG(b.age)) AS average_age
FROM Employees a
LEFT JOIN Employees b
ON a.employee_id = b.reports_to
WHERE b.employee_id IS NOT NULL
GROUP BY a.employee_id
ORDER BY a.employee_id
-- @lc code=end

