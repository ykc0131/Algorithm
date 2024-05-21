-- 코드를 작성해주세요
WITH RECURSIVE ECOLI_G(ID, PARENT_ID) AS (
    SELECT 
        ID,
        PARENT_ID
    FROM    
        ECOLI_DATA
    UNION ALL
    SELECT 
        E.ID,
        EG.PARENT_ID
    FROM 
        ECOLI_DATA E 
            INNER JOIN 
                ECOLI_G EG ON E.PARENT_ID = EG.ID
)

SELECT  
    ID
FROM ECOLI_G 
GROUP BY ID
HAVING COUNT(ID)=3
ORDER BY ID
