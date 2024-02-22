-- 코드를 입력하세요
SELECT 
    MEMBER_PROFILE.MEMBER_NAME,
    TR.REVIEW_TEXT,
    date_format(TR.REVIEW_DATE,'%Y-%m-%d') as REVIEW_DATE
FROM (
        SELECT *
        FROM REST_REVIEW
        WHERE MEMBER_ID IN (
                            SELECT 
                                MEMBER_ID
                            FROM REST_REVIEW 
                            GROUP BY MEMBER_ID
                            HAVING COUNT(REVIEW_ID) >= (SELECT COUNT(REVIEW_ID) as MAXCNT
                                                FROM REST_REVIEW
                                                GROUP BY MEMBER_ID
                                                ORDER BY MAXCNT DESC 
                                                LIMIT 1
                                              )
                            )
    ) as TR 
    JOIN
    MEMBER_PROFILE
    ON 
    TR.MEMBER_ID = MEMBER_PROFILE.MEMBER_ID
ORDER BY
    REVIEW_DATE ASC, 
    REVIEW_TEXT ASC
      