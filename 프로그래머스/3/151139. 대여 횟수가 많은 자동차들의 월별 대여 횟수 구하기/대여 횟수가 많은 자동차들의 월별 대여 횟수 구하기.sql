-- 코드를 입력하세요
WITH RENTAL_HISTORY_8_10 AS (
    SELECT
        HISTORY_ID,
        MONTH(START_DATE) AS MONTH,
        CAR_ID
    FROM
        CAR_RENTAL_COMPANY_RENTAL_HISTORY
    WHERE
        DATE_FORMAT(START_DATE,'%Y-%m') >= '2022-08' AND
        DATE_FORMAT(START_DATE,'%Y-%m') <= '2022-10' 
)


SELECT 
    MONTH,
    CAR_ID,
    COUNT(HISTORY_ID) AS RECORDS
FROM 
    RENTAL_HISTORY_8_10
WHERE 
    CAR_ID IN (SELECT
                    CAR_ID
                FROM 
                    RENTAL_HISTORY_8_10
                GROUP BY
                    CAR_ID
                HAVING  
                    COUNT(HISTORY_ID) >= 5)
GROUP BY
    CAR_ID, MONTH    
ORDER BY
    MONTH ASC,
    CAR_ID DESC