WITH RECURSIVE ECOLI_R AS (
    SELECT 
        ID,
        PARENT_ID
    FROM  
        ECOLI_DATA
    UNION ALL
    SELECT 
        E.ID,
        R.PARENT_ID
    FROM
        ECOLI_DATA E
        INNER JOIN 
        ECOLI_R R
        ON E.PARENT_ID = R.ID
), ECOLI_GENERATION AS (
    SELECT
        ID,
        COUNT(ID) AS GENERATION
    FROM ECOLI_R
    GROUP BY ID
    ORDER BY ID
), ECOLI_HAS_CHILD AS (
    SELECT 
        DISTINCT E.PARENT_ID AS ID
    FROM ECOLI_DATA E
    WHERE PARENT_ID IS NOT NULL
)

SELECT 
    COUNT(ID) AS COUNT, 
    EG.GENERATION
FROM
    ECOLI_GENERATION EG 
WHERE 
    ID NOT IN (SELECT * FROM ECOLI_HAS_CHILD)
GROUP BY GENERATION
ORDER BY GENERATION