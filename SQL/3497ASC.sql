select 
p.user_id, 
t.trial_avg_duration, 
p.paid_avg_duration
from 
(SELECT user_id,
ROUND(AVG(activity_duration), 2) AS trial_avg_duration
FROM UserActivity
WHERE activity_type = "free_trial"
GROUP BY user_id) t
join 
(SELECT user_id,
ROUND(AVG(activity_duration), 2) AS paid_avg_duration
FROM UserActivity
WHERE activity_type = "paid"
GROUP BY user_id) p
on t.user_id = p.user_id
group by p.user_id;
