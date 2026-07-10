SELECT 
    user_id, 
    COUNT(tokens) AS prompt_count, 
    ROUND(AVG(tokens), 2) AS avg_tokens
FROM prompts
GROUP BY user_id
HAVING COUNT(tokens) > 2 
   AND MAX(tokens) > AVG(tokens)
ORDER BY avg_tokens DESC, user_id ASC;