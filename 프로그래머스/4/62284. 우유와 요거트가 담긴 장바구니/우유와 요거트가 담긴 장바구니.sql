-- 코드를 입력하세요
SELECT 
    CART_ID
FROM (SELECT
            CART_ID,
            NAME,
            PRICE
        FROM
            CART_PRODUCTS 
        WHERE
            NAME='Milk' OR
            NAME='Yogurt'
        GROUP BY
            CART_ID, NAME
        ) AS C
GROUP BY
    CART_ID
HAVING 
    COUNT(NAME) = 2
ORDER BY
    CART_ID