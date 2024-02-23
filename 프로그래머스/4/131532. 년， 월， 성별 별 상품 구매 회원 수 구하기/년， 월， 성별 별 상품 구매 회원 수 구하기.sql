# -- 코드를 입력하세요
# SELECT YEAR, MONTH, GENDER, COUNT(USER_INFO.USER_ID) AS USERS
# FROM 
#     USER_INFO
#     JOIN
#     ( 
#         SELECT 
#                 ONLINE_SALE_ID,
#                 USER_ID,
#                 date_format(SALES_DATE,'%Y') AS YEAR,
#                 date_format(SALES_DATE,'%m') AS MONTH
#         FROM ONLINE_SALE
#     ) AS OS
#     ON
#     USER_INFO.USER_ID = OS.USER_ID
# WHERE gender is not null
# GROUP BY YEAR, MONTH, GENDER
# ORDER BY YEAR ASC, MONTH ASC, GENDER ASC

-- 코드를 입력하세요
SELECT YEAR, MONTH, GENDER, COUNT(USER_ID) AS USERS
FROM 
    (
        SELECT DISTINCT OS.USER_ID, YEAR, MONTH, GENDER
        FROM 
            USER_INFO
            JOIN
            ( 
                SELECT 
                        ONLINE_SALE_ID,
                        USER_ID,
                        date_format(SALES_DATE,'%Y') AS YEAR,
                        date_format(SALES_DATE,'%m') AS MONTH
                FROM ONLINE_SALE
            ) AS OS
            ON
            USER_INFO.USER_ID = OS.USER_ID
        WHERE gender is not null
    ) AS USOS
GROUP BY YEAR, MONTH, GENDER
ORDER BY YEAR ASC, MONTH ASC, GENDER ASC

