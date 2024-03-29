-- 코드를 작성해주세요
SELECT
    FI.ID,
    FNI.FISH_NAME,
    FI.LENGTH
FROM
    FISH_INFO AS FI
    LEFT JOIN
    FISH_NAME_INFO AS FNI
    USING(FISH_TYPE)
WHERE
    (FISH_TYPE, LENGTH) IN (SELECT 
                                FISH_TYPE,
                                MAX(LENGTH) AS LENGTH
                            FROM 
                                FISH_INFO
                            WHERE
                                LENGTH is not null
                            GROUP BY
                                FISH_TYPE)
ORDER BY 
    ID ASC

    

    