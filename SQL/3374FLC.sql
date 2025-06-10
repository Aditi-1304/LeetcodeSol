-- Write your PostgreSQL query statement below
SELECT
  content_id,
  content_text as original_text,
  initcap(lower(content_text))  AS converted_text
FROM user_content
