# Write your MySQL query statement below
-- select activity_date as day, count as active_users from activity where user_id has activity_type = 'open_session', 'end_session', 'scroll_down', 'send_message' from 30 days till 2019-07-27 

select activity_date as day, count(distinct user_id) as active_users from Activity where activity_date between '2019-06-28' AND '2019-07-27' group by activity_date;