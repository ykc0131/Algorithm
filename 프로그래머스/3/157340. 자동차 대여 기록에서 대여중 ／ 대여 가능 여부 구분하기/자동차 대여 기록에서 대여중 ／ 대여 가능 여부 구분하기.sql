WITH DATE_S AS (
    SELECT 
        HISTORY_ID,
        CAR_ID,
        DATE_FORMAT(START_DATE, "%y-%m-%d"),
        DATE_FORMAT(END_DATE, "%y-%m-%d"),
        CASE
            WHEN 
                DATE_FORMAT(END_DATE, "%y-%m-%d") < "22-10-16" THEN 0
            WHEN
                DATE_FORMAT(START_DATE, "%y-%m-%d") > "22-10-16" THEN 0
            ELSE
                1
        END AS AVA
    FROM
        CAR_RENTAL_COMPANY_RENTAL_HISTORY
    ORDER BY CAR_ID
)

# SELECT * FROM DATE_S
SELECT 
    CAR_ID,
    CASE
        WHEN SUM(AVA) > 0 THEN "대여중"
        ELSE
            "대여 가능"
    END AS AVAILABILITY
FROM 
    DATE_S
GROUP BY CAR_ID
ORDER BY CAR_ID DESC