WITH split_to_array AS (
SELECT 
    product_id, 
    product_name, 
    description, 
    value AS split_char
FROM products
CROSS APPLY STRING_SPLIT(description, ' ')
)
SELECT product_id, product_name, description
FROM split_to_array
WHERE len(split_char) = 11
AND substring(split_char,1,2) COLLATE Latin1_General_CS_AS = 'SN'
AND substring(split_char,7,1) = '-'
AND substring(split_char,3,1) BETWEEN '0' AND '9'
AND substring(split_char,4,1) BETWEEN '0' AND '9'
AND substring(split_char,5,1) BETWEEN '0' AND '9'
AND substring(split_char,6,1) BETWEEN '0' AND '9'
AND substring(split_char,8,1) BETWEEN '0' AND '9'
AND substring(split_char,9,1) BETWEEN '0' AND '9'
AND substring(split_char,10,1) BETWEEN '0' AND '9'
AND substring(split_char,11,1) BETWEEN '0' AND '9'
ORDER BY product_id;