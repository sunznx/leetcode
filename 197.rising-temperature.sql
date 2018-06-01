# Write your MySQL query statement below
select t2.id as Id from Weather as t1 left join
    (select id, RecordDate - INTERVAL 1 day as TmpRecordDate, Temperature from Weather) as t2
    on t1.RecordDate = t2.TmpRecordDate
where t2.id is not null and t1.Temperature < t2.Temperature;
