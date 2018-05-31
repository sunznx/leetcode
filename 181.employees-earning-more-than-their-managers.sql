# Write your MySQL query statement below
select t1.Name as Employee from Employee as t2 left join
    (select ManagerId, Salary, Name from Employee where ManagerId is not null) as t1
    on t1.ManagerId = t2.Id where t2.Salary < t1.Salary;
