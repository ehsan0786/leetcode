# Write your MySQL query statement below

-- select customer_id, min(order_date) as first_order_date
-- from Delivery
-- group by customer_id

-- | customer_id | first_order_date |
-- | ----------- | ---------------- |
-- | 1           | 2019-08-01       |
-- | 2           | 2019-08-02       |
-- | 3           | 2019-08-21       |
-- | 4           | 2019-08-09       |


select
    round(sum(case when order_date = customer_pref_delivery_date then 1 else 0 end)*100/count(distinct customer_id),2) as immediate_percentage 
from Delivery 
where(customer_id,order_date) in( -- customer is the order with the earliest order date 
                                    select customer_id, min(order_date) as first_order_date
                                    from Delivery
                                    group by customer_id
                                )   