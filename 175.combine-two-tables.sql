# Write your MySQL query statement below
select p.FirstName, p.LastName, a.City, a.State from Person as p
    left join (select PersonId, City, State from Address) as a
    on p.PersonId = a.PersonId;
