WITH MAXC AS ( 
    SELECT
        YEAR(DIFFERENTIATION_DATE) AS YEAR,
        MAX(SIZE_OF_COLONY) AS MS
    FROM 
        ECOLI_DATA
    GROUP BY
        YEAR(DIFFERENTIATION_DATE)
 )

SELECT 
    YEAR,
    MS - SIZE_OF_COLONY AS YEAR_DEV,
    ID
FROM 
    ECOLI_DATA ED
    JOIN
    MAXC
    ON YEAR(ED.DIFFERENTIATION_DATE) = MAXC.YEAR
ORDER BY
    YEAR ASC, YEAR_DEV ASC