SELECT 
    CONCAT('/home/grep/src/', BOARD_ID, '/', FILE_ID, FILE_NAME, FILE_EXT) AS FILE_PATH
FROM 
    USED_GOODS_BOARD B
    JOIN
    USED_GOODS_FILE F
    USING(BOARD_ID)
WHERE 
    B.VIEWS IN (SELECT 
                    MAX(VIEWS)
                FROM 
                    USED_GOODS_BOARD)
ORDER BY
    FILE_ID DESC