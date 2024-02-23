-- 코드를 입력하세요
SELECT 
    AUTHOR_ID, 
    AUTHOR_NAME,
    CATEGORY,
    SUM(SALES)
FROM
    (
        SELECT 
            BOOK.*,
            SALES * PRICE  as SALES
        FROM 
            BOOK_SALES
            JOIN
            BOOK
            USING(BOOK_ID)
        WHERE date_format(SALES_DATE,'%Y-%m') ='2022-01'
    ) AS BS
    JOIN 
    AUTHOR
    USING(AUTHOR_ID)
GROUP BY AUTHOR_ID,CATEGORY
ORDER BY AUTHOR_ID ASC, CATEGORY DESC
