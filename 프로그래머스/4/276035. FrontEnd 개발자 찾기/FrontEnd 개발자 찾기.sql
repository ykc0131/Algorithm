-- 코드를 작성해주세요

SELECT
    ID,
    EMAIL,
    FIRST_NAME,
    LAST_NAME
FROM
    DEVELOPERS
WHERE
    SKILL_CODE & (SELECT
                        SUM(CODE) AS TOTAL_CODE
                    FROM
                        SKILLCODES
                    WHERE 
                        CATEGORY = 'Front End'  )
ORDER BY
    ID ASC